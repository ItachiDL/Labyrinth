cmake_minimum_required(VERSION 3.12)
project(MyProject)

# Add your source files here
set(SOURCES
    src/main.cpp
    src/foo.cpp
    src/bar.cpp
)

# Add any additional include directories here
include_directories(include)

# Add any additional library directories here
link_directories(lib)

# Add any additional libraries here
set(LIBRARIES
    my_library
)

# Set the output directory for the built executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add your executable target here
add_executable(MyExecutable ${SOURCES})

# Link any libraries to the executable
target_link_libraries(MyExecutable ${LIBRARIES})