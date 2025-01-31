#ifndef RA_RENDERER_HPP
#define RA_RENDERER_HPP

#include <SDL2/SDL.h>

namespace ra {

class Renderer {
private:
  SDL_Renderer *_renderer;

public:
  Renderer(SDL_Window *window);
  ~Renderer();

  SDL_Window *getRenderer();
};

} // namespace ra

#endif // !RA_RENDERER_HPP
