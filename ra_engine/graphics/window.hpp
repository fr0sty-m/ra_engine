#ifndef RA_WINDOW_HPP
#define RA_WINDOW_HPP

#include <SDL2/SDL.h>
#include <cstdint>

namespace ra {

class Window {
private:
  SDL_Window *_window;

public:
  Window(const char *title, int x, int y, int w, int h, uint32_t style);
  ~Window();

  SDL_Window *getWindow();
};

} // namespace ra

#endif // !RA_WINDOW_HPP
