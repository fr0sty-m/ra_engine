#ifndef RA_VEC2_H
#define RA_VEC2_H

#include <cmath>
#include <iostream>

namespace ra {

template <typename T> struct vec2 {
  T x, y;

  vec2() : x(0), y(0) {}
  vec2(T x, T y) : x(x), y(y) {}

  vec2 operator+(const vec2 &other) const {
    return vec2(x + other.x, y + other.y);
  }

  vec2 operator+(T scalar) const { return vec2(x + scalar, y + scalar); }

  vec2 operator-(const vec2 &other) const {
    return vec2(x - other.x, y - other.y);
  }

  vec2 operator*(T scalar) const { return vec2(x * scalar, y * scalar); }

  vec2 operator/(T scalar) const {
    if (scalar != 0) {
      return vec2(x / scalar, y / scalar);
    }
    std::cerr << "Error: Division by zero!" << std::endl;
    return *this;
  }

  T dot(const vec2 &other) const { return x * other.x + y * other.y; }

  T magnitude() const { return std::sqrt(x * x + y * y); }

  vec2 normalize() const {
    T mag = magnitude();
    if (mag > 0) {
      return vec2(x / mag, y / mag);
    }
    return *this;
  }

  vec2 perpendicular() const { return vec2(-y, x); }

  void print() const { std::cout << "(" << x << ", " << y << ")" << std::endl; }

  T angleBetween(const vec2 &other) const {
    T dotProd = dot(other);
    T mag1 = magnitude();
    T mag2 = other.magnitude();
    if (mag1 > 0 && mag2 > 0) {
      return std::acos(dotProd / (mag1 * mag2));
    }
    return 0.0f;
  }
};

} // namespace ra

#endif // !RA_VEC2_H
