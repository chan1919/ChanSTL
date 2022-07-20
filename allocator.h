/**
 * @file allocator.h
 * @author czy (suoni1919@gmail.com)
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma

template <typename T>
class allocator {
public:
    /**
     * 申请内存，并未调用构造函数
     * @return T* 
     */
    static T* allocate() { 
        return static_cast<T*>(::operator new (sizeof(T)));
    }
    static T* allocate(int n) {
        if (n == 0) return nullptr;
        return static_cast<T*>(::operator new (n * sizeof(T)));
    }

    /**
     * 释放内存，并未调用析构函数
     * @param ptr 
     */
    static void deallocate(T* ptr) {
        if (ptr == nullptr) return;
        ::operator delete (ptr);
    }

};