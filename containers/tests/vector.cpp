#include <Catch2/catch.hpp>
#include "../vector.hpp"

TEST_CASE("vector") {
    ads::Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    REQUIRE(v.pop_front() == 1);
    REQUIRE(v.pop_front() == 2);
    REQUIRE(v.pop_front() == 3);
}
