#ifndef RA_APP_HPP
#define RA_APP_HPP

namespace ra {

struct App {
  virtual void update(float deltaTime) = 0;
  virtual void render() = 0;
};

} // namespace ra

#endif // !RA_APP_HPP
