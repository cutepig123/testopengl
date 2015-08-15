
#include <GL/freeglut.h>

namespace {

	static GLfloat spin = 0;

	void init()
	{
		glClearColor(0.5, 0, 0, 0);	//必须的，设置glClear采用的背景色
		glShadeModel(GL_FLAT);
	}

	void display() {
		glClear(GL_COLOR_BUFFER_BIT);	//必须
		//glPushMatrix();
		glLoadIdentity();
		glRotatef(spin, 0, 0, 1);
		glColor3f(0, 1, 1);
		glRectf(-25, -25, 25, 25);
		//glPopMatrix();

		glLoadIdentity();
		glColor3f(0, 0, 1);
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(0, 10);
		glVertex2f(20, 10);
		glVertex2f(30, 20);
		glVertex2f(20, 0);
		glEnd();

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
		glOrtho(-50, 50, -50, 50, -1, 1);
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