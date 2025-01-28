#include "core.hpp"
#include <SDL.h>

namespace ra {

Core::Core() {}

Core::~Core() {}

void Core::init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    return;
  }
}

} // namespace ra
