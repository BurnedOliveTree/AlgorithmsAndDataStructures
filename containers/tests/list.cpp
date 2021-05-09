#include <Catch2/catch.hpp>
#include "../list.hpp"

TEST_CASE("list-compare", "[container][list][compare]") {
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

TEST_CASE("list-assign", "[container][list][assign]") {
    ads::List<int> test;
    int c[3] = {2, 4, 6};
    test.assign(c, 3);
    REQUIRE(test.front() == c[0]);
    REQUIRE(test.back() == c[2]);
    REQUIRE(test.size() == 3);
    ads::List<int> test2;
    test2.assign(10, 3);
    REQUIRE(test2.front() == 10);
    REQUIRE(test2.back() == 10);
    REQUIRE(test2.size() == 3);
}