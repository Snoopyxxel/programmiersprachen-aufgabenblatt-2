#ifndef CIRCLE_HPP
#define CIRCLE_HPP


#include "vec2.hpp"

class Circle {
public:
    Circle(Vec2 const& ctr, float r);
private:
    float radius_;
    Vec2 center_;
};


#endif //CIRCLE_HPP
