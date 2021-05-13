#include <Catch2/catch.hpp>
#include "../vector.hpp"

TEST_CASE("vector-push", "[container][vector][push]") {
    ads::Vector<int> v;
    v.push_back(-1);
    v.push_back(2);
    v.push_back(34235523);
    REQUIRE(v[0] == -1);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 34235523);
}

TEST_CASE("vector-compare", "[container][vector][compare]") {
    ads::Vector<int> test;
    ads::Vector<int> test2;
    test.push_back(1);
    test.push_back(2);
    test2.push_back(1);
    REQUIRE(test != test2);
    test2.push_back(2);
    REQUIRE(test.compare(test2));
}
