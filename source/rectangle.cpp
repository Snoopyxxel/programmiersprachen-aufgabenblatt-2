#include "rectangle.hpp"
#include "window.hpp"
#include <cmath>

Rectangle::Rectangle(Vec2 const &min, Vec2 const &max) :
min_{min}, max_{max} {}

Rectangle::Rectangle(Vec2 const &min, Vec2 const &max, Color const &col, float thick) :
min_{min}, max_{max}, color_{col}, thickness_{thick} {}

Rectangle::Rectangle(Vec2 const &min, Vec2 const &max, Color const &col) :
min_{min}, max_{max}, color_{col} {}

float Rectangle::get_thickness() const {
    return thickness_;
}

float Rectangle::circumference() const {
    return 2 * (abs(max_.x - min_.x) + abs(max_.y - min_.y));
}

void Rectangle::draw(Window const &window) const {
    window.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness_);
    window.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness_);
    window.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness_);
    window.draw_line(min_.x, max_.y, min_.x, min_.y, color_.r, color_.g, color_.b, thickness_);
}

void Rectangle::draw(Window const &window, float thickness) const {
    window.draw_line(min_.x, min_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness);
    window.draw_line(max_.x, min_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness);
    window.draw_line(max_.x, max_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness);
    window.draw_line(min_.x, max_.y, min_.x, min_.y, color_.r, color_.g, color_.b, thickness);
}

bool Rectangle::is_inside(Vec2 const &point) {
    return ((min_.x < point.x and point.x < max_.x) and (min_.y > point.y and point.y > max_.y));
}