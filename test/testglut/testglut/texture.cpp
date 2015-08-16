
#include <GL/freeglut.h>

namespace {

	const int checkimagewidth = 255;
	const int checkimageheigh= 255;

	GLubyte checkimage[checkimagewidth][checkimageheigh][4];
	GLuint texName;
	int spin = 0;

	void makecheckimage()
	{
		for (size_t i = 0; i < checkimageheigh; i++)
		{
			for (int j = 0; j < checkimagewidth; j++)
			{
				checkimage[i][j][0] = (3*i)%255;
				checkimage[i][j][1] = (3 * j) % 255;
				checkimage[i][j][2] = (2*(i+j)) % 255;
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

		//设置相机位置？
		//glLoadIdentity();	//有了这一句显示完全不正常了，为啥？
		//glRotatef(spin, 0, -3, 1);

		if (0)
		{
			glLoadIdentity();
			GLfloat camPos[] = { 0,0,5 };
			GLfloat camLookAtPos[] = { 0,0,0 };
			GLfloat upper[] = { 0,1,0 };
			gluLookAt(camPos[0], camPos[1], camPos[2],
				camLookAtPos[0], camLookAtPos[1], camLookAtPos[2],
				upper[0], upper[1], upper[2]);

			glutWireCube(1);
		}

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
		gluPerspective(60, (GLfloat)w / h, 1, 30);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(0, 0, -3.6);
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