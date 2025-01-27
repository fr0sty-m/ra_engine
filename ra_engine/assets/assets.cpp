#include "assets.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>

namespace ra {

// Constructor
Assets::Assets() {}

// Destructor
Assets::~Assets() {
  clearAssets(); // Clean up all loaded assets
}

// Load a texture from a file
bool Assets::loadTexture(const std::string &textureID,
                         const std::string &filePath, SDL_Renderer *renderer) {
  // Check if the texture already exists
  if (textures.find(textureID) != textures.end()) {
    std::cout << "Texture with ID '" << textureID << "' already loaded.\n";
    return false;
  }

  // Load the texture
  SDL_Texture *newTexture = IMG_LoadTexture(renderer, filePath.c_str());
  if (newTexture == nullptr) {
    std::cerr << "Unable to load texture '" << filePath
              << "': " << SDL_GetError() << std::endl;
    return false;
  }

  // Store the loaded texture
  textures[textureID] = newTexture;
  return true;
}

// Load a font from a file
bool Assets::loadFont(const std::string &fontID, const std::string &filePath,
                      int fontSize) {
  // Check if the font already exists
  if (fonts.find(fontID) != fonts.end()) {
    std::cout << "Font with ID '" << fontID << "' already loaded.\n";
    return false;
  }

  // Load the font
  TTF_Font *newFont = TTF_OpenFont(filePath.c_str(), fontSize);
  if (newFont == nullptr) {
    std::cerr << "Unable to load font '" << filePath << "': " << TTF_GetError()
              << std::endl;
    return false;
  }

  // Store the loaded font
  fonts[fontID] = newFont;
  return true;
}

// Retrieve a texture by its ID
SDL_Texture *Assets::getTexture(const std::string &textureID) {
  if (textures.find(textureID) != textures.end()) {
    return textures[textureID];
  }
  std::cerr << "Texture with ID '" << textureID << "' not found.\n";
  return nullptr;
}

// Retrieve a font by its ID
TTF_Font *Assets::getFont(const std::string &fontID) {
  if (fonts.find(fontID) != fonts.end()) {
    return fonts[fontID];
  }
  std::cerr << "Font with ID '" << fontID << "' not found.\n";
  return nullptr;
}

// Clear all loaded assets (textures and fonts)
void Assets::clearAssets() {
  // Free textures
  for (auto &texturePair : textures) {
    SDL_DestroyTexture(texturePair.second);
  }
  textures.clear();

  // Free fonts
  for (auto &fontPair : fonts) {
    TTF_CloseFont(fontPair.second);
  }
  fonts.clear();
}

} // namespace ra
