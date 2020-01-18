#include<iostream>
#include<GL/glut.h>
#include<cmath>

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

void drawCircle(int xc,int yc,int x,int y)
{
	plot(xc+x,yc+y);
	plot(xc-x, yc+y); 
    plot(xc+x, yc-y); 
    plot(xc-x, yc-y); 
    plot(xc+y, yc+x); 
    plot(xc-y, yc+x); 
    plot(xc+y, yc-x); 
    plot(xc-y, yc-x); 
}

void drawCircle1(int xc,int yc,int x,int y)
{
	//plot(xc+x,yc+y);
	//plot(xc-x, yc+y); 
    plot(xc+x, yc-y); 
    plot(xc-x, yc-y); 
    //plot(xc+y, yc+x); 
   // plot(xc-y, yc+x); 
   // plot(xc+y, yc-x); 
   // plot(xc-y, yc-x); 
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

void circleBres1(int xc, int yc, int r) 
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
       
        drawCircle1(xc, yc, x, y); 
      
    } 
}  


void show(void) {

	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(128.0,128.0,128.0);
	
	//big circle
	
	circleBres(0,0,45);
	
	//components
	ddaLine(18,20,23,20);
	ddaLine(-18,20,-23,20);
	
	//down line
	ddaLine(-16,-22,16,-22);
	
	//teeth
	circleBres1(0,-10,22); 

	
	glPointSize(3.0);
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
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Emoji");
	init();
	glutDisplayFunc(show);
	glutMainLoop();
	
	glFlush();
	return 0;
}


