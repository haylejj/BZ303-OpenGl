#include <GL/gl.h>
#include <GL/glaux.h>

	GLuint listName = 1;
	void myinit (void)
	{
	glNewList (listName, GL_COMPILE);// liste olu�turma.Bu listenin ad� listName de�i�kenine atan�yor.GL_COMPILE ise bu listenin derlenerek olu�turulaca��n� belirtiyor.
	glColor3f(1.0, 0.0, 0.0);
	glBegin (GL_TRIANGLES);
	glVertex2f (0.0, 0.0);
	glVertex2f (1.0, 0.0);
	glVertex2f (0.0, 1.0);
	glEnd ();
	glTranslatef (1.5, 0.0, 0.0);
	glEndList ();
	glShadeModel (GL_FLAT);
	}
	void drawLine (void)
	{
	glBegin (GL_LINES);
	glVertex2f (0.0, 0.5);
	glVertex2f (15.0, 0.5);
	glEnd ();
	}
	void CALLBACK display(void)
	{
	GLuint i;
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	for (i = 0; i < 10; i++)
	glCallList (listName);
	drawLine ();
	glFlush ();
	}
	void CALLBACK myReshape(GLsizei w, GLsizei h)
	{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 35.0, 0.0, 2.0, -1.0, 1.0);
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



