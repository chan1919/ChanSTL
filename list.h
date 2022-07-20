/**
 * @file list.h
 * @author czy (suoni1919@gmail.com)
 * @date 2022-07-20
 * 
 * @copyright Copyright (Chan) 2022
 * 
 */
#pragma once
#include "allocator.h"
#include "construct.h"
#include "iterator.h"
/**
 * 链表节点
 * @tparam T 
 */
template <typename T>
struct list_node {
    list_node<T>* prev;
    list_node<T*> next;
    T             data;
};
/**
 * list的迭代器
 * 本质上是对list_node*的封装
 * 代理模式
 * @tparam T 
 */
template<typename T>
class list_iterator {
public:
    typedef list_iterator<T>    iterator;
    typedef list_iterator<T>    self;

    typedef bidirectional_iterator_tag  iterator_tag;
    typedef T                           value;
    typedef T*                          pointer;
    typedef T&                          reference;
    typedef list_node<T>*               node_ptr;
    typedef size_t                      size_type;
    typedef ptrdiff_t                   difference_type;

    // 链表迭代器指向结点的指针
    node_ptr _node_p; 

    list_iterator(node_ptr node_p): _node_p(node_p) {}
    list_iterator() {}
    list_iterator(const iterator& it): _node_p(it._node_p) {}

    //判断指向的结点是否相同
    bool operator == (const self& it) const {
        return _node_p == it._node_p;
    }
    bool operator != (const self& it) const {
        return _node_p != it._node_p;
    }
    
    reference operator*() const {
        return (*_node_p).data;
    }

    pointer operator->() const {
        return &(operator*());
    }

    // ++x
    self& operator++ () {
        _node_p = (node_ptr) ((*_node_p).next);
        return *this;
    }
    // x++
    self operator++ (int) {
        self temp = *this;
        ++(*this);
        return temp;
    }
    // --x
    self& operator-- () {
        _node_p = (node_ptr) ((*_node_p).prev);
        return *this;
    }
    // x--
    self operator-- (int) {
        self temp = *this;
        --(*this);
        return temp;
    }  
};
