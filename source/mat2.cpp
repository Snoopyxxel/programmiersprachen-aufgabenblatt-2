#include "mat2.hpp"
#include <cmath>

Mat2& Mat2::operator*=(Mat2 const &m) {
    float a_00 = (e_00 * m.e_00) + (e_01 * m.e_10);
    float a_01 = (e_00 * m.e_01) + (e_01 * m.e_11);
    float a_10 = (e_10 * m.e_00) + (e_11 * m.e_10);
    float a_11 = (e_10 * m.e_01) + (e_11 * m.e_11);
    e_00 = a_00;
    e_01 = a_01;
    e_10 = a_10;
    e_11 = a_11;
    return *this;
}

float Mat2::det() const {
    return e_00 * e_11 - e_10 * e_01;
}

Mat2 operator*(Mat2 const &m1, Mat2 const &m2){
    Mat2 erg = m1;
    erg *= m2;
    return erg;
}

Mat2 operator*(Mat2 const &m, float s){
    Mat2 erg{m.e_00 + s, m.e_01 + s, m.e_10 + s, m.e_11 + s}
    return erg;
}

Mat2 operator*(float s, Mat2 const &m){
    Mat2 erg{m.e_00 + s, m.e_01 + s, m.e_10 + s, m.e_11 + s}
    return erg;
}

Vec2 operator*(Mat2 const &m, Vec2 const &v){
    Vec2 erg{m.e_00 * v.x + m.e_01 * v.y};
    return erg;
}

Vec2 operator*(Vec2 const &v, Mat2 const &m){
    Vec2 erg{m.e_00 * v.x + m.e_01 * v.y};
    return erg;
}

Mat2 adj(Mat2 const &m){
    Mat2 adj{m.e_11, -m.e_01, -m.e_10, m.e_00};
}

Mat2 inverse(Mat2 const &m){
    if (m.det() != 0){
        return 1/m.det() * adj(m);
    } else{
        throw "Determinante ist 0, Inverses kann nicht berechnet werden!";
    }
}

Mat2 transpose(Mat2 const &m){
    Mat2 transp{m.e_11, m.e_01, m.e_10, m.e_00};
    return transp;
}

Mat2 make_rotation_mat2(float phi){
    Mat2 erg{cosf(phi), -sinf(phi), sinf(phi), cosf(phi)};
    return erg;
}
