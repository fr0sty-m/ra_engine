#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <cstdint>
#include <string>

#include "graphics/window.hpp"

namespace ra {

class Display {
private:
  SDL_Renderer *_renderer;

public:
  // Constructor and Destructor
  Display(Window window);
  ~Display();

  // Initialize SDL2 and TTF
  bool init();

  // Methods to draw basic shapes
  static void drawLine(int x1, int y1, int x2, int y2, SDL_Color color);
  static void drawRect(int x, int y, int w, int h, SDL_Color color);
  static void drawCircle(int x, int y, int radius, SDL_Color color);

  // Method to render text
  static void drawText(const std::string &text, int x, int y, SDL_Color color);

  // Clear the screen and present the rendering
  static void setColor(uint8_t r, uint8_t g, uint8_t b);
  static void setClearColor(uint8_t r, uint8_t g, uint8_t b);
  static void clear();
  static void present();
};

} // namespace ra

#endif // DISPLAY_HPP
