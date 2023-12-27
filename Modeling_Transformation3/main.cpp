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
   glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
   //koordinat sistemi
   glEnable(GL_LINE_STIPPLE); 
   glLineStipple(1, 0xAAAA);
    glLineWidth(3);
    glBegin(GL_LINES);
      glVertex2f(-5.0, 0.0);
      glVertex2f(5.0, 0.0);
      glVertex2f(0.0, -5.0);
      glVertex2f(0.0,  5.0);
   glEnd();
   glDisable(GL_LINE_STIPPLE);
   
   // ilk hali
   glLineWidth(5);
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   glBegin(GL_TRIANGLES);
      glVertex2f(1.0, 1.0);
      glVertex2f(3.0, 1.0);
      glVertex2f(2.0, 2.5);
   glEnd();
   
	glMatrixMode(GL_MODELVIEW); 
	glEnable(GL_LINE_STIPPLE); 
	glLineStipple(1, 0xF0F0);
	glLoadIdentity();
	
	glColor3f(1.0, 0.0, 0.0);
	//glTranslatef(-2.0, 2.0, 0.0);
	//glScalef(-1.0, -1.0, 1.0);
	//glScalef(2.0, 1.5, 1.0);
	glRotatef (90.0, 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
      glVertex2f(1.0, 1.0);
      glVertex2f(3.0, 1.0);
      glVertex2f(2.0, 2.5);
	glEnd();
 
	 glLoadIdentity();
	glColor3f(0.0, 1.0, 0.0);
	//glTranslatef(-2.0, 2.0, 0.0);
	//glScalef(-1.0, -1.0, 1.0);
	glScalef(2.0, 1.5, 1.0);
	glRotatef (90.0, 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
      glVertex2f(1.0, 1.0);
      glVertex2f(3.0, 1.0);
      glVertex2f(2.0, 2.5);
	glEnd();
 
  
 	glLoadIdentity();
	glColor3f(0.0, 0.0, 1.0);
	//glTranslatef(-2.0, 2.0, 0.0);
	glScalef(-1.0, -1.0, 1.0);
	glScalef(2.0, 1.5, 1.0);
	glRotatef (90.0, 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
      glVertex2f(1.0, 1.0);
      glVertex2f(3.0, 1.0);
      glVertex2f(2.0, 2.5);
	glEnd();
 
	glLoadIdentity();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-2.0, 2.0, 0.0);
	glScalef(-1.0, -1.0, 1.0);
	glScalef(2.0, 1.5, 1.0);
	glRotatef (90.0, 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
      glVertex2f(1.0, 1.0);
      glVertex2f(3.0, 1.0);
      glVertex2f(2.0, 2.5);
	glEnd();  
	glFlush();

   Sleep(9000);
   return 0;
}

