#ifndef RA_CORE_HPP
#define RA_CORE_HPP

#include <SDL2/SDL.h>

namespace ra {

class Core {
private:
public:
  Core();
  ~Core();

  void init();
};

} // namespace ra

#endif // !RA_CORE_HPP
