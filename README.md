# windows_tests
Test implementations

Start VS Code from the Developer Command Prompt for Visual Studio, in order to have the proper environment variables set


I get the following error with G++ when trying to configure a build task:
    Starting build...
    Build finished with errors(s).
    Command failed: C:\mingw\bin\g++.exe C:\Users\sebal\Documents\repos\windows_tests\infrastructure\state_machine\src\state_machine.cpp C:\Users\sebal\Documents\repos\windows_tests\infrastructure\helloworld.cpp -o C:\Users\sebal\Documents\repos\windows_tests\build\state_machine.exe

    The terminal process failed to launch (exit code: -1).

    Terminal will be reused by tasks, press any key to close it.
But when I run the command directly with powershell, it works:
C:\mingw\bin\g++.exe C:\Users\sebal\Documents\repos\windows_tests\infrastructure\state_machine\src\state_machine.cpp C:\Users\sebal\Documents\repos\windows_tests\infrastructure\helloworld.cpp -o C:\Users\sebal\Documents\repos\windows_tests\build\state_machine.exe

Current solution:
Build directly with gcc, not using VS code

Issue with state machine:
- cannot add object in map 
- abstract class cannot be used every where
==> cannot declare field 'std::pair<const state_list, Cstate>::second' to be of abstract type 'Cstate'
