#include "rectangle.hpp"
#include "window.hpp"
#include <cmath>

Rectangle::Rectangle(Vec2 const &min, Vec2 const &max, Color const &col) :
min_{min}, max_{max}, color_{col} {}

float Rectangle::circumference() const {
    return 2 * (abs(max_.x - min_.x) + abs(max_.y - min_.y));
}

void Rectangle::draw(Window const &window) const {
    window.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b);
    window.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b);
    window.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b);
    window.draw_line(min_.x, max_.y, min_.x, min_.y, color_.r, color_.g, color_.b);
}

void Rectangle::draw(Window const &window, float const &thickness) const {
    window.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness);
    window.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness);
    window.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness);
    window.draw_line(min_.x, max_.y, min_.x, min_.y, color_.r, color_.g, color_.b, thickness);
}