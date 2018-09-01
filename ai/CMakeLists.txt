################################################################################
# This is the CMakeLists file for the:
#
#   namespace ai::formal_devices
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
set(ai_install_include_dir 
    ${ai_install_include_dir}/ai/
)

################################################################################
# Fetch files
################################################################################

# Fetch .ccp files for library creation
file(GLOB ai_source
    "*.cpp"
)

# Fetch .h files for library creation
file(GLOB ai_headers
    "*.h"
)

################################################################################
# Library target
################################################################################

# Add library target
add_library(ai SHARED ${ai_source})

# Set shared library version, this will make cmake create a link
set_target_properties(ai PROPERTIES
    VERSION ${ai_VERSION}
    SOVERSION ${ai_VERSION}
)

# Tell cmake target's dependencies
#target_link_libraries(ai_components
#    PRIVATE 
#)

# Tell cmake the path to look for include files for this target
# This is transitive, so any targets linked with this one will
# search for headers in the respective paths
target_include_directories(ai PUBLIC
    $<BUILD_INTERFACE:${ai_source_dir}>
    $<INSTALL_INTERFACE:include>
)

# Add library target
# add_library(ai_static STATIC ${ai_source})

# Tell cmake target's dependencies
#target_link_libraries(ai_static
#)

# Tell cmake the path to look for include files for this target
# This is transitive, so any targets linked with this one will
# search for headers in the respective paths
# target_include_directories(ai_static PUBLIC
#    $<BUILD_INTERFACE:${ai_source_dir}>
#    $<INSTALL_INTERFACE:include>
# )