#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <functional>

bool is_multiple_of_3(unsigned int i){
    return i % 3 == 0;
}

template <typename T>
T filter(T const& c, std::function<bool(typename T::value_type)> f){
    T out(c);
    out.erase(std::remove_if(out.begin(), out.end(), [&f] (typename T::value_type i) -> bool {return !f(i);}), out.end());
    return out;
}

TEST_CASE("filter alle vielfache von drei mit fkt-template"){

    std::vector<unsigned int> v(100);

    for (auto &item : v) {
        item = std::rand() % 101;
    }

    std::vector<unsigned int> n = filter(v, is_multiple_of_3);
    REQUIRE(std::all_of(n.begin(), n.end(), is_multiple_of_3));
}

TEST_CASE("filter alle vielfache von drei", "[erase]"){

    std::vector<unsigned int> v(100);

    for (auto &item : v) {
        item = std::rand() % 101;
    }

    v.erase(std::remove_if(v.begin(), v.end(), [] (int i) {return !is_multiple_of_3(i);}), v.end());

    REQUIRE(std::all_of(v.begin(), v.end(), is_multiple_of_3));
}

TEST_CASE("add containers"){
    std :: vector < int > v_1 {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
    std :: vector < int > v_2 {9 ,8 ,7 ,6 ,5 ,4 ,3 ,2 ,1};
    std :: vector < int > v_3 (9);
    std::transform(v_1.cbegin(), v_1.cend(), v_2.cbegin(), v_3.begin(), [] (int i, int j) {return i + j;});

    REQUIRE(std::all_of(v_3.cbegin(), v_3.cend(), [] (int i) {return i == 10;}));
}