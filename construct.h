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
     * @param value 构造T1所需要的参数
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
     * 销毁函数
     * @tparam T 
     * @param ptr 
     */
template <typename T>
inline void destroy(T* ptr) {
    ptr->~T();
}

// @ TODO
// 对多种迭代器的销毁