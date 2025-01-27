#ifndef RA_ASSETS_HPP
#define RA_ASSETS_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <unordered_map>

namespace ra {

class Assets {
public:
  // Constructor & Destructor
  Assets();
  ~Assets();

  // Load assets
  bool loadTexture(const std::string &textureID, const std::string &filePath,
                   SDL_Renderer *renderer);
  bool loadFont(const std::string &fontID, const std::string &filePath,
                int fontSize);

  // Get assets
  SDL_Texture *getTexture(const std::string &textureID);
  TTF_Font *getFont(const std::string &fontID);

  // Clean up assets
  void clearAssets();

private:
  // Maps to store loaded assets
  std::unordered_map<std::string, SDL_Texture *> textures;
  std::unordered_map<std::string, TTF_Font *> fonts;
};

} // namespace ra

#endif // RA_ASSETS_HPP
