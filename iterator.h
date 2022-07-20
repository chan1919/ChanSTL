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