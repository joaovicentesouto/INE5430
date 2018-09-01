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
file(GLOB_RECURSE ai_test_source
    "*.cpp"
    "main.cpp"
)

# Add test target
add_executable(ai_test ${ai_test_source})

# Link target dependencies
target_link_libraries(ai_test
    PRIVATE Catch2
    PRIVATE ai
)

################################################################################
# Add test to ctest
################################################################################

enable_testing()
add_test(NAME unit_test COMMAND ai_test)
