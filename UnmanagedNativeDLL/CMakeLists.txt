# Allow the developer to select if Dynamic or Static libraries are built
OPTION (BUILD_SHARED_LIBS "Build Shared Libraries" ON)
# Set the LIB_TYPE variable to STATIC
SET (LIB_TYPE STATIC)
IF (BUILD_SHARED_LIBS)
  # User wants to build Dynamic Libraries, so change the LIB_TYPE variable to CMake keyword 'SHARED'
  SET (LIB_TYPE SHARED)
ENDIF (BUILD_SHARED_LIBS)

add_definitions(-DEXAMPLEUNMANAGEDDLL_EXPORTS)

SET(UnmanagedDLL_SOURCE 
   NativeEntity.cpp NativeEntity.h
   TestClassCallers.cpp TestClassCallers.h
   )

add_library(NativeEntity ${LIB_TYPE} ${UnmanagedDLL_SOURCE})

