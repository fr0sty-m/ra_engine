#include "core.hpp"
#include <SDL.h>

namespace ra {

Core::Core(const char *title, int x, int y, int width, int height,
           uint32_t style)
    : _title(title), _x(x), _y(y), _w(width), _h(height), _style(style) {}

Core::~Core() {
  //
  cleanUp();
}

int Core::init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    return -1;
  }

  return 0;
}

int Core::run() {
  if (init() != 0) {
    return -1;
  }

  return 0;
}

} // namespace ra
