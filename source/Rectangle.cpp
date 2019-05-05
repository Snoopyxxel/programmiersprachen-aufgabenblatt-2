#include "Rectangle.hpp"
#include <cmath>

Rectangle::Rectangle(Vec2 const &min, Vec2 const &max, Color const &col) :
min_{min}, max_{max}, color_{col} {}

float Rectangle::circumference() const {
    return 2 * (abs(max_.x - min_.x) + abs(max_.y - min_.y));
}
