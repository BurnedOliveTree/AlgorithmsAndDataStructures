#include <Catch2/catch.hpp>
#include "../queue.hpp"

TEST_CASE("queue-push_pop", "[container][queue][push][pop]") {
    ads::Queue<int> v;
    v.push_back(-1);
    v.push_back(2);
    v.push_back(3234233);
    REQUIRE(v.pop_front() == -1);
    REQUIRE(v.pop_front() == 2);
    REQUIRE(v.pop_front() == 3234233);
}