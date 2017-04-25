#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// angle of rotation for the camera direction
float angle=0.0, vangle=0.0;
// actual vector representing the camera's direction
float lx=0.0f, ly=0.0f, lz=-1.0f;
// XZ position of the camera
float x=0.0f, y=1.0f, z=5.0f;

float fraction = 0.1f;

GLuint texture;

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



GLuint LoadTexture( const char * filename )
{

  GLuint texture;

  int width, height;

  unsigned char * data;

  FILE * file;

  file = fopen( filename, "rb" );

  if ( file == NULL ) return 0;
  width = 1024;
  height = 512;
  data = (unsigned char *)malloc( width * height * 3 );
  //int size = fseek(file,);
  fread( data, width * height * 3, 1, file );
  fclose( file );

 for(int i = 0; i < width * height ; ++i)
	{
	   int index = i*3;
	   unsigned char B,R;
	   B = data[index];
	   R = data[index+2];

	   data[index] = R;
	   data[index+2] = B;

	}


	glGenTextures( 1, &texture );
	glBindTexture( GL_TEXTURE_2D, texture );
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );


	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
	gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
	free( data );

	return texture;
}

void drawHape() {
	 glEnable(GL_TEXTURE_2D);
	 
	glColor3f(0.0f, 0.0f, 0.0f);
	glBindTexture(GL_TEXTURE_2D, texture);
	/*
	glBegin(GL_QUADS);
		glTexCoord2f(0,0);
		glVertex3f(-6.0f, 10.0f, -20.0f);
		glTexCoord2f(1,0);
		glVertex3f(6.0f, 10.0f, -20.0f);
		glTexCoord2f(1,1);
		glVertex3f(6.0f, -10.0f, -20.0f);
		glTexCoord2f(0,1);
		glVertex3f(-6.0f, -10.0f, -20.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D); */
	
// Right
double c[] = {-6.0, 10.0, -20.0};
double b[] = {6.0f, 10.0f, -20.0f};
double f[] = {6.0f, -10.0f, -20.0f};
double g[] = {-6.0f, -10.0f, -20.0f};

glBegin(GL_QUADS);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glNormal3d(1, 0, 0);
glTexCoord2f(0, 1);
glVertex3dv(c);
glTexCoord2f(0, 0);
glVertex3dv(b);
glTexCoord2f(1, 0);
glVertex3dv(f);
glTexCoord2f(1, 1);
glVertex3dv(g);
glEnd();

glDisable(GL_TEXTURE_2D); 
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
	
	// Draw hape
	drawHape();
	
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
	texture = LoadTexture("android.bmp");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();

	return 1;
}