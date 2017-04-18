#include <GL/glut.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	//gambar pohon sederhana berbentuk panah ke atas
	glBegin(GL_POLYGON);
	
	glColor3f(0.0, 1.0, 0.0);
	//glVertex2f(60,20);
	glVertex2f(80,20);
	glVertex2f(80,0);
	
	glVertex2f(120,0);
	glVertex2f(120,20);
	glVertex2f(140,20);
	
	glVertex2f(100,100);
	
	
	glEnd(); 
	glFlush();
	glutSwapBuffers();
	
	/*
	glClear(GL_COLOR_BUFFER_BIT); //glclear bersihin buffer, color buffer is color buffer
	glColor3f(1,1,0); //warna kotak di dalem
	glBegin(GL_POLYGON); 
	glVertex2f(100,300);
	glVertex2f(100,100);
	glVertex2f(200,100);
	//glVertex2f(200,300);
	glEnd(); glFlush();
	glutSwapBuffers();
	*/
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(640,640);
	glutCreateWindow("OpenGL");
	
	glutDisplayFunc(display);
	
	gluOrtho2D(0,640,0,640); //posisi window
	glClearColor(0.5,1,1,0); //warna background
	glutMainLoop();

	return 0;
}