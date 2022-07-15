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
    // new 1个
    static T* allocate() { 
        return static_cast<T*>(::operator new(sizeof(T)));
    }
    // new n个
    static T* allocate(int n) {
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

};