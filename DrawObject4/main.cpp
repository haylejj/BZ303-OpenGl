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
   glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
   glLineWidth(5.0);
   glPointSize(5.0);
   
   glBegin(GL_LINES);
	for (float i = -2.0; i <= 2.0; i += 1.0) {
    glVertex2f(i, -2.0);
    glVertex2f(i, 2.0);
    glVertex2f(-2.0, i);
    glVertex2f(2.0, i);
	}
	glEnd();
   
   glPolygonMode(GL_BACK,GL_LINE);
   glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);   	
      glVertex2f(-0.5, -0.5);
      glVertex2f(-0.5, 0.5);
      glVertex2f(0.5, 0.5);
      glVertex2f(0.5, -0.5);
   glEnd();
   glFlush();

   Sleep(3000);
   return 0;
}

