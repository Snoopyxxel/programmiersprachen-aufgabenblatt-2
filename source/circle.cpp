#include <math.h>
#include "circle.hpp"
#include "mat2.hpp"

Circle::Circle(Vec2 const &ctr, float r, Color const &col) :
radius_{r}, center_{ctr}, color_{col} {}

float Circle::circumference() const {
    return 2 * M_PI * radius_;
}

void Circle::draw(Window const &window) const {
    Mat2 rotation = make_rotation_mat2((2 * M_PI) / 100);
    Vec2 start{radius_};
    for (int i = 1; i <= 100; ++i){
        Vec2 end = start * rotation;
        window.draw_line(center_.x + start.x, center_.y + start.y, center_.x + end.x, center_.y + end.y, color_.r, color_.g, color_.b);
        start = end;
    }
}