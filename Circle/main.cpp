#include <GL/gl.h>
#include <GL/glaux.h>
#include <math.h>
#define PI 3.1415926535897;
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

double angle;
int i;
int circle_points=100;

glBegin(GL_LINE_LOOP);
	for(i=0;i<circle_points;i++){
		angle=2*3.14*i/circle_points;
		glVertex2f(cos(angle),sin(angle));
	}
glEnd();
   glFlush();

   Sleep(3000);
   return 0;
}
