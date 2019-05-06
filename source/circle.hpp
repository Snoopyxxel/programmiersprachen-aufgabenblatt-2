#ifndef CIRCLE_HPP
#define CIRCLE_HPP


#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle {
public:
    Circle(Vec2 const& ctr, float r, Color const &col);
    float circumference() const;
    void draw(Window const &window) const;
private:
    float radius_;
    Vec2 center_;
    Color color_;
};


#endif //CIRCLE_HPP
