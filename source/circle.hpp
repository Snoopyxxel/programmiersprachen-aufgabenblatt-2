#ifndef CIRCLE_HPP
#define CIRCLE_HPP


#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle {
public:
    Circle(Vec2 const &ctr, float r, Color const &col, std::string const &name);

    Circle(Vec2 const &ctr, float r, Color const &col, float thick);

    Circle(Vec2 const &ctr, float r, Color const &col);

    Circle(Vec2 const &ctr, float r);

    Circle(float r);

    float circumference() const;

    void draw(Window const &window) const;

    void draw(Window const &window, float thickness) const;

    bool is_inside(Vec2 const &point) const;

    float get_thickness() const;

    bool is_highl(std::string const &highl_name) const;

    float get_radius() const;

    bool operator<(Circle const& c) const;
    bool operator>(Circle const &c) const;
    bool operator==(Circle const& c) const;

private:
    float radius_;
    float thickness_ = 1.0f;
    Vec2 center_ = {0.0f, 0.0f};
    Color color_;
    std::string name_ = "NoName";
};


#endif //CIRCLE_HPP
