#include "display.hpp"
#include "graphics/window.hpp"
#include <SDL_render.h>

namespace ra {

Display::Display(Window window) {
  _renderer = SDL_CreateRenderer(window.getWindow(), 0, -1);
}

Display::~Display() { SDL_DestroyRenderer(_renderer); }

} // namespace ra
