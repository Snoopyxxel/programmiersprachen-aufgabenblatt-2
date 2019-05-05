#include "mat2.hpp"

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

Mat2 operator*(Mat2 const &m1, Mat2 const &m2){
    Mat2 erg = m1;
    erg *= m2;
    return erg;
}