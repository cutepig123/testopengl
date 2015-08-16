
#include <GL/freeglut.h>

namespace {

	const int checkimagewidth = 64;
	const int checkimageheigh= 64;

	GLubyte checkimage[checkimagewidth][checkimageheigh][4];
	GLuint texName;

	void makecheckimage()
	{
		for (size_t i = 0; i < checkimageheigh; i++)
		{
			for (int j = 0; j < checkimagewidth; j++)
			{
				int c = (((i & 8) == 0) ^ ((j & 8) == 0)) * 255;
				checkimage[i][j][0] = checkimage[i][j][1] = checkimage[i][j][2] = c;
				checkimage[i][j][3] = 255;
			}
		}
	}
	void init()
	{
		glClearColor(0.5, 0, 0, 0);	//必须的，设置glClear采用的背景色
		glShadeModel(GL_FLAT);
		glEnable(GL_DEPTH_TEST);
		makecheckimage();
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);	//?

		glGenTextures(1, &texName);
		glBindTexture(GL_TEXTURE_2D, texName);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	//?
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);	//?
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);	//?
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);	//?
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkimagewidth, checkimageheigh, 0, GL_RGBA, GL_UNSIGNED_BYTE, checkimage);
	}

	GLfloat atex_vertexcoords[][5] = { {0,0,	-2,-1,0,},
	{0,1,	-2,1,0,},
	{ 1,1,	0,1,0, },
	{ 1,0,	0,-1,0, },

	{ 0,0,	1,-1,0, },
	{ 0,1,	1,1,0, },
	{ 1,1,	2.414,1,-1.414, },
	{ 1,0,	2.414,-1,-1.414, },
	};
	void display() {
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);	//必须
		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);	//?
		glBindTexture(GL_TEXTURE_2D, texName);
		glBegin(GL_QUADS);

		for (size_t i = 0; i < sizeof(atex_vertexcoords)/ sizeof(atex_vertexcoords[0]); i++)
		{
			glTexCoord2f(atex_vertexcoords[i][0], atex_vertexcoords[i][1]);
			glVertex3f(atex_vertexcoords[i][2], atex_vertexcoords[i][3], atex_vertexcoords[i][4]);
		}
		glEnd();
		glFlush();
		glDisable(GL_TEXTURE_2D);
	}

	/*void spinDisplay()
	{
		spin += 2;
		if (spin > 360)
			spin -= 360;
		glutPostRedisplay();
	}*/

	void reshape(int w, int h)
	{
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60, (GLfloat)w / h, 1, 30);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(0, 0, -3.6);
	}

	//void mouse(int button, int state, int x, int y)
	//{
	//	switch (button)
	//	{
	//	case GLUT_LEFT_BUTTON:
	//		if (state == GLUT_DOWN)
	//			//glutIdleFunc(spinDisplay);
	//			spinDisplay();
	//		break;
	//	case GLUT_RIGHT_BUTTON:
	//		if (state == GLUT_DOWN)
	//			glutIdleFunc(NULL);
	//		break;
	//	default:
	//		break;
	//	}
	//}

}

int ttexture(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_RGB);
	glutInitWindowSize(250, 250);

	glutCreateWindow("Freeglut Hello World");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutMouseFunc(mouse);

	glutMainLoop();
	return 0;
}