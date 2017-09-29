SET(GRAPHICS_SOURCES IsometricMapSprite.cpp IsometricMapSprite.hpp utils/utils.hpp)

SET(GRAPHICS_LIB IIH_Graphics)

ADD_LIBRARY(${GRAPHICS_LIB} ${GRAPHICS_SOURCES})