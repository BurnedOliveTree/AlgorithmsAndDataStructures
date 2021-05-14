#include <Catch2/catch.hpp>
#include "../search.hpp"

#include <string>
#include "../../containers/vector.hpp"

TEST_CASE("search-naive", "[algorithm][search][naive]") {
    std::string text = "ACABCCCBABCBABCABCB";
    std::string pattern = "ABC";
    ads::Vector<unsigned long> indexes;
    find_naive(pattern, text, indexes);
    REQUIRE(indexes[0] == 2);
    REQUIRE(indexes[1] == 8);
    REQUIRE(indexes[2] == 12);
    REQUIRE(indexes[3] == 15);
}

TEST_CASE("search-BoyerMoore", "[algorithm][search][BoyerMoore]") {
    std::string text = "ACABCCCBABCBABCABCB";
    std::string pattern = "ABC";
    ads::Vector<unsigned long> indexes;
    find_BoyerMoore(pattern, text, indexes);
    REQUIRE(indexes[0] == 2);
    REQUIRE(indexes[1] == 8);
    REQUIRE(indexes[2] == 12);
    REQUIRE(indexes[3] == 15);
}