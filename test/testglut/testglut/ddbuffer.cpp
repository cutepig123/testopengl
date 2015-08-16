
#include <GL/freeglut.h>

namespace {

	static GLfloat spin = 0;
	// test 顶点数组
	GLint vertices[] = {25,25,
	100,325,
	175,25,
	175,325,
	250,25,
	325,325};

	GLfloat colors[] = {
		1, .2, .2,
		.2,.2,1,
		.8,1,.2,
		.75,.75,.75,
		.35,.35,.35,
		.5,.5,.5,
	};

	GLubyte allIndices[] = { 4,5,6,7,1,2,6,5,
	0,1,5,4,0,3,2,1,
	0,4,7,3,2,3,7,6 };


	void init()
	{
		glClearColor(0.5, 0, 0, 0);	//必须的，设置glClear采用的背景色
		glShadeModel(GL_FLAT);

		// 设置顶点数组
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glColorPointer(3, GL_FLOAT, 0, colors);
		glVertexPointer(2, GL_INT, 0, vertices);
	}

	void display() {
		glClear(GL_COLOR_BUFFER_BIT);	//必须
		//glPushMatrix();
		glLoadIdentity();
		glRotatef(spin, 0, 0, 1);
		glColor3f(0, 1, 1);

		glRectf(-25, -25, 25, 25);
		//glPopMatrix();

		//glLoadIdentity();
		glColor3f(0, 0, 1);
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(0, 10);
		glVertex2f(20, 10);
		glVertex2f(30, 20);
		glVertex2f(20, 0);
		glEnd();

		if (0)
		{
			glBegin(GL_TRIANGLES);
			glArrayElement(2);
			glArrayElement(3);
			glArrayElement(5);
			glEnd();
		}
		else
		{
			glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, allIndices);
		}
		

		glutSwapBuffers();
	}

	void spinDisplay()
	{
		spin += 2;
		if (spin > 360)
			spin -= 360;
		glutPostRedisplay();
	}

	void reshape(int w, int h)
	{
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-350, 350, -350, 350, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void mouse(int button, int state, int x, int y)
	{
		switch (button)
		{
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN)
				//glutIdleFunc(spinDisplay);
				spinDisplay();
			break;
		case GLUT_RIGHT_BUTTON:
			if (state == GLUT_DOWN)
				glutIdleFunc(NULL);
			break;
		default:
			break;
		}
	}

}

int ddbuffer(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(250, 250);

	glutCreateWindow("Freeglut Hello World");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);

	glutMainLoop();
	return 0;
}