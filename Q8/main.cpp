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
   
   //KOORDÝNAT SÝSTEMÝ
   glEnable(GL_LINE_STIPPLE);
   glLineStipple(1,0xF0F0);
   glBegin(GL_LINES);
   	glVertex2f(-10.0,0.0);
   	glVertex2f(10.0,0.0);
   	glVertex2f(0.0,-10.0);
   	glVertex2f(0.0,10.0);
   glEnd();
   glDisable(GL_LINE_STIPPLE);
   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   
   //þeklin ilk hali
   glBegin(GL_LINE_LOOP);
   	glVertex2f(1.0,1.0);
   	glVertex2f(3.0,1.0);
   	glVertex2f(3.0,2.0);
   	glVertex2f(1.0,2.0);
   glEnd();
   
   //1.Operasyon 90 derece döndür
   
   glLoadIdentity();
   glColor3f(1.0,0.0,0.0);
   glRotatef(90.0,0.0,0.0,1.0);
   glBegin(GL_LINE_LOOP);
   	glVertex2f(1.0,1.0);
   	glVertex2f(3.0,1.0);
   	glVertex2f(3.0,2.0);
   	glVertex2f(1.0,2.0);
   glEnd();
   
   //2.operasyon 90 derece döndür soýnra x ekseni 3 kat y 2 kat ölçekle

   glLoadIdentity();
   glColor3f(0.0,1.0,1.0);
   glScalef(3.0,2.0,1.0);
   glRotatef(90.0,0.0,0.0,1.0);
   glBegin(GL_LINE_LOOP);
   	glVertex2f(1.0,1.0);
   	glVertex2f(3.0,1.0);
   	glVertex2f(3.0,2.0);
   	glVertex2f(1.0,2.0);
   glEnd();
   
   //2.operasyon 90 derece döndür soýnra x ekseni 3 kat y 2 kat ölçekle sonra x -2 y 1 br ötele
 
   glLoadIdentity();
   glColor3f(1.0,1.0,0.0);
   glTranslatef(-2.0,1.0,0.0);
   glScalef(3.0,2.0,1.0);
   glRotatef(90.0,0.0,0.0,1.0);
   glBegin(GL_LINE_LOOP);
   	glVertex2f(1.0,1.0);
   	glVertex2f(3.0,1.0);
   	glVertex2f(3.0,2.0);
   	glVertex2f(1.0,2.0);
   glEnd();
   
   glFlush();

   Sleep(3000);
   return 0;
}

