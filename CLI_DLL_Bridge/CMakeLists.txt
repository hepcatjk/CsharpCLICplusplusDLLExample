include_directories(
  # Native DLL header files to include
  ${NATIVEENTITY_INCLUDE_DIR}
  )

# Allow the developer to select if Dynamic or Static libraries are built
OPTION (BUILD_SHARED_LIBS "Build Shared Libraries" ON)
# Set the LIB_TYPE variable to STATIC
SET (LIB_TYPE STATIC)
IF (BUILD_SHARED_LIBS)
  # User wants to build Dynamic Libraries, so change the LIB_TYPE variable to CMake keyword 'SHARED'
  SET (LIB_TYPE SHARED)
ENDIF (BUILD_SHARED_LIBS)


SET(CLI_DLL_Bridge_SOURCE 
   ManagedEntity.cpp ManagedEntity.h
   AssemblyInfo.cpp)

set( FORCE_CXX ON )
add_definitions( -D_UNICODE -DUNICODE )   
   
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /clr")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHa")

#Ugly - is there a better fix to this ....
if(CMAKE_CXX_FLAGS_DEBUG MATCHES "/RTC1")
   string(REPLACE "/EHsc" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
   string(REPLACE "/RTC1" " " CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
endif()   


  
add_library(CLI_Bridge ${LIB_TYPE} ${CLI_DLL_Bridge_SOURCE})

target_link_libraries(CLI_Bridge NativeEntity)

ADD_DEPENDENCIES(CLI_Bridge NativeEntity)
STRING (REGEX REPLACE "/RTC(su|[1su])" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")   