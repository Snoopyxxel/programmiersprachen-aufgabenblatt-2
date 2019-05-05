#ifndef CIRCLE_HPP
#define CIRCLE_HPP


#include "vec2.hpp"
#include "color.hpp"

class Circle {
public:
    Circle(Vec2 const& ctr, float r, Color const &col);
    float circumference() const;
private:
    float radius_;
    Vec2 center_;
    Color color_;
};


#endif //CIRCLE_HPP
