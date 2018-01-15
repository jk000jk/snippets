
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
	glBegin(GL_POLYGON);   // initializare desen poligon
	glVertex2f(0.0, 00.0); // stabilire coordonate triunghi 
	glVertex2f(200.0,200.0);// stabilire coordonate triunghi 
	glVertex2f(00.0,200.0);// stabilire coordonate triunghi
	glEnd();			   // sfisit desenare
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
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);   // stabilirea viewportului la dimensiunea ferestrei
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


#include <GL/glut.h> //header OpenGL ce include gl.h si glu.h
void init()			 //functia initiere
{
	// glClearColor (0.0, 0.0, 0.0, 0.0);  //stabileste culoarea de sters
	// glShadeModel (GL_FLAT);
}

//functia de desenare si afisare
void display()
{
	glClear(GL_COLOR_BUFFER_BIT); //sterge urmele de desene din fereastra curenta glBegin(GL_POLYGON);//initializare desen poligon
	glColor3f(2.0, 0.0, 0.0);	 //culoarea de desenare
	glVertex2f(200.0, 200.0);	 //stabilire coordonate triunghi glVertex2f(400.0,200.0);//stabilire coordonate triunghi glVertex2f(400.0,400.0);//stabilire coordonate triunghi
	glEnd();					  //sfisit desenare glFlush ();//executare functie
	glColor3f(1.0, 1.0, 0.0);	 //culoarea de desenare glBegin(GL_POLYGON);//initializare desen poligon
	glVertex2f(200.0, 400.0);	 //stabilire coordonate triunghi glVertex2f(400.0,400.0);//stabilire coordonate triunghi glVertex2f(200.0,200.0);//stabilire coordonate triunghi
	glEnd();					  //sfisit desenare
	glFlush();					  //executare functie
	glColor3f(0.0, 1.0, 1.0);	 //culoarea de desenare
	glBegin(GL_POLYGON);		  //initializare desen poligon glVertex2f(000.0,000.0); //stabilire coordonate triunghi glVertex2f(200.0,200.0);//stabilire coordonate triunghi glVertex2f(000.0,200.0);//stabilire coordonate triunghi
	glEnd();					  //sfisit desenare glFlush ();//executare functie
	glColor3f(1.0, 0.5, 1.0);	 //culoarea de desenare
	glBegin(GL_POLYGON);		  //initializare desen poligon glVertex2f(000.0,000.0); //stabilire coordonate triunghi glVertex2f(200.0,200.0);//stabilire coordonate triunghi glVertex2f(000.0,200.0);//stabilire coordonate triunghi
	glEnd();					  //sfisit desenare
	glFlush();					  //executare functie
	glColor3f(1.0, 1.0, 0.5);	 //culoarea de desenare
	glBegin(GL_POLYGON);		  //initializare desen poligon glVertex2f(600.0,000.0); //stabilire coordonate triunghi glVertex2f(600.0,200.0);//stabilire coordonate triunghi glVertex2f(400.0,200.0);//stabilire coordonate triunghi
	glEnd();					  //sfisit desenare glFlush ();//executare functie
	glColor3f(0.0, 1.0, 0.0);	 //culoarea de desenare
	glBegin(GL_POLYGON);		  //initializare desen poligon glVertex2f(200.0,400.0);//stabilire coordonate triunghi glVertex2f(000.0,400.0);//stabilire coordonate triunghi glVertex2f(200.0,600.0);//stabilire coordonate triunghi
	glEnd();					  //sfisit desenare glFlush ();//executare functie
	glColor3f(0.0, 1.0, 1.0);	 //culoarea de desenare
	glBegin(GL_POLYGON);		  //initializare desen poligon glVertex2f(400.0,400.0); //stabilire coordonate triunghi glVertex2f(600.0,400.0);//stabilire coordonate triunghi glVertex2f(600.0,600.0);//stabilire coordonate triunghi
	glEnd();					  //sfisit desenare glFlush ();//executare functie
	glColor3f(3.0, 0.0, 0.0);	 //culoarea de desenare
	glBegin(GL_POLYGON);		  //initializare desen poligon glVertex2f(400.0,600.0); //stabilire coordonate triunghi glVertex2f(400.0,400.0);//stabilire coordonate triunghi glVertex2f(600.0,600.0);//stabilire coordonate triunghi
	glEnd();					  //sfisit desenare
	glFlush();					  //executare functie
}

void reshape(int w, int h)						//functia redesenare {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);   //stabilirea viewportului la dimensiunea ferestrei
glMatrixMode(GL_PROJECTION);					//specificare matrice modificabila la valoare argumentului de modificare
glLoadIdentity();								//initializarea sistemului de coordonate
gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h); //stabileste volumul de vedere folosind o proiectie ortografica
}

int main(int argc, char **argv) //creare fereastra
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //se specifica modelul de culoare al ferestrei: un singur buffer si culoare RGB
	glutInitWindowSize(600, 600);				 //initiaza dimensiunea ferestrei principale 600x600 pixeli glutInitWindowPosition (200,10);//initiaza in fereastra principala fereastra de afisare glutCreateWindow ("TRIUNGHIURI");
	init();
	glutDisplayFunc(display); //se reimprospateza continutul ferestrei glutReshapeFunc(reshape);//functia redesenare glutMainLoop();//bucla de procesare a evenimentelor
	return 0;
}

#include <GL/glut.h> #include <stdlib.h> #include <math.h> void init() {
// Stabileste culoarea cu care se va curata interiorul ferestrei, prin parametrii dati stabilindu-se
// componenetele culorii ce au valori reale de la 0.0 la 1.0 (cu pasi aproximativi de 0.00006).
glClearColor(0.0, 0.0, 0.0, 0.0); // select flat or smooth shading. glShadeModel (GL_FLAT);
}
void display()
{
	// Sterge eventualele desene din fereastra curenta glClear (GL_COLOR_BUFFER_BIT);
	// stabileste culoarea (RGB)
	glColor3f(1.0, 0.0, 0.0);
	// Specifies the primitive or primitives that will be created from vertices

	 
		// glBegin and the subsequent glEnd. Ten symbolic constants are accepted:
		// GL_POINTS,
		// GL_LINES,
		// GL_LINE_STRIP, GL_LINE_LOOP, GL_TRIANGLES, GL_TRIANGLE_STRIP,
		// GL_TRIANGLE_FAN, GL_QUADS,
		// GL_QUAD_STRIP, and GL_POLYGON.
		glBegin(GL_POLYGON);
	// specify a vertex (x, y coord)
	glVertex2f(200.0, 200.0);
	glVertex2f(400.0, 200.0);
	glVertex2f(400.0, 400.0);
	// glBegin and glEnd delimit the vertices that define a primitive or a group of like
	primitives.
		// glBegin accepts a single argument that specifies in which of ten ways the vertices
		are interpreted.glEnd();
	// force execution of GL commands in finite time glFlush();
	// dreptunghi jos
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.0);
	glVertex2f(50.0, 0.0);
	glVertex2f(50.0, 60.0);
	glVertex2f(0.0, 60.0);
	glEnd();
	glFlush();
	// patrat sus
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.0, 500.0);
	glVertex2f(100.0, 500.0);
	glVertex2f(100.0, 600.0);
	glVertex2f(0.0, 600.0);
	glEnd();
	glFlush();
	// cerc in jurul triunghiului
	glColor3f(1, 1, 0);
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2f(300, 300); // un punct in centru
	for (int i = 0; i < 360; ++i)
	{
		// 141 = raza cercului + 1 pixel
		glVertex2f(300 + sin(i) * 141, 300 + cos(i) * 141);
	}
	glEnd();
	glFlush();
}
void reshape(int w, int h)
{
	// Stabilirea viewportului la dimensiunea ferestrei glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	// specify which matrix is the current matrix
		glMatrixMode(GL_PROJECTION);
	// replace the current matrix with the identity matrix glLoadIdentity ();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // seteaza dimensiunea ferestrei
	glutInitWindowSize(600, 600);
	// seteaza pozitia initiala
	glutInitWindowPosition(100, 100);
	glutCreateWindow("TESTE");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
