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
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
   glPointSize(9);
   glLineWidth(7);
   
   glBegin(GL_LINES);
   glColor3f(1.0,0.0,0.0);
   glVertex2f(-0.5,-0.5);//A
   glVertex2f(-0.5,0.5);//B
   glVertex2f(0.5,0.5);//C
   glVertex2f(0.5,-0.5);//D
   
   glColor3f(0.0,1.0,0.0);
   
   
   glVertex2f(-0.5,0.5);//B
   glVertex2f(0.5,0.5);//C
   glVertex2f(0.5,-0.5);//D
   glVertex2f(-0.5,-0.5);//A
   
   glEnd();
   glFlush();

   Sleep(10000);
   return 0;
}

