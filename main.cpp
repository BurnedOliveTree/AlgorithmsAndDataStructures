#include "containers/heap.hpp"
#include <iostream>

using namespace ads;

int main()
{
    ads::Heap<int> test(2);
    test.append(9);
    test.append(4);
    test.append(10);
    test.append(2);
    test.append(5);
    test.append(1);
    std::cout << test;
    return 0;
}