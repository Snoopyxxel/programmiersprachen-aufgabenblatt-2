#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP


#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle {
public:
    Rectangle(Vec2 const &min, Vec2 const &max, Color const &col, float thick);
    Rectangle(Vec2 const &min, Vec2 const &max, Color const &col);
    float circumference() const;
    void draw(Window const &window) const;
    void draw(Window const &window, float thickness) const;
    bool is_inside(Vec2 const &point);
    float get_thickness() const;
private:
    float thickness_ = 1.0f;
    Vec2 min_;
    Vec2 max_;
    Color color_;
};


#endif //RECTANGLE_HPP
