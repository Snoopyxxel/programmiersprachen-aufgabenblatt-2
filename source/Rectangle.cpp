#include "Rectangle.hpp"
#include <cmath>

Rectangle::Rectangle(Vec2 const &min, Vec2 const &max) :
min_{min}, max_{max} {}

float Rectangle::circumference() const {
    return 2 * (abs(max_.x - min_.x) + abs(max_.y - min_.y));
}
