20150815
1) F:\opengl\freeglut-3.0.0.tar\freeglut-3.0.0			Build ok

2) F:\opengl\test\ConsoleApplication2	- SDL test		Build fail --�������޸� -->build ok
>MSVCRTD.lib(exe_main.obj) : error LNK2019: �޷��������ⲿ���� _main���÷����ں��� "int __cdecl invoke_main(void)" (?invoke_main@@YAHXZ) �б�����
�������֣�sdl�����main���¶���Ϊsdl_main,������ɾ��֮��Ϳ���build�Ѿ�������


3) ������������ϲ��freeglutһЩ

4)�ο�http://blog.csdn.net/sarkuya/article/details/45067035��д��һ����򵥵�opengl����
F:\opengl\test\testglut
ֻ��Ҫ�ֶ�����freeglut_header��freeglut_lib
����Ҫֱ�Ӱ���xx��lib������ͷ�ļ����Ѿ�������ˣ�

5) ������Ҫѧϰһ����Щ����任��������ɶ
һ����reshape��������glMatrixMode�л�Ҫ�޸ĵľ���
��projection������غ���
	glFrustum
	gluPerspective
modelviuew����
	��
һ����display������glclear֮�����õ������λ�ã�
	gluLookAt(camPos, camLookAt, upper)
	
6��ѧϰ����
http://www.glprogramming.com/red/chapter03.html
	