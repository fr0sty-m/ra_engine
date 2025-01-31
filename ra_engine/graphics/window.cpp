#include "window.hpp"

namespace ra {

Window::Window(const char *title, int x, int y, int w, int h, uint32_t style) {
  _window = SDL_CreateWindow(title, x, y, w, h, style);
}

SDL_Window *Window::getWindow() { return _window; }

} // namespace ra
