#include <GL/gl.h>
#include <GL/glaux.h>
#include <math.h>


int main(int argc, char** argv)
{
   auxInitDisplayMode (AUX_SINGLE | AUX_RGBA);
   auxInitPosition (0, 0, 1000, 1000);
   auxInitWindow (argv[0]);

   glClearColor (0.0, 0.0, 0.0, 0.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
double X,Z,Y;

X=0.5;
Y=1;
Z=1.5;

GLint i;

static GLfloat vdata[12][3] = {
{X,Z,Y}, {-X,-X,-X}, {-X, X, -Z}, {X, -X, -Z},
{Z, -X,-X}, {-Z, X, -X}, {X, -X, Z}, {X, X, X},
{Z, -X,Z}, {-X, X, -Z}, {Z, Z, X}, {-X, -Z, -X}
};
static GLint tindices[10][4] = {
{0,4,1,9}, {5,2,9,1}, {4,3,6,7}, {0,7,9,4}, {11,1,10,8},
{8,10,11,2}, {8,3,10,5}, {5,3,8,6}, {5,2,3,7}, {2,7,3,8},
 };
for (i = 1; i < 5; i++) {
	glLineWidth(i);
glBegin(GL_LINE_STRIP);
glVertex2fv(&vdata[tindices[i][0]][0]);
glVertex2fv(&vdata[tindices[i][1]][0]);
glVertex2fv(&vdata[tindices[i+1][2]][1]);
glVertex2fv(&vdata[tindices[i+1][3]][2]);
glEnd();
}
glFlush();

   Sleep(3000);
   return 0;
}
