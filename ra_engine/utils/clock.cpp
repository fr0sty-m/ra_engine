#include "clock.hpp"
#include <SDL2/SDL.h>
#include <SDL_timer.h>

namespace ra {

Clock::Clock() : startTime(0), pausedTime(0), paused(false), started(false) {}

void Clock::start() {
  if (!started) {
    startTime = SDL_GetTicks();
    pausedTime = 0;
    started = true;
    paused = false;
  }
}

void Clock::stop() {
  started = false;
  paused = false;
  pausedTime = 0;
}

void Clock::pause() {
  if (started && !paused) {
    paused = true;
    pausedTime += SDL_GetTicks() - startTime;
  }
}

void Clock::unpause() {
  if (started && paused) {
    paused = false;
    startTime = SDL_GetTicks();
  }
}

uint32_t Clock::getTicks() {
  if (started) {
    if (paused) {
      return pausedTime;
    }
    return pausedTime + (SDL_GetTicks() - startTime);
  }
  return 0;
}

float Clock::getSeconds() { return getTicks() / 1000.0f; }

bool Clock::isStarted() { return started; }

bool Clock::isPaused() { return paused; }

float Clock::getDeltaTime() {
  uint32_t currentTime = SDL_GetTicks();
  uint32_t deltaTime =
      currentTime - previousTime; // Time difference between frames
  previousTime = currentTime;     // Update previous time to current time

  return deltaTime / 1000.0f; // Convert delta time to seconds
}

} // namespace ra
