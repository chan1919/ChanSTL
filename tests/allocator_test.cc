/**
 * @file allocator_test.cc
 * @author czy (suoni1919@gmail.com)
 * @date 2022-07-15
 * 
 * @copyright Copyright (Chan) 2022
 * 
 */

#include "../allocator.h"
#include <iostream>

int main() {
    int*  addr1 = allocator<int>::allocate();
    *addr1 = 5;
    std::cout << *addr1<<std::endl;
    *addr1 = 100;
    std::cout << *addr1<<std::endl;
    delete addr1;

    int* addr2 = allocator<int>::allocate(5);
    *(addr2) = 1;
    *(addr2+1) = 2;
    *(addr2+2) = 3;
    *(addr2+3) = 4;
    *(addr2+4) = 6666;
    allocator<int>::deallocate(addr2);
    // delete (addr2+4);  //delete两次
    return 0;
}