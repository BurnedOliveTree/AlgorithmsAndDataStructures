#include "containers/heap.hpp"
#include <iostream>

using namespace ads;

int main()
{
    ads::Heap<int> test(2);
    test.push_back(9);
    test.push_back(4);
    test.push_back(10);
    test.push_back(2);
    test.push_back(5);
    test.push_back(1);
    std::cout << test;
    return 0;
}