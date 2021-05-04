#include <Catch2/catch.hpp>
#include "../list.hpp"

TEST_CASE("list") {
    ads::List<int> test;
    ads::List<int> test2;
    test.insert(9, 0);
    test.insert(4, 0);
    test.insert(6, 0);
    test2.insert(9, 0);
    test2.insert(4, 0);
    REQUIRE(test != test2);
    test2.insert(6, 0);
    REQUIRE(test == test2);
}