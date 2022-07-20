/**
 * @file iterator.h
 * @author czy (suoni1919@gmail.com)
 * @date 2022-07-20
 * 
 * @copyright Copyright (Chan) 2022
 * 
 */

#pragma once
#include <cstddef>
/**
 * 五种迭代器的类型：
 * ---------
 * 输入迭代器
 * 输出迭代器
 * 前向迭代器
 * 双向迭代器
 * 任意迭代器
 */
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag: public input_iterator_tag {};
struct bidirectional_iterator_tag: public forward_iterator_tag {};
struct random_access_iterator_tag: public bidirectional_iterator_tag {};

/**
 * 将
 * [迭代器类型]、
 * [值类型]、
 * [指针距]、
 * [指针类型]、
 * [引用类型]
 * 和各种迭代器自身建立联系
 */
template <typename T, typename Distance>
struct input_iterator {
    typedef input_iterator_tag  iterator_category;
    typedef T                   value_type;
    typedef Distance            difference_type;
    typedef T*                  pointer;
    typedef T&                  reference;
};

struct output_iterator {
    typedef output_iterator_tag iterator_category;
    typedef void                value_type;
    typedef void                difference_type;
    typedef void                pointer;
    typedef void                reference;
};

template <typename T, typename Distance>
struct forward_iterator {
    typedef forward_iterator_tag iterator_category;
    typedef T                    value_type;
    typedef Distance             difference_type;
    typedef T*                   pointer;
    typedef T&                   reference;
};

template <typename T, typename Distance>
struct bidirectional_iterator {
    typedef bidirectional_iterator_tag  iterator_category;
    typedef T                           value_type;
    typedef Distance                    difference_type;
    typedef T*                          pointer;
    typedef T&                          reference;
};

template <typename T, typename Distance>
struct random_access_iterator {
    typedef random_access_iterator_tag  iterator_category;
    typedef T                           value_type;
    typedef Distance                    difference_type;
    typedef T*                          pointer;
    typedef T&                          reference;
};

/**
 * 这里提供一个iterator范本
 * 继承它便符合STL迭代器标准
 */
template <typename Category,
          typename T,
          typename Distance = ptrdiff_t,
          typename Pointer = T*,
          typename Reference = T& >
struct iterator {
    typedef Category    iterator_category;
    typedef T           value_type;
    typedef Distance    difference_type;
    typedef Pointer     pointer;
    typedef Reference   reference
};

/**
 * 迭代器萃取器
 * 对上面[struct iterator]的
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