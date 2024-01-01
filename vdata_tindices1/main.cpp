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
   glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
double X,Z;

X=0.525731112119133606;
Z=0.850650808352039932;

GLint i;

static GLfloat vdata[12][3] = {
{-X, 0.0, Z}, {X, 0.0, Z}, {-X, 0.0, -Z}, {X, 0.0, -Z},
{0.0, Z, X}, {0.0, Z, -X}, {0.0, -Z, X}, {0.0, -Z, -X},
{Z, X, 0.0}, {-Z, X, 0.0}, {Z, -X, 0.0}, {-Z, -X, 0.0}
};
static GLint tindices[20][3] = {
{0,4,1}, {0,9,4}, {9,5,4}, {4,5,8}, {4,8,1},
{8,10,1}, {8,3,10}, {5,3,8}, {5,2,3}, {2,7,3},
{7,10,3}, {7,6,10}, {7,11,6}, {11,0,6}, {0,1,6},
{6,1,10}, {9,0,11}, {9,11,2}, {9,2,5}, {7,2,11} };
for (i = 0; i < 20; i++) {
/* color information here */
//glColor3f((i+1)*0.15, 0.5, 0.5);
glBegin(GL_TRIANGLES);
glColor3f (0.0, 1.0, 0.0);
glVertex3fv(&vdata[tindices[i][0]][0]);
glColor3f (0.0, 1.0, 0.0);
glVertex3fv(&vdata[tindices[i][1]][0]);
glColor3f (0.0, 0.0, 1.0);
glVertex3fv(&vdata[tindices[i][2]][0]);
glEnd();
}
glFlush();

   Sleep(3000);
   return 0;
}
