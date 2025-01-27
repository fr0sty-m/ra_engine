#ifndef RA_COLOR_HPP
#define RA_COLOR_HPP

#include <cstdint>

namespace ra {

typedef struct Color {
  uint8_t r, g, b, a;

  Color() : r(0), g(0), b(0), a(255) {}
  Color(float r, float g, float b) : r(r), g(g), b(b), a(255) {}
  Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}

} Color;

static const Color WHITE = Color(255, 255, 255);
static const Color BLACK = Color();
static const Color DARK_GRAY = Color(33, 33, 33);

static const Color RED = Color(172, 50, 50);
static const Color YELLOW = Color(251, 242, 54);
static const Color GREEN = Color(106, 190, 48);
static const Color BLUE = Color(0, 102, 182);

} // namespace ra

#endif // !RA_COLOR_HPP
