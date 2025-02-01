#include <ra_engine.h>

void updateGame(float deltaTime) {
  ra::vec2<float> position(150.0f, 150.0f);
  float speed = 50.0f;

  position.x += speed * deltaTime;
  position.y += speed * deltaTime;
}

int main() {
  ra::Core core("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280,
                720, SDL_WINDOW_SHOWN);
  core.init();
  core.run();

  /*SDL_Window *window =*/
  /*    SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED,
   * SDL_WINDOWPOS_CENTERED,*/
  /*                     1280, 720, SDL_WINDOW_SHOWN);*/
  /*if (window == nullptr) {*/
  /*  std::cout << "window could not be created! SDL_Error" << SDL_GetError()*/
  /*            << std::endl;*/
  /*  return -1;*/
  /*}*/

  /*SDL_Renderer *renderer =*/
  /*    SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);*/
  /*if (!renderer) {*/
  /*  std::cerr << "Renderer could not be created! SDL_Error: " <<
   * SDL_GetError()*/
  /*            << std::endl;*/
  /*  SDL_DestroyWindow(window);*/
  /*  SDL_Quit();*/
  /*  return -1;*/
  /*}*/

  ra::Clock clock;
  clock.start();

  int quit = 0;
  SDL_Event e;

  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        quit = 1;
      }
    }

    // Get deltaTime from the clock
    float deltaTime = clock.getDeltaTime();

    // Update game logic using deltaTime
    updateGame(deltaTime);

    // Clear the screen
    SDL_SetRenderDrawColor(renderer, ra::GREEN.r, ra::GREEN.g, ra::GREEN.b,
                           ra::GREEN.a);
    SDL_RenderClear(renderer);

    // Render the current frame
    SDL_RenderPresent(renderer);

    // Delay to control the frame rate
    SDL_Delay(32);
  }

  SDL_DestroyWindow(window);

  SDL_Quit();

  return 0;
}
