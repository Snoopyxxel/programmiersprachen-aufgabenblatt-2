#include <math.h>
#include "circle.hpp"
#include "mat2.hpp"

Circle::Circle(Vec2 const &ctr, float r, Color const &col, float thick) :
radius_{r}, center_{ctr}, color_{col}, thickness_{thick} {}

Circle::Circle(Vec2 const &ctr, float r, Color const &col) :
radius_{r}, center_{ctr}, color_{col} {}

float Circle::get_thickness() const {
    return thickness_;
}

float Circle::circumference() const {
    return 2 * M_PI * radius_;
}

void Circle::draw(Window const &window) const {
    Mat2 rotation = make_rotation_mat2((2 * M_PI) / 100);
    Vec2 start{radius_};
    for (int i = 1; i <= 100; ++i){
        Vec2 end = start * rotation;
        window.draw_line(center_.x + start.x, center_.y + start.y, center_.x + end.x, center_.y + end.y, color_.r, color_.g, color_.b, thickness_);
        start = end;
    }
}

void Circle::draw(Window const &window, float thickness) const {
    Mat2 rotation = make_rotation_mat2((2 * M_PI) / 100);
    Vec2 start{radius_};
    for (int i = 1; i <= 100; ++i){
        Vec2 end = start * rotation;
        window.draw_line(center_.x + start.x, center_.y + start.y, center_.x + end.x, center_.y + end.y, color_.r, color_.g, color_.b, thickness);
        start = end;
    }
}

bool Circle::is_inside(Vec2 const &point) const {
    Vec2 center_to_point = center_ - point;
    return  abs(sqrt(pow(center_to_point.x, 2) + pow(center_to_point.y, 2))) < radius_;
}