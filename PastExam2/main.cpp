#include <GL/gl.h>
#include <GL/glaux.h>
#include <math.h>

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
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
   
   glEnable(GL_LINE_STIPPLE);
   glLineStipple(1,0xF0F0);
   glBegin(GL_LINES);
      glVertex2f(-10.0,0.0);
      glVertex2f(10.0,0.0);
      glVertex2f(0.0,-10.0);
      glVertex2f(0.0,10.0);
   glEnd();
   glDisable(GL_LINE_STIPPLE);
   
   double angle;
   int i;
   int circle_point=200;
   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   
   glTranslatef(4.0,2.0,0.0);
   
   glBegin(GL_LINE_LOOP);
   for(i=0;i<circle_point;i++)
   {
		angle=2*3.14*i/circle_point;
		glVertex2f(cos(angle),sin(angle));
   }
   glEnd();
   glFlush();

   Sleep(3000);
   return 0;
}

