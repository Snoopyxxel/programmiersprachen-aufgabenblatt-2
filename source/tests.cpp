#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

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
        WHEN("they are subtracted (-=)") {
            v -= v1;
            THEN("the second one gets subtracted from the first one") {
                REQUIRE(v.x == -2);
                REQUIRE(v.y == -2);
            }
        }
        WHEN("one gets multiplied with a constant (*=)") {
            v1 *= 2;
            THEN("it becomes the product") {
                REQUIRE(v1.x == 6);
                REQUIRE(v1.y == 8);
            }
        }
        WHEN("one gets divided by a constant (/=)") {
            v1 /= 2;
            THEN("it becomes the quotient") {
                REQUIRE(v1.x == Approx(1.5));
                REQUIRE(v1.y == Approx(2));
            }
        }
    }
}

SCENARIO("Vektorrechnung mit freien Funktionen", "[vector]") {
    GIVEN("Zwei Vektoren") {
        Vec2 v{1, 2};
        Vec2 v1{3, 4};
        WHEN("they are added") {
            auto erg = v + v1;
            THEN("+") {
                REQUIRE(erg.x == 4);
                REQUIRE(erg.y == 6);
            }
        }
        WHEN("they are subtracted") {
            auto erg = v - v1;
            THEN("-") {
                REQUIRE(erg.x == -2);
                REQUIRE(erg.y == -2);
            }
        }
        WHEN("one gets multiplied with a constant") {
            auto erg = v1 * 2;
            THEN("*") {
                REQUIRE(erg.x == 6);
                REQUIRE(erg.y == 8);
            }
        }
        WHEN("one gets divided by a constant") {
            auto erg = v1 / 2;
            THEN("/") {
                REQUIRE(erg.x == Approx(1.5));
                REQUIRE(erg.y == Approx(2));
            }
        }
    }
}

SCENARIO("Matrix multiplication", "[matrix]") {
    GIVEN("Two 2x2 matrices a and b") {
        Mat2 a{1, 2, 3, 4};
        Mat2 b{8, 9, 6, 5};

        WHEN("they get multiplied (*=)") {
            a *= b;
            THEN("a becomes the product") {
                REQUIRE(a.e_00 == 20);
                REQUIRE(a.e_01 == 19);
                REQUIRE(a.e_10 == 48);
                REQUIRE(a.e_11 == 47);
            }
        }
        WHEN("they get multiplied") {
            auto result = a * b;
            THEN("result = a * b") {
                REQUIRE(result.e_00 == 20);
                REQUIRE(result.e_01 == 19);
                REQUIRE(result.e_10 == 48);
                REQUIRE(result.e_11 == 47);
            }
        }
    }
}

TEST_CASE("Circumference") {
    Rectangle rectangle({2, 5}, {3, 7});
    Circle circle({8, 9}, 4);

    REQUIRE(rectangle.circumference() == 6);
    REQUIRE(circle.circumference() == Approx(25.132741228718));
}