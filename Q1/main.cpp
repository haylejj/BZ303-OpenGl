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
   glOrtho(-20.0, 20.0, -20.0, 20.0, -20.0, 20.0);
   glLineWidth(2);
   
   glEnable(GL_LINE_STIPPLE);
   glLineStipple(1,0xFF00);// KOORDÝNAT SÝSTEMÝ
   glBegin(GL_LINES);
      glVertex2f(-20.0, 0.0);
      glVertex2f(20.0, 0.0);
      glVertex2f(0.0, -20.0);
      glVertex2f(0.0,  20.0);
   glEnd();
   glDisable(GL_LINE_STIPPLE);
   
   // þeklin ilk hali
   glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);// þeklin içini boþ gösterir.
   glColor3f(0.0,0.0,1.0);
   glBegin(GL_TRIANGLES);
	  glVertex2f(1.0,1.0);
	  glVertex2f(3.0,1.0);
	  glVertex2f(3.0,3.0);
   glEnd();	  	
   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   
   glTranslatef(3.0,-1.0,0.0);
   glScalef(-1.0,1.0,1.0);
   glScalef(2.0,3.0,1.0);
   glRotatef(30.0,0.0,0.0,1.0);
   glPushMatrix();
   
   glColor3f(0.0,0.0,1.0);
   glBegin(GL_TRIANGLES);
	  glVertex2f(1.0,1.0);
	  glVertex2f(3.0,1.0);
	  glVertex2f(3.0,3.0);
   glEnd();
   
   glFlush();
   Sleep(3000);
   return 0;
}

