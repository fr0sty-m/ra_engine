#ifndef RA_LOGGER_HPP
#define RA_LOGGER_HPP

#include <string>

namespace ra {

class Logger {
public:
  // Static log function that can take multiple arguments
  template <typename... Args> static void log(Args &&...args);

private:
  // Private function to get the current timestamp in string format
  static std::string getTimestamp();
};

} // namespace ra

#endif
