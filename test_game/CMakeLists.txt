set(ra ${CMAKE_SOURCE_DIR}/ra_engine)

include_directories(${ra})

add_executable(test_game main.cpp)

target_link_libraries(test_game ra_engine-1.0)
