set SDL_lib=F:\opengl\SDL2-devel-2.0.3-VC\SDL2-2.0.3\lib\x86
set SDL_header=F:\opengl\SDL2-devel-2.0.3-VC\SDL2-2.0.3\include
set glew_bin=F:\opengl\glew-1.12.0\glew-1.12.0\bin\Debug\Win32
set glew_lib=F:\opengl\glew-1.12.0\glew-1.12.0\lib\Debug\Win32
set glew_header=F:\opengl\glew-1.12.0\glew-1.12.0\include
set freeglut_header=F:\opengl\freeglut-3.0.0.tar\freeglut-3.0.0\src;F:\opengl\freeglut-3.0.0.tar\freeglut-3.0.0\include;F:\opengl\freeglut-3.0.0.tar\freeglut-3.0.0\sln
set freeglut_lib=F:\opengl\freeglut-3.0.0.tar\freeglut-3.0.0\sln\lib\Debug
set freeglut_bin=F:\opengl\freeglut-3.0.0.tar\freeglut-3.0.0\sln\bin\Debug
path %path%;%SDL_lib%;%glew_bin%;%freeglut_bin%
rem start "F:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\IDE\devenv.exe"
start cmd /c "F:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\IDE\devenv.exe"
cmd
