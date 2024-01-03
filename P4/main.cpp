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
   glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 1.0);
   
   //koordinat sistemi
   glEnable(GL_LINE_STIPPLE);
   glLineStipple(1,0xF0F0);
   glBegin(GL_LINES);
   	glVertex2f(-10.0,0.0);
   	glVertex2f(10.0,0.0);
   	glVertex2f(0.0,-10.0);
   	glVertex2f(0.0,10.0);
   glEnd();
   glDisable(GL_LINE_STIPPLE);
   
   //ÞEKLÝN ÝLK HALÝ
   glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
   glColor3f(1.0,0.0,0.0);
   glBegin(GL_TRIANGLES);
   	glVertex2f(2.0,2.0);
   	glVertex2f(3.0,2.0);
   	glVertex2f(3.0,3.0);
   glEnd();
   
   /*
   içi boþ kýrmýzý renk 2,2 3,2 3,3 köþelerin oluþturduðu abc üçgenine
   transformasyon uygulanmak isteniyor
   önce 2,2 noktasýna göre 90 derece rotasyon
   sonra x eksenine göre 3 kat y eksenine göre 2 kat
   x eksenine göre -3,y eksenine göre 2 birim öteleme
   */
   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   
   glTranslatef(-3.0,2.0,0.0);
   glScalef(3.0,2.0,1.0);
   glTranslatef(2.0,2.0,0.0);
   glRotatef(90.0,0.0,0.0,1.0);
   glTranslatef(-2.0,-2.0,0.0);
   
   glColor3f(1.0,0.0,0.0);
   glBegin(GL_TRIANGLES);
   	glVertex2f(2.0,2.0);
   	glVertex2f(3.0,2.0);
   	glVertex2f(3.0,3.0);
   glEnd();
   
   	
   glFlush();

   Sleep(3000);
   return 0;
}

