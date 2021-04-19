#include "queue.hpp"
#include <iostream>

using namespace ads;

int main()
{
    ads::Queue<int> test;
    test.push_back(1);
    std::cout << test.pop();
    return 0;
}