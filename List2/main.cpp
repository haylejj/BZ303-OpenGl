#include <GL/gl.h>
#include <GL/glaux.h>

GLuint listName = 1;
void myinit (void)
{
glNewList (listName, GL_COMPILE);
glBegin (GL_TRIANGLES);
glVertex2f (0.0, 0.0);
glVertex2f (1.0, 0.0);
glVertex2f (0.0, 1.0);
glEnd ();
glColor3f(1.0, 0.0, 0.0);
glTranslatef (1.0, 0.0, 0.0);
glEndList ();
glShadeModel (GL_FLAT);
}
void drawLine (void)
{
glBegin (GL_LINES);
glVertex2f (0.0, 1.0);
glVertex2f (5.0, 1.0);
glEnd ();
}
void CALLBACK display(void)
{
GLuint i;
glClear (GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glTranslatef (5.0, 0.0, 0.0);
glPushMatrix();
glLoadIdentity();
glColor3f(0.0, 1.0, 0.0);
for (i = 0; i < 5; i++){
glCallList (listName);
glTranslatef (1.0, 1.0, 0.0);
}
glColor3f(1.0, 1.0, 0.0);
glPopMatrix();
drawLine ();
glFlush ();
}
void CALLBACK myReshape(GLsizei w, GLsizei h)
{
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 10.0, 0.0, 5.0, -1.0, 1.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
int main(int argc, char** argv)
{
auxInitDisplayMode (AUX_SINGLE | AUX_RGBA);
auxInitPosition (0, 0, 400, 50);
auxInitWindow (argv[0]);
myinit ();
auxReshapeFunc (myReshape);
auxMainLoop(display);
   Sleep(3000);
   return 0;
}



