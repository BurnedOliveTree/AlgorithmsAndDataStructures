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

TEST_CASE("vector-insert", "[container][vector][insert]") {
    ads::Vector<int> v;
    v.insert(-1, 0);
    v.insert(2, 0);
    v.insert(34235523, 1);
    REQUIRE(v[0] == 2);
    REQUIRE(v[1] == 34235523);
    REQUIRE(v[2] == -1);
}

TEST_CASE("vector-erase", "[container][vector][erase]") {
    ads::Vector<int> v;
    int c[3] = {1, 2, 3};
    v.assign(c, 3);
    REQUIRE(v.erase(1) == 2);
    REQUIRE(v.erase(1) == 3);
    REQUIRE(v.erase(0) == 1);
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
