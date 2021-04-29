#include "containers/list.hpp"
#include <iostream>

using namespace ads;

int main()
{
    List<int> test;
    test.insert(9, 0);
    test.insert(4, 0);
    test.insert(6, 0);
    test.insert(5, 0);
    test.insert(2, 0);
    test.insert(7, 4);
    test.insert(8, 0);
    std::cout << test;
    return 0;
}