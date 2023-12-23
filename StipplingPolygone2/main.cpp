#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

int main(int argc, char** argv)
{
   auxInitDisplayMode (AUX_SINGLE | AUX_RGBA);
   auxInitPosition (0, 0, 500, 500);
   auxInitWindow (argv[0]);

   glClearColor (1.0, 1.0, 1.0, 0.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0, 0.0, 0.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
 
   glLineStipple(1,0x3F07);
   glEnable(GL_LINE_STIPPLE);
   glLineWidth(5);
   glBegin(GL_LINES);
   	glVertex2f(-0.5,-0.5);
   	glVertex2f(0.5,-0.5);
   glEnd();	
   glFlush();

   Sleep(95000);
   return 0;
}


