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
   glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
   
   //Koordinat sistemi
   glEnable(GL_LINE_STIPPLE);
   glLineStipple(1,0xF0F0);
   glBegin(GL_LINES);
   	glVertex2f(-10.0,0.0);
    glVertex2f(10.0,0.0);
    glVertex2f(0.0,-10.0);
    glVertex2f(0.0,10.0);
   glEnd();
   glDisable(GL_LINE_STIPPLE);
   
   /*
   içi boþ, her bir kenarýnýn kalýnlýðý farklý olan (2,3,4 piksel kalýnlýðý)
   a 1,1  b 1,2  c 2,1 köþelerinin oluþturduðu bir üçgene transformasyon uygulanacak:
		önce orjine göre 90 derece
		sonra x ekseni 3 kat y ekseni 2 kat ölçekleme
		sonra y ekseni göre simetri alma
		daha sonra x eksenine göre 3, y eksenine göre -2 birim öteleme
   */
   
   glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
   //Þeklin ilk hali
   glColor3f(1.0,1.0,0.0);
   glBegin(GL_TRIANGLES);
   	glLineWidth(2.0);
   	glVertex2f(1.0,1.0);
   	glLineWidth(3.0);
   	glVertex2f(1.0,2.0);
   	glLineWidth(4.0);
   	glVertex2f(2.0,1.0);
   glEnd();
   
   //Transformasyon uygulanmýþ hali
   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   
   
   
   glTranslatef(3.0,-2.0,0.0);
   glScalef(-1.0,1.0,1.0);
   glScalef(3.0,2.0,1.0);
   glRotatef(90.0,0.0,0.0,1.0);
   glColor3f(0.0,0.0,1.0);
    glBegin(GL_TRIANGLES);
   	glLineWidth(2.0);
   	glVertex2f(1.0,1.0);
   	glLineWidth(3.0);
   	glVertex2f(1.0,2.0);
   	glLineWidth(4.0);
   	glVertex2f(2.0,1.0);
   glEnd();
   
   
   glLoadIdentity();
   
   glScalef(-1.0,1.0,1.0);
   glScalef(3.0,2.0,1.0);
   glRotatef(90.0,0.0,0.0,1.0);
   glColor3f(0.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
   	glLineWidth(2.0);
   	glVertex2f(1.0,1.0);
   	glLineWidth(3.0);
   	glVertex2f(1.0,2.0);
   	glLineWidth(4.0);
   	glVertex2f(2.0,1.0);
   glEnd();
   
   glLoadIdentity();
   

   glScalef(3.0,2.0,1.0);
   glRotatef(90.0,0.0,0.0,1.0);
   glColor3f(0.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
   	glLineWidth(2.0);
   	glVertex2f(1.0,1.0);
   	glLineWidth(3.0);
   	glVertex2f(1.0,2.0);
   	glLineWidth(4.0);
   	glVertex2f(2.0,1.0);
   glEnd();
   
	glLoadIdentity();   

   glRotatef(90.0,0.0,0.0,1.0);
   glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
   	glLineWidth(2.0);
   	glVertex2f(1.0,1.0);
   	glLineWidth(3.0);
   	glVertex2f(1.0,2.0);
   	glLineWidth(4.0);
   	glVertex2f(2.0,1.0);
   glEnd();
   
   	
   glFlush();

   Sleep(10000);
   return 0;
}

