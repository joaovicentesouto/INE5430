################################################################################
# This is the CMakeLists file for the minimax' tests directory.
#
################################################################################

# Fetch test files recursevely
file(GLOB_RECURSE minimax_tests_source
    "*.cpp"
    "main.cpp"
)

# Add test target
add_executable(minimax_tests ${minimax_tests_source})

# target_link_libraries(minimax_tests
#     PRIVATE minimax_components
#     PRIVATE minimax_devices
# )

# message("Creating symlink for test files")
# execute_process(
#     COMMAND ln -f -s ${PROJECT_SOURCE_DIR}/tests/files ${PROJECT_BINARY_DIR}/tests/.
#     RESULT_VARIABLE result
# )


################################################################################
# Add test to ctest
################################################################################

enable_testing()
add_test(NAME unit_test COMMAND minimax_tests)