//
// Created by vito on 06.05.19.
//

#ifndef BLATT2_RECTANGLE_HPP
#define BLATT2_RECTANGLE_HPP


#include "vec2.hpp"

class Rectangle {
public:
    Rectangle(Vec2 min, Vec2 max);

private:
    Vec2 min_;
    Vec2 max_;
};


#endif //BLATT2_RECTANGLE_HPP
