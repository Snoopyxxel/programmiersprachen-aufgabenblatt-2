#include <math.h>
#include "Circle.hpp"

Circle::Circle(Vec2 const &ctr, float r) :
center_{ctr}, radius_{r} {}

float Circle::circumference() const {
    return 2 * M_PI * radius_;
}
