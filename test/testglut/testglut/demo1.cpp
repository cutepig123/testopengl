// testglut.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <GL/freeglut.h>

static
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}

int demo1(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Freeglut Hello World");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

