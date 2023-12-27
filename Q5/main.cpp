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
   
   //Þeklin ilk hali
   
   glBegin(GL_LINES);
   	glVertex2f(1.0,1.0);
   	glVertex2f(3.0,1.0);
   glEnd();	
   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   
   //1.Operasyon ->> 3.2 noktasýna göre 90 derece dönder
   
   glTranslatef(3.0,2.0,0.0);
   glRotatef(90.0,0.0,0.0,1.0);
   glTranslatef(-3.0,-2.0,0.0);
   
   glColor3f(1.0,0.0,0.0);
   glBegin(GL_LINES);
   	glVertex2f(1.0,1.0);
   	glVertex2f(3.0,1.0);
   glEnd();
   
   //2.Operasyon ->>3.2 noktasýna göre 90 derece dönder x ekseninde -2 birim
   glLoadIdentity();
   
   glTranslatef(-2.0,0.0,0.0);
   glTranslatef(3.0,2.0,0.0);
   glRotatef(90.0,0.0,0.0,1.0);
   glTranslatef(-3.0,-2.0,0.0);
   
   glColor3f(0.0,1.0,0.0);
   glBegin(GL_LINES);
   	glVertex2f(1.0,1.0);
   	glVertex2f(3.0,1.0);
   glEnd();
   
   //3.Operasyon ->>3.2 noktasýna göre 30 derece dönder x ekseninde -2 birim,x 3 kat büyüt
   glLoadIdentity();
   
   glScalef(3.0,1.0,1.0);
   glTranslatef(-2.0,0.0,0.0);
   glTranslatef(3.0,2.0,0.0);
   glRotatef(30.0,0.0,0.0,1.0);
   glTranslatef(-3.0,-2.0,0.0);
   
   glColor3f(1.0,0.5,0.0);
   glBegin(GL_LINES);
   	glVertex2f(1.0,1.0);
   	glVertex2f(3.0,1.0);
   glEnd();
   
   glFlush();

   Sleep(3000);
   return 0;
}

