cmake_minimum_required(VERSION 3.14)

# include the ez submodule unitilty cmake functions
include("ezEngine/Code/BuildSystem/CMake/ezUtilsSubmodule.cmake")

ez_detect_languages()

project("ezSubmoduleExample" LANGUAGES ${EZ_LANGUAGES})

add_subdirectory(ezEngine)
add_subdirectory(HelloWorldApp)