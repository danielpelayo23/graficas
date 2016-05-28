// Cubica

#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <cmath>
using namespace std;

#define DEF_floorGridScale	1.0
#define DEF_floorGridXSteps	10.0
#define DEF_floorGridZSteps	10.0
float PI  = 3.141592654;
bool activateGrid = false;

GLUnurbsObj *theNurb;
GLfloat ctlpoints[21][21][3];
GLfloat knots[25];
//Variables Ecuacion//
//Ola 1//
//Usuario controla ola 1 al presionar tecla 1//
float L1 = 8; //Valor Cambiante cuando tocan a-z
float A1 = 0; //Valor Cambiante cuando tocan s-x
float S1 = 2; //Valor Cambiante cuando tocan d-c
float Dx1 = 0; //Valor Cambiante cuando tocan f-v
float Dy1 = -1; //Valor Cambiante cuando tocan g-b
float W1 = 2*PI/L1;
float Dx1norm = Dx1/sqrt(pow(Dx1,2)+pow(Dy1,2));
float Dy1norm = Dy1/sqrt(pow(Dx1,2)+pow(Dy1,2));
//Ola 2//
//Usuario controla ola 2 al presionar tecla 2//
float L2 = 3; //Valor Cambiante cuando tocan a-z
float A2 = 0.3; //Valor Cambiante cuando tocan s-x
float S2 = 1; //Valor Cambiante cuando tocan d-c
float Dx2 = 1; //Valor Cambiante cuando tocan f-v
float Dy2 = 1; //Valor Cambiante cuando tocan g-b
float Dx2norm = Dx2/sqrt(pow(Dx2,2)+pow(Dy2,2));
float Dy2norm = Dy2/sqrt(pow(Dx2,2)+pow(Dy2,2));
float W2 = 2*PI/L2;
float t;

void ejesCoordenada() {
	glLineWidth(2.5);
	glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(0,10);
		glVertex2f(0,-10);
		glColor3f(0.0,0.0,1.0);
		glVertex2f(10,0);
		glVertex2f(-10,0);
	glEnd();

	glLineWidth(1.5);
	int i;
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
		for(i = -10; i <=10; i++){
			if (i!=0) {		
				if ((i%2)==0){	
					glVertex2f(i,0.4);
					glVertex2f(i,-0.4);

					glVertex2f(0.4,i);
					glVertex2f(-0.4,i);
				}else{
					glVertex2f(i,0.2);
					glVertex2f(i,-0.2);

					glVertex2f(0.2,i);
					glVertex2f(-0.2,i);

				}
			}
		}
		
	glEnd();

	glLineWidth(1.0);
}

void changeViewport(int w, int h) {
	
	float aspectratio;

	if (h==0)
		h=1;

	
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(30, (GLfloat) w/(GLfloat) h, 1.0, 200.0);
   glMatrixMode (GL_MODELVIEW);

}

void colorSelect(string color){
	if (color.compare("red") == 0)
		glColor3f(1,0,0);
	else if (color.compare("green") == 0)
		glColor3f(0,1,0);
	else if (color.compare("blue") == 0)
		glColor3f(0,0,1);
	else if (color.compare("yellow") == 0)
		glColor3f(1,1,0);
	else if (color.compare("yellow1") == 0)
		glColor3f(0.918,0.835,0.078);
	else if (color.compare("yellow2") == 0)
		glColor3f(0.659,0.592,0.212);
	else if (color.compare("grey") == 0)
		glColor3f(0.72,0.72,0.67);
	else if (color.compare("orange") == 0)
		glColor3f(1,0.5,0);
	else if (color.compare("purple") == 0)
		glColor3f(1,0,1);
	else if (color.compare("white") == 0)
		glColor3f(1,1,1);
	else if (color.compare("black") == 0) 
		glColor3f(0,0,0);
	else if (color.compare("skin") == 0)
		glColor3f(1,0.84,0.76);
	else if (color.compare("brown") == 0)
		glColor3f(0.55,0.27,0.07);
	else
		glColor3f(1,0,0);
}
void drawPoint(float x,float y,float z, string color){
	colorSelect(color);
	glBegin(GL_POINTS);
		glVertex3f(x,y,z);
	glEnd();
}

float productoEscalar(float a[], float b[]){
	float result = 0;
	for (int i = 0; i < 2; i++)
	{
		result = a[i] * b[i] + result;
		
	}
	return result;
}

void init_surface() {
	for (int i = 0; i <21; i++) {
		for (int j = 0; j < 21; j++) {
			ctlpoints[i][j][0] = 10 -(GLfloat)j;
			ctlpoints[i][j][1] = 0.0;
			ctlpoints[i][j][2] = 10 - (GLfloat)i;
		}
	}

	for (int i = 0; i < 25; i++)
	{
		if ((0 <= i && i <= 3))
		{
			knots[i] = 0.0;
		}
		else if ((21 <= i && i <= 24)){
			knots[i] = 1.0;
		}
		else{
			knots[i] = knots[i-1] + 0.058;
		}
	}
	
	
	
}
void animacion(int value) {
	t += 0.1;


	for (int i = 0; i <21; i++) {
		for (int j = 0; j < 21; j++) {
			ctlpoints[i][j][1] = (A1 * sin( ((Dx1norm*ctlpoints[i][j][0] + Dy1norm*ctlpoints[i][j][2]) * W1) + t*S1*2*PI/L1)) + (A2 * sin( ((Dx2norm*ctlpoints[i][j][0] + Dy2norm*ctlpoints[i][j][2]) * W2) + t*S2*2*PI/L2));
		}
	}
	glutTimerFunc(10,animacion,0);
    glutPostRedisplay();	
}
void init(){
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_AUTO_NORMAL);
   glEnable(GL_NORMALIZE);

   init_surface();

   theNurb = gluNewNurbsRenderer();
   gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 15.0);
   gluNurbsProperty(theNurb, GLU_DISPLAY_MODE, GLU_FILL);

   glutTimerFunc(0, animacion, 0);
   t = 0.0;
}

void Keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
	case 27:             
		exit (0);
	break;
	case 'g':// usar grid
		if(activateGrid)
			activateGrid = false;
		else
			activateGrid = true;
	break;
	
  }
}



void render(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat zExtent, xExtent, xLocal, zLocal;
    int loopX, loopZ;

	glLoadIdentity ();                       
	gluLookAt (25.0, 12.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	

	// Luz y material

	GLfloat mat_diffuse[] = { 0.6, 0.6, 0.9, 1.0 };
	GLfloat mat_specular[] = { 0.8, 0.8, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 60.0 };
	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	

    GLfloat light_ambient[] = { 0.0, 0.0, 0.2, 1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat light_specular[] = { 0.6, 0.6, 0.6, 1.0 };
	GLfloat light_position[] = { -10.0, 5.0, 0.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);   


	
	// Render Grid
	if (activateGrid)
	{
		glDisable(GL_LIGHTING);
		glLineWidth(1.0);
		glPushMatrix();
		glRotatef(90,1.0,0.0,0.0);
		glColor3f( 0.0, 0.7, 0.7 );
		glBegin( GL_LINES );
		zExtent = DEF_floorGridScale * DEF_floorGridZSteps;
		for(loopX = -DEF_floorGridXSteps; loopX <= DEF_floorGridXSteps; loopX++ )
		{
		xLocal = DEF_floorGridScale * loopX;
		glVertex3f( xLocal, -zExtent, 0.0 );
		glVertex3f( xLocal, zExtent,  0.0 );
		}
		xExtent = DEF_floorGridScale * DEF_floorGridXSteps;
		for(loopZ = -DEF_floorGridZSteps; loopZ <= DEF_floorGridZSteps; loopZ++ )
		{
		zLocal = DEF_floorGridScale * loopZ;
		glVertex3f( -xExtent, zLocal, 0.0 );
		glVertex3f(  xExtent, zLocal, 0.0 );
		}
		glEnd();
		ejesCoordenada();
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
	// Fin Grid


	//Suaviza las lineas
	glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable( GL_LINE_SMOOTH );	

	glPushMatrix();
		gluBeginSurface(theNurb);    
			gluNurbsSurface(theNurb, 
						   25, knots, 25, knots,
						   21 * 3, 3, &ctlpoints[0][0][0], 
						   4, 4, GL_MAP2_VERTEX_3);
		gluEndSurface(theNurb);	
	glPopMatrix();
	
	/* Muestra los puntos de control */

	/*
		int i,j;
		glPointSize(5.0);
		glDisable(GL_LIGHTING);
		colorSelect("yellow");
		glBegin(GL_POINTS);
		for (i = 0; i <21; i++) {
			for (j = 0; j < 21; j++) {
	            glVertex3f(ctlpoints[i][j][0], 	ctlpoints[i][j][1], ctlpoints[i][j][2]);
			}
		}
		glEnd();
		glEnable(GL_LIGHTING);
	*/
	glDisable(GL_BLEND);
	glDisable(GL_LINE_SMOOTH);
	glutSwapBuffers();
}

int main (int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(960,540);

	glutCreateWindow("Nurbs Proyecto - Ola");

	init();

	glutReshapeFunc(changeViewport);
	glutDisplayFunc(render);
	glutKeyboardFunc (Keyboard);
		
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}
	

	glutMainLoop();
	return 0;

}
