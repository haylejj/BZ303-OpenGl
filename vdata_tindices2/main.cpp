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
double X,Y,Z;

X=1.0;
Y=2.0;
Z=3.0;

GLint i;

static GLfloat vdata[12][3] = {
{-Z,X,Y}, {X, Y, Z}, {-X, -X, -Z}, {-Y, -Z, -Z},
{-Y, Z, X}, {-Z, -X, -X}, {X, X, -X}, {-Z, Z, -X},
{Z, -X, 0.0}, {-X, X, X}, {Z, -X, 0.0}, {-Z, Y, -Z}
};
static GLint tindices[10][4] = {
{0,4,1,9},{5,2,9,1},{5,3,6,7},{4,9,6,11},{0,9,1,4},
{3,2,9,4},{8,3,11,7},{5,3,8,6},{5,2,3,7},{2,7,3,8}
};
for (i = 0; i < 6; i++) {
/* color information here */
//glColor3f((i+1)*0.15, 0.5, 0.5);
glBegin(GL_LINES);

glVertex3fv(&vdata[tindices[i][0]][0]);

glVertex3fv(&vdata[tindices[i][1]][0]);

glVertex2fv(&vdata[tindices[i+1][2]][1]);

glVertex2fv(&vdata[tindices[i+1][3]][1]);
glEnd();
}
glFlush();

   Sleep(3000);
   return 0;
}
