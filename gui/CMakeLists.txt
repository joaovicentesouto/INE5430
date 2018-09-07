################################################################################
# This is the CMakeLists file for the:
#
#   ai GUI
#
# Its main goals are:
#   - Create an graphic user interface.
#
################################################################################

################################################################################
# Set flags
################################################################################

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

################################################################################
# Fetch files
################################################################################

# Fetch .cpp files for executable creation
file(GLOB_RECURSE ai_gui_source
    "*.cpp"
)

# Fetch .ui files for executable creation
file(GLOB_RECURSE ai_gui_userinterface
    "*.ui"
)

################################################################################
# GUI executable
################################################################################

# Add gui executable
add_executable( ai_gui MACOSX_BUNDLE ${ai_gui_source} ${ai_gui_userinterface} )

# Add executable dependencies
target_link_libraries(ai_gui PUBLIC
    PRIVATE Qt5::Widgets
    PRIVATE ai
)