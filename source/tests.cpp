#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "vec2.hpp"

SCENARIO("Vector-Initialisierung", "[vector]") {
    GIVEN("Eine Initialisierung ohne Parameter") {
        Vec2 v;

        REQUIRE(v.x == 0.0f);
        REQUIRE(v.y == 0.0f);
    }
    GIVEN("Eine Aggregatinitialisierung mit Parametern") {
        Vec2 v{1.2, 3.5};

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

SCENARIO("Vektorrechnung mit Memberfunktionen", "[vector]") {
    GIVEN("Zwei Vektoren") {
        Vec2 v{1, 2};
        Vec2 v1{3, 4};
        WHEN("they are added (+=)") {
            v += v1;
            THEN("the first one is the sum of both of them") {
                REQUIRE(v.x == 4);
                REQUIRE(v.y == 6);
            }
        }
        WHEN("they are subtracted (-=)"){
            v -= v1;
            THEN("the second one gets subtracted from the first one"){
                REQUIRE(v.x == -2);
                REQUIRE(v.y == -2);
            }
        }
        WHEN("one gets multiplied with a constant (*=)"){
            v1 *= 2;
            THEN("it becomes the product"){
                REQUIRE(v1.x == 6);
                REQUIRE(v1.y == 8);
            }
        }
        WHEN("one gets divided by a constant (/=)"){
            v1 /= 2;
            THEN("it becomes the quotient"){
                REQUIRE(v1.x == Approx(1.5));
                REQUIRE(v1.y == Approx(2));
            }
        }
    }
}
