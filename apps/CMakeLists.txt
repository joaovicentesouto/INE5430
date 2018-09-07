################################################################################
# This is the CMakeLists file for the AI library Test binary. 
#
# Its main goals are:
#   - Fetch test files.
#   - Configure Catch test library.
#   - Add test target.
#   - Link test target.
#   - Prepare test input environment.
################################################################################

# Fetch test files recursevely
file(GLOB_RECURSE ai_app_source
    "main.cpp"
    # performance_test.cpp
)

# Add test target
add_executable(ai_app ${ai_app_source})

# Link target dependencies
target_link_libraries(ai_app
    PRIVATE ai
)
