#include "vec2.hpp"

Vec2 & Vec2::operator +=(Vec2 const& v ){
    this->x = this->x + v.x;
    this->y = this->y + v.y;
    return *this;
}

Vec2 & Vec2::operator-=(Vec2 const& v) {
    this->x = this->x - v.x;
    this->y = this->y - v.y;
    return *this;
}

Vec2 & Vec2::operator*=(float s) {
    this->x = this->x * s;
    this->y = this->y * s;
    return *this;
}

Vec2 & Vec2::operator/=(float s) {
    this->x = this->x / s;
    this->y = this->y / s;
    return *this;
}