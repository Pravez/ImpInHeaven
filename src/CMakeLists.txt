set(SOURCES Main.cpp screen/Screen.cpp graphics/Map.cpp graphics/Tile.cpp tools/Vector.hpp graphics/Camera.cpp graphics/Camera.hpp)

add_executable(Game ${SOURCES})

IF (WIN32)
	set(LIBS ${PROJECT_SOURCE_DIR}/lib/SDL2/x64/SDL2.lib ${PROJECT_SOURCE_DIR}/lib/SDL2/x64/SDL2main.lib ${PROJECT_SOURCE_DIR}/lib/SDL2_image/x64/SDL2_image.lib)
	SET(SDL2_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include/SDL2 ${PROJECT_SOURCE_DIR}/include/SDL2_image)

	add_custom_command(TARGET Game POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/lib/SDL2/x64/SDL2.dll"
        $<TARGET_FILE_DIR:Game>)
	add_custom_command(TARGET Game POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/lib/SDL2_image/x64/SDL2_image.dll"
    $<TARGET_FILE_DIR:Game>)
	add_custom_command(TARGET Game POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/lib/SDL2_image/x64/libjpeg-9.dll"
    $<TARGET_FILE_DIR:Game>)
ELSE()
	INCLUDE(FindPkgConfig)
	PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
	PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
	set(LIBS SDL2 SDL2main SDL2_image)
ENDIF()

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})

TARGET_LINK_LIBRARIES(Game ${LIBS})

INSTALL(TARGETS Game DESTINATION bin/)

add_custom_target(copy-runtime-files ALL
    COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:Game>/resources)
	