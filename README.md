# windows_tests
Test implementations

Start VS Code from the Developer Command Prompt for Visual Studio, in order to have the proper environment variables set


I get the following error with G++:
    Starting build...
    Build finished with errors(s).
    Command failed: C:\mingw\bin\g++.exe C:\Users\sebal\Documents\repos\windows_tests\infrastructure\state_machine\src\state_machine.cpp C:\Users\sebal\Documents\repos\windows_tests\infrastructure\helloworld.cpp -o C:\Users\sebal\Documents\repos\windows_tests\build\state_machine.exe

    The terminal process failed to launch (exit code: -1).

    Terminal will be reused by tasks, press any key to close it.
But when I run the command directly with powershell, it works:
C:\mingw\bin\g++.exe C:\Users\sebal\Documents\repos\windows_tests\infrastructure\state_machine\src\state_machine.cpp C:\Users\sebal\Documents\repos\windows_tests\infrastructure\helloworld.cpp -o C:\Users\sebal\Documents\repos\windows_tests\build\state_machine.exe