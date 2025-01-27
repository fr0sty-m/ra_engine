#ifndef RA_CLOCK_HPP
#define RA_CLOCK_HPP

#include <cstdint>
namespace ra {

class Clock {
private:
  uint32_t startTime;
  uint32_t previousTime;
  uint32_t pausedTime;
  bool paused;
  bool started;

public:
  Clock();

  void start();
  void stop();
  void pause();
  void unpause();

  uint32_t getTicks();
  float getSeconds();

  bool isStarted();
  bool isPaused();

  float getDeltaTime();
};

} // namespace ra

#endif // !RA_CLOCK_HPP
