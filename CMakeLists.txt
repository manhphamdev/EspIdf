# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)

# Set the project name
project(main)

# Add the ESP-IDF components
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Add the common/include directory to the include paths
set(COMPONENT_ADD_INCLUDEDIRS common/include)

# Add the common directory to the list of extra components
set(EXTRA_COMPONENT_DIRS common)

# Create the project
project(${COMPONENT_NAME})