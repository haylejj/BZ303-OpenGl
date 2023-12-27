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
   
   //KOORD�NAT S�STEM�
   glEnable(GL_LINE_STIPPLE);
   glLineStipple(1,0xF0F0);
   
   glBegin(GL_LINES);
   	glVertex2f(-10.0,0.0);
   	glVertex2f(10.0,0.0);
   	glVertex2f(0.0,-10.0);
   	glVertex2f(0.0,10.0);
   glEnd();
   glDisable(GL_LINE_STIPPLE);
   
   //�eklin ilk hali
   glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
   glLineWidth(3.0);
   glColor3f(0.0,1.0,0.0);
   glBegin(GL_POLYGON);
   	glVertex2f(1.0,0.0);
   	glVertex2f(1.0,1.0);
   	glVertex2f(3.0,1.0);
   	glVertex2f(3.0,0.0);
   glEnd();	
   
   glMatrixMode(GL_MODELVIEW);  
   glLoadIdentity();
   
   //1.Operasyon 90 derece d�nd�r ve x y�n�nde 2 kat b�y�t ve x eksenine g�re simetri al
   
   glScalef(1.0,-1.0,1.0);
   glScalef(2.0,1.0,1.0);
   glRotatef(90.0,0.0,0.0,1.0);
   
   glColor3f(1.0,0.5,0.0);
   glBegin(GL_POLYGON);
   	glVertex2f(1.0,0.0);
   	glVertex2f(1.0,1.0);
   	glVertex2f(3.0,1.0);
   	glVertex2f(3.0,0.0);
   glEnd();
   
   //2.Operasyon 3,1 noktas�na g�re x y�n�nde 2 kat y y�n�nde 2 kat b�y�t
   glLoadIdentity();
   
   glTranslatef(3.0,1.0,0.0);
   glScalef(2.0,2.0,1.0);
   glTranslatef(-3.0,-1.0,0.0);
   
   glColor3f(1.0,0.0,1.0);
   glBegin(GL_POLYGON);
   	glVertex2f(1.0,0.0);
   	glVertex2f(1.0,1.0);
   	glVertex2f(3.0,1.0);
   	glVertex2f(3.0,0.0);
   glEnd();
   
   //3.Operasyon 1,2 noktas�na g�re 270 derece d�nder. y eksenine g�re simetri al. y y�n�nde 2 kat b�y�t.
   
   glLoadIdentity();
   
   glScalef(1.0,2.0,1.0);
   glScalef(-1.0,1.0,1.0);
   glTranslatef(1.0,2.0,0.0);
   glRotatef(270.0,0.0,0.0,1.0);
   glTranslatef(-1.0,-2.0,0.0);
   
   glColor3f(1.0,0.0,0.0);
   glBegin(GL_POLYGON);
   	glVertex2f(1.0,0.0);
   	glVertex2f(1.0,1.0);
   	glVertex2f(3.0,1.0);
   	glVertex2f(3.0,0.0);
   glEnd();
   
   glFlush();

   Sleep(3000);
   return 0;
}

