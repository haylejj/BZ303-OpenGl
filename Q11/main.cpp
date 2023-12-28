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
   
   //KOORDÝNAT SÝSTEMÝ
   glEnable(GL_LINE_STIPPLE);
   glLineStipple(1,0xF0F0);
   
   glBegin(GL_LINES);
   	glVertex2f(-20.0,0.0);
   	glVertex2f(20.0,0.0);
   	glVertex2f(0.0,-20.0);
   	glVertex2f(0.0,20.0);
  glEnd();
  glDisable(GL_LINE_STIPPLE);
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  
  
  glScalef(1.0,-1.0,1.0);
  glScalef(2.0,3.0,1.0);
  glRotatef(60.0,0.0,0.0,1.0);
  glPushMatrix();
  
  glColor3f(1.0,1.0,0.0);
  glBegin(GL_TRIANGLES);
  	glVertex2f(2.0,4.0);
  	glVertex2f(3.0,4.0);
  	glVertex2f(2.0,5.0);
  glEnd();
  
  glLoadIdentity();
  
  glPopMatrix();
  
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_LINES);
  	glVertex2f(-7.0,-2.0);
  	glVertex2f(-2.0,-2.0);
  glEnd();
  
  glColor3f(0.0,1.0,0.0);
  glBegin(GL_LINES);
  	glVertex2f(-2.0,-2.0);
  	glVertex2f(-2.0,-9.0);
  glEnd();
  
  glColor3f(0.0,0.0,1.0);
  glBegin(GL_LINES);
  	glVertex2f(-2.0,-9.0);
  	glVertex2f(-7.0,-9.0);
  glEnd();
  
  glColor3f(0.0,1.0,1.0);
  glBegin(GL_LINES);
  	glVertex2f(-7.0,-9.0);
  	glVertex2f(-7.0,-2.0);
  glEnd();
  
  
   glFlush();

   Sleep(3000);
   return 0;
}

