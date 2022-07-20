/**
 * @file traits.h
 * @author czy (suoni1919@gmail.com)
 * @date 2022-07-20
 * 
 * @copyright Copyright (Chan) 2022
 * 
 */

#pragma once
#include "iterator.h"


/**
 * 迭代器萃取器
 * 对[iterator]的
 * 类型进行提取
 */
template <typename Iterator>
struct iterator_traits {
    typedef typename Iterator::iterator_category    iterator_category;
    typedef typename Iterator::value_type           value_type;
    typedef typename Iterator::difference_type      difference_type;
    typedef typename Iterator::pointer              pointer;
    typedef typename Iterator::reference            reference;
};

    /**
     * 对基本指针类型的特化版本
     */
template <typename T>
struct iterator_traits<T*> {
    typedef random_access_iterator_tag  iterator_category;
    typedef T                           value_type;
    typedef ptrdiff_t                   difference_type;
    typedef T*                          pointer;
    typedef T&                          reference;   
};

    /**
     * 对const 指针的特化版本
     */
template <typename T>
struct iterator_traits<const T*> {
    typedef random_access_iterator_tag  iterator_category;
    typedef T                           value_type;
    typedef ptrdiff_t                   difference_type;
    typedef const T*                    pointer;
    typedef const T&                    reference;  
};

    /**
     * 对萃取器功能的实现：
     * 提取[迭代器类型]
     * 提取[值类型]
     * 提取[指针距]
     */
template <typename Iterator>
inline typename iterator_traits<Iterator>::iterator_category
    iterator_category(const Iterator& it) {
        typedef typename iterator_traits<Iterator>::iterator_category category;
        return category();
    }

template <typename Iterator>
inline typename iterator_traits<Iterator>::value_type*
    value_type(const Iterator& it) {
        return static_cast<typename iterator_traits<Iterator>::value_type*>(nullptr);
    }

template <typename Iterator>
inline typename iterator_traits<Iterator>::difference_type*
    difference_type(const Iterator& it) {
        return static_cast<typename iterator_traits<Iterator>::diference_type*>(nullptr);
    }

/**
 * 编译期类型推导标志
 */

struct true_type {};
struct false_type {};

/**
 * 类型萃取器
 * 用来提取某些类型的特殊性质
 * 
 * POD: 普通类型，没有构造和析构函数，兼容C的内存布局
 */

    /**
     * 泛化版本设置为保守值
     * @tparam type 
     */
template <typename type>
struct type_traits {
    typedef false_type has_trivial_default_constructor;
    typedef false_type has_trivial_copy_constructor;
    typedef false_type has_trivial_assignment_operator;
    typedef false_type has_trivial_destructor;
    typedef false_type is_POD_type;
};

    /**
     * 对基础类型版本进行特化，拥有全部可优化的特性
     */
template <>
struct type_traits<bool> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};

template <>
struct type_traits<char> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};

template <>
struct type_traits<unsigned char> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};

template <>
struct type_traits<short> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};

template <>
struct type_traits<unsigned short> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};

template <>
struct type_traits<int> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};

template <>
struct type_traits<unsigned int> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};

template <>
struct type_traits<long> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};

template <>
struct type_traits<unsigned long> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};

template <>
struct type_traits<long long> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};

template <>
struct type_traits<unsigned long long> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};

template <>
struct type_traits<float> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};

template <>
struct type_traits<double> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};

template <>
struct type_traits<long double> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};

    /**
     * 对基本指针进行偏特化
     */
template <typename T>
struct type_traits<T*> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};

template <typename T>
struct type_traits<const T*> {
    typedef true_type has_trivial_default_constructor;
    typedef true_type has_trivial_copy_constructor;
    typedef true_type has_trivial_assignment_operator;
    typedef true_type has_trivial_destructor;
    typedef true_type is_POD_type;
};