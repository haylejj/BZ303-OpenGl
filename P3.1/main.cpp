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
   
   //KOORDYNAT SYSTEMY
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
   
   /*
   glPointSize(5);
   glTranslatef(4.0,3.0,0.0);
   glRotatef(135.0,0.0,0.0,1.0);
   //glTranslatef(1.0,1.0,0.0);
   
   glBegin(GL_POINTS);
			glVertex2f(0.0,0.0);
		glEnd();
	
	glLoadIdentity();
		
		glPointSize(5);
   glTranslatef(4.0,3.0,0.0);
   glRotatef(90.0,0.0,0.0,1.0);
  // glTranslatef(1.0,1.0,0.0);
   
   glBegin(GL_POINTS);
			glVertex2f(0.0,0.0);
		glEnd();
		
   
   glLoadIdentity();
   glPointSize(5);
   glTranslatef(4.0,3.0,0.0);
   glRotatef(45.0,0.0,0.0,1.0);
  // glTranslatef(1.0,1.0,0.0);
   
   glBegin(GL_POINTS);
			glVertex2f(0.0,0.0);
		glEnd();
   
   burada push pop mantýðý: ilk baþta tr4,3 pushlanýyor stacke sonra ilgili 
   iþlemler yapýlýyor þekil çizildikden sonra pop matrix yapýp stackdeki elemaný cýkartýroyuz.
   bizim yeni transformasyon matrisimiz oluyor ve döngü yeniden baþlýyor yani her seferinde transformasyon matrisi tr 4,3 oluyor
   sonra 45*i rotasyon iþlemini yapýyoruz.
   */
   glTranslatef(4.0,3.0,0.0);
   int i;
   for(i=0;i<8;i++){
	glPushMatrix();
	glRotatef(45.0*i,0.0,0.0,1.0);
	glTranslatef(1.0,1.0,0.0);
	glPointSize((i+1));
	glBegin(GL_POINTS);
		glVertex2f(0.0,0.0);
	glEnd();
	glPopMatrix();// burada ilk pushladýðýmýzý popluyoruz ve yeni transformasyon matrisimiz o oluyor yani tr 4,3
	//bunun anlamý transformasyon matrisini baþlangýca döndürüyoruz. hep 4,3 olacak þekilde ayarladýk baþlarken
   }
   
   
      
   glFlush();

   Sleep(10000);
   return 0;
}

