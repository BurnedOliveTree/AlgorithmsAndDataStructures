#include "containers/queue.hpp"
#include <iostream>

using namespace ads;

int main()
{
    ads::Vector<int> test;
    test.push_back(1);
    ads::Vector<int> test2;
    test2.push_back(1);
    std::cout << test.compare(test2);
    std::cout << (test != test2);
    return 0;
}