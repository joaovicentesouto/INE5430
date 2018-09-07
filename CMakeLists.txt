################################################################################
# Set up global variables
################################################################################

# Set up minimal cmake version
cmake_minimum_required(VERSION 3.5.1)

# Set project name
project(ai)

# Set project version
set(ai_VERSION 0.1)

# Set c++14 globally
set(CMAKE_CXX_STANDARD 14)

# Set formal_languages source dir
set(ai_source_dir ${PROJECT_SOURCE_DIR})

################################################################################
# Project logic 
################################################################################

# Add subdirectories
add_subdirectory(3rdparty)
add_subdirectory(ai)
add_subdirectory(apps)
add_subdirectory(tests)