ADD_SUBDIRECTORY(components)

SET(SOURCES main.cpp)

ADD_EXECUTABLE(Main_Executable ${SOURCES})
TARGET_LINK_LIBRARIES(Main_Executable Components)