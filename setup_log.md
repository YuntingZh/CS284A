## Jan/18/2024
WID: Clone hw0, use Visual Studio. Set up code environment for my machine.
----
Install Vcpkg
Open a PowerShell / CMD / Git Bash in the folder：..\Documents\CS284A
Vcpkg is a package management software that downloads and builds the required software dependencies
-> git clone https://github.com/microsoft/vcpkg
-> cd vcpkg 
-> .\bootstrap-vcpkg.bat
After vcpkg is installed, install the dependency of this project
On 64-bit system (most systems today) 
->.\vcpkg.exe install freetype:x64-windows
<!--vcpkg package management program version 2024-01-11-710a3116bbd615864eef5f9010af178034cb9b44-->
----
Go to visual studio installer - Modify- Look for "Desktop development with C++
(For CMake support, make sure the "C++ CMake tools for Windows" and any other relevant CMake components are selected.)
- CMakeLists.txt, and then click "CMake Settings for Assignment1" no opt for Assignment1
- CMake toolchain file： C:\Users\Magiccc\Documents\CS284A\vcpkg\scripts\buildsystems\vcpkg.cmake
<!--我遇到一个问题就是我的build里没有build all 选项，原因在我的CMake setting里左侧configurations里不光有x64-Release，还加了一个x64-Debug，删除之后就能正常的build all了：）-->
- Set quad_test.cpp as Startup Item 
- Run the Project: To run the project, you can press F5 or go to Debug > Start Debugging. This will start the application with the debugger attached.
If you want to run the project without the debugger, you can press Ctrl + F5 or go to Debug > Start Without Debugging.
(got error message when set the wrong main file - unable to start program C:\Users\..\hw0\build\x64-Release\CGL\src\CGL.lib s not a valid Win32 application)
- i can see a window pop up with a rectangle with a brick texture.
part 2 done! 
![w1_quad](../images/w1_quad.png) 
->
pic ![w1_rotate_quad](../images/w1_rotate_quad.png)
Part 3 - Types of Filters
Part 4 - for fun
![w1_sword_1](../images/w1_sword_1.png) 
![w1_sword_2](../images/w1_sword_2.png)
