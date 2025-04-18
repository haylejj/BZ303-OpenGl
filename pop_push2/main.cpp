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
  	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
   
   //koordinat sistemi
   glEnable(GL_LINE_STIPPLE); 
   glLineStipple(1, 0xAAAA);
   glLineWidth(3);
   
    glBegin(GL_LINES);
      glVertex2f(-10.0, 0.0);
      glVertex2f(10.0, 0.0);
      glVertex2f(0.0, -10.0);
      glVertex2f(0.0,  10.0);
   glEnd();
   glDisable(GL_LINE_STIPPLE);
   
   glLineWidth(3);
   	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
      glVertex2f(1.0, 1.0);
      glVertex2f(3.0, 1.0);
      glVertex2f(3.0, 3.0);
	glEnd();  
	glFlush();
   
   
   	glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();  
    
    glEnable(GL_LINE_STIPPLE); 
	glLineStipple(1, 0xF0F0);
   
	
	glScalef(2.0,1.0,1.0); // ref
	glPushMatrix();
	glTranslatef(1.0,1.0,0.0);// ref,Tr(1,1) //  pushlad���m�z transformasyon matrisi ilk translate yap�l�yo sonra scale i�lemi
	glPushMatrix();
	glScalef(3.0,2.0,1.0);
	glTranslatef(-3.0,-1.0,0.0);
	glTranslatef(2.0,2.0,0.0);
	glRotatef(90.0,0.0,0.0,1.0);// bu durumda bu ve yukardaki i�lemler devred��� kal�yor.
	glPopMatrix(); // bu durumda sadece ref,Tr(1,1) cal�sacak.
	
	
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
      glVertex2f(1.0, 1.0);
      glVertex2f(3.0, 1.0);
      glVertex2f(3.0, 3.0);
	glEnd();  
	glFlush();
   
   

   Sleep(15000);
   return 0;
}

