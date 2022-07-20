/**
 * @file construct.h
 * @author czy (suoni1919@gmail.com)
 * @date 2022-07-15
 * 
 * @copyright Copyright (Chan) 2022
 * 
 */

#pragma

// #include
#include <new>
#include "traits.h"

/**
 * 定点构造
 * Placement New
 */

    /**
     * 
     * @tparam T1 
     * @param ptr 构造地址
     * 无参构造
     */
template <typename T1>
inline void construct(T1* ptr) {
    new((void*)ptr) T1();
}

    /**
     * 
     * @tparam T1 
     * @tparam T2 
     * @param ptr 构造地址
     * @param value 赋值构造
     */
template <typename T1, typename T2>
inline void construct(T1* ptr, const T2& value) {
    new((void*)ptr) T1(value); //T1::T1(value)
}

// @TODO 
//     /** 
//      * 移动构造 (使用std完美转发)
//      * @tparam T 
//      * @tparam Args 
//      * @param ptr 
//      * @param args 
//      */
// template <typename T, typename... Args>
// void construct(T* ptr, Args&&... args) {
//     new((void*)ptr) T(std::forward<Args>(args)...);
// }

    /**
     * 调用析构函数
     * @tparam T 
     * @param ptr 
     */
template <typename T>
inline void destroy(T* ptr) {
    ptr->~T();
}

/**
 * 连续析构
 * 
 * 这里对连续的迭代器通过 
 * __destory调用 __destory_aux 进行分流
 * 平凡的对象不需要调用析构函数，这里do nothing
 * 直接交给delete 释放内存即可
 * 
 * 非平凡的对象需要先析构再释放，这里逐个调用析构函数
 */
template <typename ForwardIterator>
inline void destory(ForwardIterator first, ForwardIterator last) {
    __destory(first, last, value_type(first));
}

template <typename ForwardIterator, typename T>
inline void __destory(ForwardIterator first, ForwardIterator last, T*) {
    typedef typename __type_traits<T>::has_trivial_destructor trivial_destructor;
    __destory_aux(first, last, trivial_destructor());
}

template <typename ForwardIterator>
inline void __destory_aux(ForwardIterator first, ForwardIterator last, false_type) {
    for (; first < last; ++first) destory(&(*first));
}

template <typename ForwardIterator>
inline void __destory_aux(ForwardIterator first, ForwardIterator last, true_type) {}
