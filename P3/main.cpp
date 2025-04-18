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
   glBegin(GL_LINES);
			glVertex2f(0.0,0.0);
			glVertex2f(1.0,2.0);
		glEnd();
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(4.0,3.0,0.0);
   /*
   burada push pop mant���: ilk ba�ta tr4,3 pushlan�yor stacke sonra ilgili 
   i�lemler yap�l�yor �ekil �izildikden sonra pop matrix yap�p stackdeki eleman� c�kart�royuz.
   bizim yeni transformasyon matrisimiz oluyor ve d�ng� yeniden ba�l�yor yani her seferinde transformasyon matrisi tr 4,3 oluyor
   sonra 45*i rotasyon i�lemini yap�yoruz.
   */
   for(int i=0;i<6;i++)
   {
		glPushMatrix();
		glRotatef(45.0*i,0.0,0.0,1.0);
		glLineWidth((i+1));
		glBegin(GL_LINES);
			glVertex2f(0.0,0.0);
			glVertex2f(1.0,2.0);
		glEnd();
		glPopMatrix();
   }
   
   
      
   glFlush();

   Sleep(10000);
   return 0;
}

