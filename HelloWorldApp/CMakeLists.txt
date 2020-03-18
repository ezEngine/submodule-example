# create cmake target listing the source files
add_executable(HelloWorldApp HelloWorldApp.cpp)

# link against ezEngine Foundation
target_link_libraries(HelloWorldApp Foundation)

# copy the ezFoundation.dll and dependencies into the binary output directory.
# Alternatively you could:
# * Change the output location of ezEngine by setting EZ_OUTPUT_DIRECTORY_DLL
# * Change your project to output into the same location as ezEngine

# Copy ezFoundation.dll
add_custom_command(TARGET HelloWorldApp POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Foundation> $<TARGET_FILE_DIR:HelloWorldApp>/$<TARGET_FILE_NAME:Foundation>
)

if(EZ_3RDPARTY_ENET_SUPPORT)
	# copy enet.dll
	add_custom_command(TARGET HelloWorldApp POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE_DIR:Foundation>/enet.dll $<TARGET_FILE_DIR:HelloWorldApp>/enet.dll
	)
endif()

if(EZ_3RDPARTY_ZSTD_SUPPORT)
	# copy zstd.dll
	add_custom_command(TARGET HelloWorldApp POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE_DIR:Foundation>/zstd.dll $<TARGET_FILE_DIR:HelloWorldApp>/zstd.dll
	)
endif()

if(EZ_3RDPARTY_ZLIB_SUPPORT)
	# copy zlib.dll
	add_custom_command(TARGET HelloWorldApp POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE_DIR:Foundation>/zlib.dll $<TARGET_FILE_DIR:HelloWorldApp>/zlib.dll
	)
endif()

# enable c++17 support as its required by ezEngine
set_property(TARGET HelloWorldApp PROPERTY CXX_STANDARD 17)