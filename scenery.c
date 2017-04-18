#include <GL/glut.h>
#include <GL/GL.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

void drawFilledSun(){
    //static float angle;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -10);
    int i, x, y;
    double radius = 0.30;
    //glColor3ub(253, 184, 19);     
    glColor3ub(255, 0, 0);
    double twicePi = 2.0 * 3.142;
    x = 0, y = 0;
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= 20; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
            );
    }
    glEnd(); //END
}

void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	/*
	//gambar pohon sederhana berbentuk panah ke atas
	glBegin(GL_POLYGON);
	
	glColor3f(0.0, 1.0, 0.0);

	glVertex2f(60,20);
	glVertex2f(80,20);
	glVertex2f(80,0);
	
	glVertex2f(120,0);
	glVertex2f(120,20);
	glVertex2f(140,20);
	
	glVertex2f(100,100);

	glEnd();
	*/


	GLfloat cx=320,cy=400,radius = 85;
	int numPoints;

	const float DegToRad = 3.14159 / 180;

  glBegin (GL_TRIANGLE_FAN);
	  int count = 1;
	  numPoints = 10;
		glColor3f((float)253/255,(float)184/255,(float)19/255);
    glVertex2f(cx, cy);
      for (int i = 0; i <= 360; i+=360/(numPoints*2)) {
        float DegInRad = i * DegToRad;
        if(count%2!=0){
        		glColor3f(1,1,1);
            glVertex2d (cx + cos (DegInRad) * (radius+radius)/2, cy + sin (DegInRad) * (radius+radius)/2);
        } else {
        		
        		glColor3f((float)253/255,(float)184/255,(float)19/255);
            glVertex2d ((cx + cos (DegInRad) * radius/2), (cy + sin (DegInRad) * radius/2));
        }	
   		 count++;
      }

  glEnd();

  radius = 75;
  glBegin (GL_TRIANGLE_FAN);
	  count = 1;
	  numPoints = 20;
		glColor3f((float)255/255,(float)102/255,0);
    glVertex2f(cx, cy);
      for (int i = 0; i <= 360; i+=360/(numPoints*2)) {
        float DegInRad = i * DegToRad;
        //if(count%2!=0){
        		// glColor3f(1,1,1);
            // glVertex2d (cx + cos (DegInRad) * radius, cy + sin (DegInRad) * radius);
        //} else {
        		
        		glColor3f((float)253/255,(float)184/255,(float)19/255);
            glVertex2d ((cx + cos (DegInRad) * radius/2), (cy + sin (DegInRad) * radius/2));
        //}	
   		 count++;
      }

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