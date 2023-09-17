# windows_tests
Test implementations

Start VS Code from the Developer Command Prompt for Visual Studio, in order to have the proper environment variables set
Windows: don t forget to add mingw, CC and CXX to your PATH in order to avoid having issues with shared libraries/cmake (DLL)

Running the code directly from the command line (call the compiler, might need additional source links)
 C:/mingw/bin/g++.exe C:/Users/sebal/Documents/repos/windows_tests/infrastructure/state_machine/src/state_machine.cpp C:/Users/sebal/Documents/repos/windows_tests/infrastructure/state_machine/src/state_run.cpp C:/Users/sebal/Documents/repos/windows_tests/infrastructure/state_machine/src/state_init.cpp C:/Users/sebal/Documents/repos/windows_tests/infrastructure/helloworld.cpp -o C:/Users/sebal/Documents/repos/windows_tests/build/state_machine.exe

Also possible to build with CMake, but Visual Studio has to be installed to configure the CMake folder. CMake tries at some point to call NMake which is only 
provided in:
    - Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx64\x86\nmake.exe

Once cmake and Visual Studio are installed, follow these steps:
  - Start a x86 Native Tools Command Prompt for VS 2019 from the root of the repository
  - mkdir build_cmake
  - cd build_cmake
  - cmake .. 
  - cmake --build .
  - .\windows.exe

[When running the program](sebaleme.github.com/windows_tests/illustrations/results.jpg)

http://halpernwightsoftware.com/stdlib-scratch/exercises.html

Usefull:
anmeldeinformationsverwaltung
