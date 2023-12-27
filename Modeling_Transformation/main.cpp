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
   glOrtho(-6.0, 6.0, -6.0, 6.0, -5.0, 5.0);
   
   glEnable(GL_LINE_STIPPLE); /* koordinat sistemi */
   glLineStipple(1, 0xF0F0);
   glBegin(GL_LINES);
      glVertex2f(-6.0, 0.0);
      glVertex2f(6.0, 0.0);
      glVertex2f(0.0, -6.0);
      glVertex2f(0.0, 6.0);
      glEnd();
    glDisable(GL_LINE_STIPPLE);
    
    glBegin(GL_LINE_LOOP);  // üçgenin ilk hali
      glVertex2f(1.0, 1.0);
      glVertex2f(3.0, 1.0);
      glVertex2f(3.0, 3.0);
      glEnd();
      
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // birim matrise çeviriyor
    
    glTranslatef(3.0,-2.0,0.0);
    glRotatef(180.0,0.0,0.0,1.0);
    glTranslatef(2.0,2.0,0.0);
    glScalef(2.0,1.0,1.0);
    glTranslatef(-2.0,-2.0,0.0);
    glBegin(GL_LINE_LOOP);
    	glVertex2f(1.0,1.0);
    	glVertex2f(3.0,1.0);
    	glVertex2f(3.0,3.0);
    	glEnd();
    
    
   glFlush();

   Sleep(10000);
   return 0;
}

