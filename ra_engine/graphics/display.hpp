#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

namespace ra {

class Display {
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  TTF_Font *font; // Font for rendering text

public:
  // Constructor and Destructor
  Display(const std::string &title, int width, int height);
  ~Display();

  // Initialize SDL2 and TTF
  bool init();

  // Methods to draw basic shapes
  void drawLine(int x1, int y1, int x2, int y2, SDL_Color color);
  void drawRect(int x, int y, int w, int h, SDL_Color color);
  void drawCircle(int x, int y, int radius, SDL_Color color);

  // Method to render text
  void drawText(const std::string &text, int x, int y, SDL_Color color);

  // Clear the screen and present the rendering
  void clear();
  void present();
};

} // namespace ra

#endif // DISPLAY_HPP
