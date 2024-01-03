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
   glOrtho(-5.0, 5.0, -5.0, 5.0, -1.0, 1.0);
   //Koordinat sistemi
   glEnable(GL_LINE_STIPPLE);
   glLineStipple(1,0xF0F0);
   glBegin(GL_LINES);
      glVertex2f(-10.0, 0.0);
      glVertex2f(10.0, 0.0);
      glVertex2f(0.0, -10.0);
      glVertex2f(0.0, 10.0);
   glEnd();
   glDisable(GL_LINE_STIPPLE);
   
   /*
   kenar çizgileri kesikli doðrulardan oluþan 3 siyah 6 beyaz 2 siyah 1 beyaz 3 siyah 1 beyaz
   þeklþinde içi boþ mavi renk bir dörtgene transformasyon uygulanacak.a 1,1  b 1,2  c 2,2  d 2,1
   Dörtgenin 3,-2 noktasýna göre 90 derece rotasyonu yapýn.
   
   		bu arka plan beyaz,çizilecek þey siyah
   		1110 0000 0110 1110
   		0111 0110 0000 0111
   		0x7607
   		
   		bu arka plan siyah çizilecek þey beyaz
   		0001 1111 1001 0001
   		1000 1001 1111 1000
   		0x89F8
   */
   
   //þeklin ilk hali
   glEnable(GL_LINE_STIPPLE);
   glLineStipple(1,0x7607);
   glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
   glColor3f(0.0,0.0,1.0);
   glBegin(GL_LINE_LOOP);
   	glVertex2f(1.0,1.0);
   	glVertex2f(1.0,2.0);
   	glVertex2f(2.0,2.0);
   	glVertex2f(2.0,1.0);
   glEnd();
   
   //transformasyon uygulanmýþ hali
   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   
   glTranslatef(3.0,-2.0,0.0);
   glRotatef(90.0,0.0,0.0,1.0);
   glTranslatef(-3.0,2.0,0.0);
   
   glColor3f(0.0,0.0,1.0);
   glBegin(GL_LINE_LOOP);
   	glVertex2f(1.0,1.0);
   	glVertex2f(1.0,2.0);
   	glVertex2f(2.0,2.0);
   	glVertex2f(2.0,1.0);
   glEnd();
   
   glFlush();

   Sleep(3000);
   return 0;
}

