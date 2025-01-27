find_package(SDL2 REQUIRED)

add_library(ra_engine-1.0 SHARED
assets/assets.cpp

core/core.cpp

utils/clock.cpp
)

target_link_libraries(ra_engine-1.0 SDL2 SDL2_image SDL2_ttf ${SDL2_LIBRARIES})
