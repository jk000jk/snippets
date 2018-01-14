
#include <GL/glut.h>
#include <stdlib.h>


void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3d(0, 1, 1);
   glBegin(GL_POLYGON);
        glVertex2f(250, 300);
        glVertex2f(350, 300);
        glVertex2f(400, 400);
        glVertex2f(300, 500);
        glVertex2f(200, 400);
   glEnd();
   glFlush();

   glBegin(GL_LINES);
   glColor3d(1, 1, 1);
        glVertex2f(0, 300);
        glVertex2f(450, 300);
        glVertex2f(200, 300);
        glVertex2f(200, 500);
   glEnd();
   glFlush();

   glColor3d(0, 1, 0);
   glBegin(GL_POLYGON);
        glVertex2f(250, 300);
        glVertex2f(350, 300);
        glVertex2f(400, 200);
        glVertex2f(300, 100);
        glVertex2f(200, 200);
   glEnd();
   glFlush();

  glColor3d(1, 0, 0);
   glBegin(GL_POLYGON);
        glVertex2f(50, 300);
        glVertex2f(150, 300);
        glVertex2f(200, 400);
        glVertex2f(100, 500);
        glVertex2f(0, 400);
   glEnd();
   glFlush();


}
void reshape (int w, int h)//functia redesenare
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);//stabilirea viewportului la dimensiunea ferestrei
    glMatrixMode (GL_PROJECTION);//specificare matrice modificabila la valoare argumentului de modificare
    glLoadIdentity ();//initializarea sistemului de coordonate
    gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);//stabileste volumul de vedere folosind o proiectie ortografica
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (150,150);
    glutCreateWindow ("_");
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}



// Puncte
#include <GL/glut.h> void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //glPointSize(40.0);
	glShadeModel(GL_FLAT);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);   //initializare desen poligon
	glVertex2f(0.0, 00.0); //stabilire coordonate triunghi glVertex2f(200.0,200.0);//stabilire coordonate triunghi glVertex2f(00.0,200.0);//stabilire coordonate triunghi
	glEnd();			   //sfisit desenare
	//executare functie
	glFlush();
	glPointSize(40.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(100, 300);
	glVertex2i(200, 300);
	glPointSize(40.0);
	glVertex2i(200, 400);
	glVertex2i(0, 0);
	glEnd();
	glFlush();
}
void reshape(int w, int h)						//functia redesenare {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);   //stabilirea viewportului la dimensiunea ferestrei
glMatrixMode(GL_PROJECTION);					//specificare matrice modificabila la valoare argumentului de modificare
glLoadIdentity();								//initializarea sistemului de coordonate
gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h); //stabileste volumul de vedere folosind o proiectie ortografica
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("puncte");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}
