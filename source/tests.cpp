#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "vec2.hpp"


SCENARIO("Vector-Initialisierung", "[vector]"){
    GIVEN("Eine Initialisierung ohne Parameter"){
        Vec2 v;

        REQUIRE(v.x == 0.0f);
        REQUIRE(v.y == 0.0f);
    }
    GIVEN("Eine Aggregatinitialisierung mit Parametern"){
        Vec2 v{1.2,3.5};

        REQUIRE(v.x == Approx(1.2));
        REQUIRE(v.y == Approx(3.5));
    }
    /*
    GIVEN("Eine nicht-Aggregatinitialisierung"){
        Vec2 v(1.2,3.5);

        REQUIRE(v.x == 0.0f);
        REQUIRE(v.y == 0.0f);
    }
     */
}
