#include "containers/list.hpp"
#include <iostream>

using namespace ads;

int main()
{
    List<int> test;
    List<int> test2;
    test.insert(9, 0);
    test.insert(4, 0);
    test.insert(6, 0);
    test2.insert(9, 0);
    test2.insert(4, 0);
    std::cout << (test != test2);
    test2.insert(6, 0);
    std::cout << (test == test2);
    return 0;
}