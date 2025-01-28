#include "logger.hpp"
#include <ctime>
#include <iostream>
#include <sstream>

// Generic helper function to convert any type to string
template <typename T> std::string toString(const T &value) {
  std::ostringstream oss;
  oss << value;
  return oss.str();
}

namespace ra {

// Definition of the log function
template <typename... Args> void Logger::log(Args &&...args) {
  std::stringstream ss;

  // Concatenate all arguments into the stringstream
  ((ss << toString(std::forward<Args>(args))), ...);

  // Output the final concatenated string to console with a timestamp
  std::cout << getTimestamp() << " - " << ss.str() << std::endl;
}

// Definition of getTimestamp function
std::string Logger::getTimestamp() {
  std::time_t now = std::time(nullptr);
  char buffer[100];
  std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S",
                std::localtime(&now));
  return std::string(buffer);
}

} // namespace ra

// Explicit template instantiation is not required now, as toString() works with
// all types.
