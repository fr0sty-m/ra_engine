#ifndef RA_CORE_HPP
#define RA_CORE_HPP

#include <SDL2/SDL.h>
#include <cstdint>

namespace ra {

class Core {
private:
  const char *_title;
  int _x, _y, _w, _h;
  uint32_t _style;

public:
  Core(const char *title, int x, int y, int width, int height, uint32_t style);
  ~Core();

  void cleanUp();

  int init();
  int run();

  int loop();
};

} // namespace ra

#endif // !RA_CORE_HPP
