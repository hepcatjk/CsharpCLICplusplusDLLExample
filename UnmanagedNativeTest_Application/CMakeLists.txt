include_directories(
  # Native DLL header files to include
  ${NATIVEENTITY_INCLUDE_DIR}
  )
  
SET(UnmanagedNativeTest_Application_SOURCE 
   main.cpp)
   
   
add_executable(NativeEntity_Test_Application ${UnmanagedNativeTest_Application_SOURCE})

target_link_libraries(NativeEntity_Test_Application NativeEntity)

ADD_DEPENDENCIES(NativeEntity_Test_Application NativeEntity)   