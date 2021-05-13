#include <Catch2/catch.hpp>
#include "../heap.hpp"

TEST_CASE("heap-push", "[container][heap][push]") {
    ads::Heap<int> test(2);
    test.push_back(9);
    test.push_back(4);
    test.push_back(10);
    test.push_back(2);
    test.push_back(5);
    test.push_back(1);
    REQUIRE(test[0] == 1);
    REQUIRE(test[2] == 4);
}