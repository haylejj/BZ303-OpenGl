#include <GL/gl.h>
#include <GL/glaux.h>

int main(int argc, char** argv)
{
   auxInitDisplayMode (AUX_SINGLE | AUX_RGBA);
   auxInitPosition (0, 0, 500, 500);
   auxInitWindow (argv[0]);

   glClearColor (1.0, 1.0, 1.0, 1.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
   
   glLineWidth(5.0);
   
   
   glLineStipple(1,0x0033);
   glEnable(GL_LINE_STIPPLE);
   glBegin(GL_LINES);
   	glColor3f(0.0,0.0,0.0);
      glVertex2f(-0.5,-0.5);
      glVertex2f(0.5,0.5);
   glEnd();
   glFlush();

   Sleep(15000);
   return 0;
}

