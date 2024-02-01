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

<img src="/images/w1_quad.png" alt="w1_quad" width="300"/>

<p>pic</p>
<img src="/images/w1_rotate_quad.png" alt="w1_rotate_quad" width="300"/>

<h2>Part 3 - Types of Filters</h2>
<h2>Part 4 - for fun</h2>

<img src="/images/w1_sword_1.png" alt="w1_sword_1" width="300"/> 

<img src="/images/w1_sword_2.png" alt="w1_sword_2" width="300"/>

----
### hw1
## Jan/31/2024
draw.exe path/to/yourfile.svg
Follow this to setup-> https://cs184.eecs.berkeley.edu/sp24/docs/building-assignments#step0

if I click play: :[Drawer] Not enough arguments. Pass in an .svg or a directory of .svg files.

C:\Users\Magiccc\Unity_dev\hw1-rasterizer-sp24-the-cy-alliance\out\build\x64-Release\draw.exe (process 7688) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

Using an IDE (like Visual Studio):

If you're running your program in an IDE like Visual Studio, you'll need to set up the command line arguments in the project settings.
In Visual Studio, you can do this by right-clicking on your project in the **Solution Explorer**, selecting 'Properties', navigating to the 'Debugging' tab, and then entering your command line arguments in the 'Command Arguments' field.

![Screenshot 2024-01-31 202102](https://github.com/YuntingZh/CS284A/assets/100269093/9af3c005-3c2d-42e1-a4ac-a27f58d6d3f0)

You can run the executable with the command

./draw [path to svg file/folder to render]
For example, you could run this command:

./draw ../svg/basic/test1.svg
Note: For Visual Studio, the output folder is 3 layers deep. Therefore you should use ./draw ../../../svg/basic/test1.svg For Linux / Unix / Mac commandline build, it should be 1 layer deep: ./draw ../svg/basic/test1.svg **All the IDEs has some form of debug / launch settings. You can use those to specify the SVG file and then you can use the debugger provided by the IDE. Anyways, the path should always be relative to the executable file!**
I am trying to figure out how to set it up in Visual studio, but my Properties is blank T_T

![Screenshot 2024-01-31 204011](https://github.com/YuntingZh/CS284A/assets/100269093/40ceedb0-afd0-4261-a6b6-0c1ffae8cb81)
