# CsharpCLICplusplusDLLExample

This is a rough example how to call some legacy C\+\+ classes into a C\# project using [Common Language Infrastructure (CLI)](https://en.wikipedia.org/wiki/Common_Language_Infrastructure). This is important if you wanted to mix legacy C\+\+ (or just intrested in performance) and C\#. Three quick examples : a decent GUI (and did not want to use Qt), for the Unity Game Engine, and to create some plug-ins ([Rhinoceros](https://www.rhino3d.com/)).

I built this example based (heavily) on the following examples:
- [How to Marshal a C++ Class - (Code Project)](https://www.codeproject.com/articles/18032/how-to-marshal-a-c-class?)
- [Passing a vector/array from unmanaged C++ to C#](http://stackoverflow.com/questions/31417688/passing-a-vector-array-from-unmanaged-c-to-c-sharp)

Generating a C\# Project in C\+\+ uses this resource (hacky but did work):
[Generate C# project using CMake](http://stackoverflow.com/questions/2074144/generate-c-sharp-project-using-cmake) ... because this is a great example why you just want to include or create a C\# project inside another project (Since the DLLs are not platform independent).

*This is rough draft* : comments welcomed and encouraged 

## Code Setup
The project contains four projects
- **UnmanagedNativeDLL (NativeEntity)** - This project creates a native DLL. This project only has simple *sets* and *gets* for five basic types: double, int, char*, std:string, and std::vector. (This is designed as a toy example on purpose).
- **UnmanagedNativeTest_Application (NativeEntity_Test_Application)** - This project tests (1) - the NativeEntity C\+\+ DLL in C\+\+. The project checks the DLL works before attempting to transfer data and the DLL itself contains no (blantant) errors.
- **CLI_DLL_BRIDGE (CLI_Bridge)** - This project creates the CLI DLL managed wrapper (using [CLR](http://stackoverflow.com/questions/480752/clr-and-cli-what-is-the-difference)). This wrapper interacts with the unmanged NativeEntity code (1) and manages everything for C\#.
- **Csharp_Test_Application (C\#)** - This is the real main program to run and test (right click the project and set it as the "Startup Project"). This calls the managed CLR DLL wrapper bridge. The program creates a bunch of local variables, tests the Native DLL variables (which should be different), sets the local variables to the Native values (and test), changes the local values to a different value, and sets the remote values to the new values (and tests).

*Note:* the C\# - [CMAKE](https://cmake.org/) interface is choppy at best. I had to modify the csproj.template file to get the paths I wanted, x64 bit default, and include in the greater CMAKE Visual Studio project (see the above link).

## Is this the best Approach?
No idea :) This is why I created this project. Warning up front.
But this is why I created this example:
- To provide a simple, clean, and complete example (something oddly lacking)
- Solicit feedback from the greater community