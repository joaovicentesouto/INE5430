################################################################################
# This is the CMakeLists file for the:
#
#   namespace minimax::formal_devices
#
# Its main goals are:
#   - Fetch library files.
#   - Add target.
#       `- Set target_include_path.
#       `- Set target_link_libraries.
#       `- Set target_compiler_options.
#   - Define installation parameters.
#       `- Install targets.
#       `- Install headers.
#
################################################################################

################################################################################
# Set variables
################################################################################

# Set the include path for installed target
set(minimax_install_include_dir 
    ${minimax_install_include_dir}/minimax/
)

################################################################################
# Fetch files
################################################################################

# Fetch .ccp files for library creation
file(GLOB minimax_source
    "*.cpp"
)

# Fetch .h files for library creation
file(GLOB minimax_headers
    "*.h"
)

################################################################################
# Library target
################################################################################

# Add library target
add_library(minimax SHARED ${minimax_source})

# Set shared library version, this will make cmake create a link
set_target_properties(minimax PROPERTIES
    VERSION ${minimax_VERSION}
    SOVERSION ${minimax_VERSION}
)

# Tell cmake target's dependencies
#target_link_libraries(minimax_components
#    PRIVATE 
#)

# Tell cmake the path to look for include files for this target
# This is transitive, so any targets linked with this one will
# search for headers in the respective paths
target_include_directories(minimax PUBLIC
    $<BUILD_INTERFACE:${minimax_source_dir}>
    $<INSTALL_INTERFACE:include>
)

# Add library target
# add_library(minimax_static STATIC ${minimax_source})

# Tell cmake target's dependencies
#target_link_libraries(minimax_static
#)

# Tell cmake the path to look for include files for this target
# This is transitive, so any targets linked with this one will
# search for headers in the respective paths
# target_include_directories(minimax_static PUBLIC
#    $<BUILD_INTERFACE:${minimax_source_dir}>
#    $<INSTALL_INTERFACE:include>
# )