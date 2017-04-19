#include <stdio.h>
#include <unistd.h>
#include <GL/glut.h>
#include <GL/GL.h>
#include <math.h>

const float DegToRad = 3.14159 / 180;

void drawCircle(int r1, int g1, int b1, int a1, int r2, int g2, int b2, int a2, int radii, int x, int y, int edges) {
	int radius = radii;
	int cx = x;
	int cy = y;
	int numPoints = edges;
	
	glBegin (GL_TRIANGLE_FAN);
	//int count = 1;
	
	glColor4f((float)r1/255,(float)g1/255,(float)b1/255, (float)a1/255);

    glVertex2f(cx, cy);
	
	for (int i = 0; i <= 360; i+=360/(numPoints*2)) {
        float DegInRad = i * DegToRad;

		glColor4f((float)r2/255,(float)g2/255,(float)b2/255, (float)a2/255);
		glVertex2d ((cx + cos (DegInRad) * radius/2), (cy + sin (DegInRad) * radius/2));
    }

	glEnd();
}

void drawTree() {
	//draw stem
	glBegin(GL_QUADS);
	glColor3f((float)178/255, (float)34/255, (float)34/255);
	glVertex2f(98, 0);
	glVertex2f(108, 0);
	glVertex2f(108, 100);
	glVertex2f(98, 100);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f((float)178/255, (float)34/255, (float)34/255);
	glVertex2f(498, 0);
	glVertex2f(508, 0);
	glVertex2f(508, 100);
	glVertex2f(498, 100);
	glEnd();
	
	//draw leaves
	drawCircle(0, 255, 0, 255, 0, 40, 0, 255, 30, 80, 45, 20);
	drawCircle(0, 255, 0, 255, 0, 40, 0, 255, 100, 100, 100, 20);
	drawCircle(0, 255, 0, 255, 0, 40, 0, 255, 50, 140, 60, 20);
	
	drawCircle(0, 255, 0, 255, 0, 40, 0, 255, 30, 480, 45, 20);
	drawCircle(0, 255, 0, 255, 0, 40, 0, 255, 100, 500, 100, 20);
	drawCircle(0, 255, 0, 255, 0, 40, 0, 255, 50, 540, 60, 20);
}

void drawMountains() {
	
	//draw mountain 2
	glBegin(GL_TRIANGLES);
	glColor3d(0,1,0);
	glVertex2f(640,0);
	glVertex2f(-40,0);
	glVertex2f(640,300);
	glEnd();
	
	//drawMountain Shadow
	glBegin(GL_TRIANGLES);
	glColor4d(0,0,0,1);
	glVertex2f(0,0);
	glColor4d(1,1,1,0);
	glVertex2f(1000,0);
	glVertex2f(0,130);
	glEnd();
	
	//draw mountain 1
	glBegin(GL_TRIANGLES);
	glColor3d(0,1,0);
	glVertex2f(0,0);
	glVertex2f(400,0);
	glVertex2f(0,100);
	glEnd();
}

void washColor(int radii, int x, int y) {
	drawCircle(255,255,255,255, 255,255,255,0, radii,x,y,20);
	drawCircle(255,255,255,255, 255,255,255,0, radii,x,y,20);
	drawCircle(255,255,255,255, 255,255,255,0, radii,x,y,20);
	drawCircle(255,255,255,255, 255,255,255,0, radii,x,y,20);
	drawCircle(255,255,255,255, 255,255,255,0, radii,x,y,20);
	drawCircle(255,255,255,255, 255,255,255,0, radii,x,y,20);
	drawCircle(255,255,255,255, 255,255,255,0, radii,x,y,20);
}

void drawRainbow() {
	//sky
	drawCircle(255,255,255,255, 127,255,255,255, 2000, -40,-40,20);
	
	//red
	drawCircle(255,0,0,255, 255,0,0,0, 1000,-40,-40,20);
	washColor(950, -40, -40);
	
	//orange
	drawCircle(255,99,71,255, 255,99,71,0, 950,-40,-40,20);
	washColor(900, -40, -40);
	
	//yellow
	drawCircle(255,255,0,255, 255,255,0,0, 900,-40,-40,20);
	washColor(850, -40, -40);
	
	//green
	drawCircle(0,255,0,255, 0,255,0,0, 850,-40,-40,20);
	washColor(800, -40, -40);
	
	//blue
	drawCircle(0,0,255,255, 0,0,255,0, 800,-40,-40,20);
	washColor(750, -40, -40);
	
	//indigo
	drawCircle(127,0,255,255, 127,0,255,0, 750,-40,-40,20);
	washColor(700, -40, -40);
	
	//purple
	drawCircle(255,0,255,255, 255,0,255,0, 700,-40,-40,20);
	washColor(650, -40, -40);
	
}


void drawFilledSun(){
    //draw spikes
	
	//draw circle
}

void drawMountains(){
	//gambar gunung1
	glBegin(GL_POLYGON);
	
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(400,0);
	float w=640.0;
	float y=0.0;
	for(float x=0.0;-x*x/100+4*x>=0;x++) {
		y=-x*x/100+4*x;
		if(x>w/4-10) glColor3f(0.83, 1.0, 0.47);
		else glColor3f(0.0, 1.0, 0.0);
		glVertex2f(x,y);
	}
	
	glEnd();
	
	//gambargunung2
	glBegin(GL_POLYGON);
	
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(320,0);
	for(float x=0.0;-x*x/80+4*x>=0;x++) {
		y=-x*x/80+4*x;
		if(x<w/4+10) glColor3f(0.83, 1.0, 0.47);
		else glColor3f(0.15, 1.0, 0.15);
		glVertex2f(x+w/2,y);
	}
	
	glEnd();
}

void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GLfloat cx=500,cy=500,radius = 85;
	int numPoints;
	int count = 1;

	
	//rainbow
	drawRainbow();
	
	drawCircle(253, 184, 19, 255, 253, 184, 19, 0, 300, 500, 500, 20);
	
	//gambar spike di sekitar matahari
	glBegin (GL_TRIANGLE_FAN);
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
	
	
	//gambar lingkaran matahari
	drawCircle(255, 102, 0, 255, 253, 184, 19, 255, 75, 500, 500, 20);
	
	
	//drawMountains
	drawMountains();
	
	//draw tree
	drawTree();
	
	//draw gunung
	drawMountains();
	/*
	radius = 75;
	glBegin (GL_TRIANGLE_FAN);
	count = 1;
	numPoints = 20;
	glColor3f((float)255/255,(float)102/255,0);

    glVertex2f(cx, cy);
	
	for (int i = 0; i <= 360; i+=360/(numPoints*2)) {
        float DegInRad = i * DegToRad;

		glColor3f((float)253/255,(float)184/255,(float)19/255);
		glVertex2d ((cx + cos (DegInRad) * radius/2), (cy + sin (DegInRad) * radius/2));

		count++;
    }

	glEnd();
	*/
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
