#include <math.h>
#include "Circle.hpp"

Circle::Circle(Vec2 const &ctr, float r, Color const &col) :
center_{ctr}, radius_{r}, color_{col} {}

float Circle::circumference() const {
    return 2 * M_PI * radius_;
}
