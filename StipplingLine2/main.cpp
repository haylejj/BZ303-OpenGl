#include <GL/gl.h>
#include <GL/glaux.h>

int main(int argc, char** argv)
{
   auxInitDisplayMode (AUX_SINGLE | AUX_RGBA);
   auxInitPosition (0, 0, 500, 500);
   auxInitWindow (argv[0]);

   glClearColor (0.0, 0.0, 0.0, 0.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
   
   //koordinat sistemi çizme
   glBegin(GL_LINES);
      glVertex2f(-10, 0.0);
      glVertex2f(10.0, 0.0);
      glVertex2f(0.0,10.0);
      glVertex2f(0.0,-10.0);
   glEnd();
   
   glLineStipple(1,0x160F);
   glEnable(GL_LINE_STIPPLE);
   
   //A-B
   glColor3f(1.0,0.0,0.0);//kýrmýzý
   glLineWidth(1.0);
   glBegin(GL_LINES);
   	glVertex2f(1.0,1.0);
   	glVertex2f(1.0,3.0);
   glEnd();
   
   //B-C
   glColor3f(0.0,1.0,0.0);
   glLineWidth(2.0);
   glBegin(GL_LINES);  
    glVertex2f(1.0,3.0);
	glVertex2f(3.0,3.0);
   glEnd();
	
   //C-D	
   glColor3f(1.0,0.0,0.0);
   glLineWidth(3.0);
   glBegin(GL_LINES);
   	glVertex2f(3.0,3.0);
   	glVertex2f(3.0,1.0);
   glEnd();
   	
   //D-A
   glColor3f(0.0,1.0,0.0);
   glLineWidth(4.0);
   glBegin(GL_LINES);
   	glVertex2f(3.0,1.0);
   	glVertex2f(1.0,1.0);
   glEnd();	
      	
	
   glFlush();

   Sleep(5000);
   return 0;
}

