#include "renderer.hpp"

namespace ra {

Renderer::Renderer(SDL_Window *window) {
  _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Renderer::~Renderer() { SDL_DestroyRenderer(_renderer); }

} // namespace ra
