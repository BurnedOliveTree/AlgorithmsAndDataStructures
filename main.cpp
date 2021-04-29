#include "containers/list.hpp"
#include <iostream>

using namespace ads;

int main()
{
    List<int> test;
    test.insert(9, 0);
    test.insert(4, 0);
    test.insert(6, 0);
    test.erase(1);
    std::cout << test;
    return 0;
}