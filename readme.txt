20150815
1) F:\opengl\freeglut-3.0.0.tar\freeglut-3.0.0			Build ok

2) F:\opengl\test\ConsoleApplication2	- SDL test		Build fail --》经过修改 -->build ok
>MSVCRTD.lib(exe_main.obj) : error LNK2019: 无法解析的外部符号 _main，该符号在函数 "int __cdecl invoke_main(void)" (?invoke_main@@YAHXZ) 中被引用
后来发现，sdl里面把main重新定义为sdl_main,俺把它删了之后就可以build已经运行了


3) 看起来俺还是喜欢freeglut一些

4)参考http://blog.csdn.net/sarkuya/article/details/45067035编写了一个最简单的opengl程序
F:\opengl\test\testglut
只需要手动加入freeglut_header，freeglut_lib
不需要直接包含xx。lib（她的头文件里已经处理好了）

5) 看来需要学习一下这些矩阵变换到底做了啥
一般在reshape函数，用glMatrixMode切换要修改的矩阵
如projection矩阵，相关函数
	glFrustum
	gluPerspective
modelviuew矩阵
	？
一般在display函数，glclear之后设置的是相机位置？
	gluLookAt(camPos, camLookAt, upper)
	
6）学习资料
http://www.glprogramming.com/red/chapter03.html
	