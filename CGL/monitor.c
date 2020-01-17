#include <iostream>
#include <GL/glut.h>

void plot(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void ddaLine(float x1, float y1, float x2, float y2)
{
	float dx = x2-x1 , dy = y2-y1, xin, yin, step, x=x1, y=y1;
	if(abs(dy)>abs(dx))
		step = abs(dy);
	else
		step = abs(dx);
	xin = (dx/step);
	yin = (dy/step);
	for(int i=0;i<=step;i++,x+=xin,y+=yin)
		plot(x,y);
}

void drawCircle(int xc, int yc, int x, int y) 
{ 
    plot(xc+x, yc+y); 
    plot(xc-x, yc+y); 
    plot(xc+x, yc-y); 
    plot(xc-x, yc-y); 
    plot(xc+y, yc+x); 
    plot(xc-y, yc+x); 
    plot(xc+y, yc-x); 
    plot(xc-y, yc-x); 
} 
  

void circleBres(int xc, int yc, int r) 
{ 
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawCircle(xc, yc, x, y); 
    while (y >= x) 
    { 
        
        x++; 
  
       
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
        drawCircle(xc, yc, x, y); 
      
    } 
} 


void show(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(	128.0, 128.0, 128.0);
	//inner rectangle
	ddaLine(50, 40,-50, 40);
	ddaLine(-50, 40, -50, -40);
	ddaLine(-50, -40, 50, -40);
	ddaLine(50, -40, 50, 40);
	
	//outer rectangle
	ddaLine(55, 45,-55, 45);
	ddaLine(-55, 45, -55, -45);
	ddaLine(-55,-45,-20,-45);
	ddaLine(20,-45,55,-45);
	ddaLine(55, -45, 55, 45);
	//inclined line
	ddaLine(-20,-45,-30,-55);
	ddaLine(20,-45,30,-55);
	
	//base Line
	ddaLine(-30,-55,30,-55);
	
	//scenery
	ddaLine(-20,-40,-20,-10);
	ddaLine(20,-40,20,-10);
	ddaLine(-20,-10,20,-10);
	
	//top
	ddaLine(-20,-10,0,10);
	ddaLine(20,-10,0,10);
	
	//door
	ddaLine(-8,-40,-8,-23);
	ddaLine(8,-40,8,-23);
	ddaLine(-8,-23,8,-23);
	ddaLine(0,-40,0,-23);
	
	//sun
	circleBres(-25,25,7);
	
	glPointSize(2.0);
	glFlush();
}

void init(void)
{
	glClearColor(0.7,0.7,0.7,0.7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-150,150,-150,150);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (0,0);
	glutCreateWindow ("Line assignment No1");
	init();
	glutDisplayFunc(show);
	glutMainLoop();

	
	glFlush();
	return 0;
}
