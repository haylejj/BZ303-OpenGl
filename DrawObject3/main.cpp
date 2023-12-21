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
   glBegin(GL_LINES);
	for (float i = -2.0; i <= 2.0; i += 1.0) {
    glVertex2f(i, -2.0);
    glVertex2f(i, 2.0);
    glVertex2f(-2.0, i);
    glVertex2f(2.0, i);
	}
	glEnd();
   glLineWidth(5.0);
   glPointSize(5.0);
   
   glBegin(GL_POINTS);
   	glColor3f(1.0,0.0,0.0);
    glVertex2f(0.25,0.25);
    glVertex2f(0.75,0.50);
    glVertex2f(1.1,1.1);
   glEnd();
   
   glFlush();

   Sleep(5000);
   return 0;
}

