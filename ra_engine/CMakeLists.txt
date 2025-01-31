find_package(SDL2 REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/ra_engine)

add_library(ra_engine-1.0 SHARED
assets/assets.cpp

core/core.cpp

graphics/display.cpp

log/logger.cpp

utils/clock.cpp
)

target_link_libraries(ra_engine-1.0 SDL2 SDL2_image SDL2_ttf ${SDL2_LIBRARIES})
