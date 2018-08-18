################################################################################
# Set up global variables
################################################################################

# Set up minimal cmake version
cmake_minimum_required(VERSION 3.5.1)

# Set project name
project(minimax)

# Set project version
set(minimax_VERSION 0.1)

# Set c++14 globally
set(CMAKE_CXX_STANDARD 14)

# Set formal_languages source dir
set(minimax_source_dir ${PROJECT_SOURCE_DIR})

################################################################################
# Project logic 
################################################################################

# Add subdirectories
add_subdirectory(minimax)
add_subdirectory(tests)