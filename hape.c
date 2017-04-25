#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

// angle of rotation for the camera direction
float angle=0.0, vangle=0.0;
// actual vector representing the camera's direction
float lx=0.0f, ly=0.0f, lz=-1.0f;
// XZ position of the camera
float x=0.0f, y=1.0f, z=5.0f;

float fraction = 0.1f;

void drawSkybox() {
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
		glVertex3f(-50.0f, -50.0f, -50.0f);
		glVertex3f(-50.0f, -50.0f,  50.0f);
		glVertex3f( 50.0f, -50.0f,  50.0f);
		glVertex3f( 50.0f, -50.0f, -50.0f);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-50.0f, 50.0f, -50.0f);
		glVertex3f(-50.0f, 50.0f,  50.0f);
		glVertex3f( 50.0f, 50.0f,  50.0f);
		glVertex3f( 50.0f, 50.0f, -50.0f);
	glEnd();
	
	glColor3f(0.9f, 0.9f, 0.0f);
	glBegin(GL_QUADS);
		glVertex3f(-50.0f, -50.0f, -50.0f);
		glVertex3f(-50.0f, -50.0f,  50.0f);
		glVertex3f(-50.0f, 50.0f,  50.0f);
		glVertex3f(-50.0f, 50.0f, -50.0f);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f( 50.0f, -50.0f, -50.0f);
		glVertex3f( 50.0f, -50.0f,  50.0f);
		glVertex3f( 50.0f, 50.0f,  50.0f);
		glVertex3f( 50.0f, 50.0f, -50.0f);
	glEnd();
	
	glColor3f(0.0f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
		glVertex3f(-50.0f, -50.0f, -50.0f);
		glVertex3f(50.0f, -50.0f,  -50.0f);
		glVertex3f( 50.0f, 50.0f,  -50.0f);
		glVertex3f( -50.0f, 50.0f, -50.0f);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-50.0f, -50.0f, 50.0f);
		glVertex3f(50.0f, -50.0f,  50.0f);
		glVertex3f( 50.0f, 50.0f,  50.0f);
		glVertex3f( -50.0f, 50.0f, 50.0f);
	glEnd();
}

void renderScene(void) {

	// Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(x, y, z,
			x+lx, y+ly,  z+lz,
			0.0f, 1.0f,  0.0f);

    // Draw skybox
	drawSkybox();
	
	glutSwapBuffers();
}

void changeSize(int w, int h) {
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int xx, int yy)
{
	switch (key) {
		case 119 : //W
		case 87  :	
			x += lx * fraction;
			z += lz * fraction;
			break;
		case 65	 : //A
		case 97	 :
			x += lz * fraction;
			z -= lx * fraction;
			break;
		case 83	 : //S
		case 115 :
			x -= lx * fraction;
			z -= lz * fraction;
			break;
		case 68 :
		case 100:
			x -= lz * fraction;
			z += lx * fraction;
			break;
		case 27  :
			exit(0);
			
	}
}

void processSpecialKeys(int key, int xx, int yy) {
	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP :
			vangle += 0.01f;
			ly = vangle;
			break;
		case GLUT_KEY_DOWN :
			vangle -= 0.01f;
			ly = vangle;
			break;
	}
}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("OpenGL");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();

	return 1;
}