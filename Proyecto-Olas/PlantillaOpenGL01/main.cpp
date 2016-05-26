
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;

#define DEF_floorGridScale	1.0
#define DEF_floorGridXSteps	10.0
#define DEF_floorGridZSteps	10.0

GLfloat knots01[8] = {
	0.0,0.0,0.0,0.0,1.0,1.0,1.0,1.0
};

GLfloat knots02[9] = {
	0.0,0.0,0.0,0.0,0.5,1.0,1.0,1.0,1.0
};

GLfloat ctrlpointsCurveNurbs01[4][3] = {
	{-10.0,0.0,0.0},{-5.0,0.0,0.0},
	{5.0,0.0,8.0}, {10.0,0.0,0.0}
};

GLfloat ctrlpointsCurveNurbs02[5][3] = {
	{-2.0,2.0,0.0},{-1.0,2.0,2.0},
	{1.0,2.0,-2.0}, {2.0,2.0,0.0},{2.0,2.0,1.0}
};

GLfloat ctrPoints01[4][3] = {
	{-4.0,0.0,0.0},{-2.0,2.0,0.0},{4.0,0.0,0.0},{2.0,2.0,0.0}
};

GLfloat ctlpointsNurbsSurf[4][4][3];
GLfloat knotsSurfs[8] = {
	0.0,0.0,0.0,0.0,1.0,1.0,1.0,1.0
};

GLUnurbsObj *theNurb01, *theNurb02, *theNurbSurf;
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
	aspectratio = (float) w / (float) h;
	/*
	if (h==0)
		h=1;
	if (w<=h)
		glOrtho(-10,10,-10/aspectratio,10/aspectratio,1.0,-1.0);
	else
		glOrtho(-10*aspectratio,10*aspectratio,-10,10,1.0,-1.0);
	*/
	
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(30,aspectratio,1.0, 200.0);
   

}

void init_surface() {
	 ctlpointsNurbsSurf[0][0][0] = 2.0;
	 ctlpointsNurbsSurf[0][0][1] = 0.0;
	 ctlpointsNurbsSurf[0][0][2] = 2.0;

	 ctlpointsNurbsSurf[0][1][0] = 1.0;
	 ctlpointsNurbsSurf[0][1][1] = 0.0;
	 ctlpointsNurbsSurf[0][1][2] = 2.0;

	 ctlpointsNurbsSurf[0][2][0] = -1.0;
	 ctlpointsNurbsSurf[0][2][1] = 0.0;
	 ctlpointsNurbsSurf[0][2][2] = 2.0;

	 ctlpointsNurbsSurf[0][3][0] = -2.0;
	 ctlpointsNurbsSurf[0][3][1] = 0.0;
	 ctlpointsNurbsSurf[0][3][2] = 2.0;

	 ctlpointsNurbsSurf[1][0][0] = 2.0;
	 ctlpointsNurbsSurf[1][0][1] = 0.0;
	 ctlpointsNurbsSurf[1][0][2] = 1.0;

	 ctlpointsNurbsSurf[1][1][0] = 1.0;
	 ctlpointsNurbsSurf[1][1][1] = 0.0;
	 ctlpointsNurbsSurf[1][1][2] = 1.0;

	 ctlpointsNurbsSurf[1][2][0] = -1.0;
	 ctlpointsNurbsSurf[1][2][1] = 0.0;
	 ctlpointsNurbsSurf[1][2][2] = 1.0;

	 ctlpointsNurbsSurf[1][3][0] = -2.0;
	 ctlpointsNurbsSurf[1][3][1] = 0.0;
	 ctlpointsNurbsSurf[1][3][2] = 1.0;

	 ctlpointsNurbsSurf[2][0][0] = 2.0;
	 ctlpointsNurbsSurf[2][0][1] = 0.0;
	 ctlpointsNurbsSurf[2][0][2] = -1.0;

	 ctlpointsNurbsSurf[2][1][0] = 1.0;
	 ctlpointsNurbsSurf[2][1][1] = 0.0;
	 ctlpointsNurbsSurf[2][1][2] = -1.0;

	 ctlpointsNurbsSurf[2][2][0] = -1.0;
	 ctlpointsNurbsSurf[2][2][1] = 0.0;
	 ctlpointsNurbsSurf[2][2][2] = -1.0;

	 ctlpointsNurbsSurf[2][3][0] = -2.0;
	 ctlpointsNurbsSurf[2][3][1] = 0.0;
	 ctlpointsNurbsSurf[2][3][2] = -1.0;

	 ctlpointsNurbsSurf[3][0][0] = 2.0;
	 ctlpointsNurbsSurf[3][0][1] = 0.0;
	 ctlpointsNurbsSurf[3][0][2] = -2.0;

	 ctlpointsNurbsSurf[3][1][0] = 1.0;
	 ctlpointsNurbsSurf[3][1][1] = 0.0;
	 ctlpointsNurbsSurf[3][1][2] = -2.0;

	 ctlpointsNurbsSurf[3][2][0] = -1.0;
	 ctlpointsNurbsSurf[3][2][1] = 0.0;
	 ctlpointsNurbsSurf[3][2][2] = -2.0;

	 ctlpointsNurbsSurf[3][3][0] = -2.0;
	 ctlpointsNurbsSurf[3][3][1] = 0.0;
	 ctlpointsNurbsSurf[3][3][2] = -2.0;

}

void changePoints(int value){
	t+=0.1;
	ctlpointsNurbsSurf[1][1][1] =3*sin(t);
	ctlpointsNurbsSurf[1][2][1] =-3*sin(t);
	ctlpointsNurbsSurf[2][1][1] =-3*sin(t);
	ctlpointsNurbsSurf[2][2][1] =3*sin(t);

	glutTimerFunc(10,changePoints,1);
	glutPostRedisplay();
}

void init(){



   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_AUTO_NORMAL);
   glEnable(GL_NORMALIZE);
   theNurb01 = gluNewNurbsRenderer();
   theNurb02 = gluNewNurbsRenderer();
   gluNurbsProperty(theNurb01, GLU_SAMPLING_TOLERANCE, 25.0);
   gluNurbsProperty(theNurb02, GLU_SAMPLING_TOLERANCE, 25.0);

   theNurbSurf = gluNewNurbsRenderer();
   gluNurbsProperty(theNurbSurf, GLU_SAMPLING_TOLERANCE, 25.0);
   gluNurbsProperty(theNurbSurf, GLU_DISPLAY_MODE, GLU_FILL);
   init_surface();

   //ctlpointsNurbsSurf[1][1][1] = 3.0;
   //ctlpointsNurbsSurf[1][2][1] = 3.0;
   //ctlpointsNurbsSurf[2][1][1] = 3.0;
   //ctlpointsNurbsSurf[2][2][1] = 3.0;


   glEnable(GL_DEPTH_TEST);
   glEnable(GL_AUTO_NORMAL);
   glEnable(GL_NORMALIZE);

   glutTimerFunc(10,changePoints,1);
   t=0.0;

}



void Keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
	case 27:             
		exit (0);
		break;
	
  }
}



void render(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat zExtent, xExtent, xLocal, zLocal;
    int loopX, loopZ;

	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();                       
	//gluLookAt (25.0, 12.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	gluLookAt (10.0, 5.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	const GLfloat pos[]= {10.0,10.0,0.0,0.0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);
	glEnable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	

	// Luz y material
	glEnable(GL_LIGHT0);
	GLfloat mat_diffuse[] = { 1.0, 0.5, 0.5, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 100.0 };
	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	gluBeginSurface(theNurbSurf);
	gluNurbsSurface(theNurbSurf,
					8,knotsSurfs,8,knotsSurfs,
					4*3,3,&ctlpointsNurbsSurf[0][0][0],
					4,4,GL_MAP2_VERTEX_3);
	gluEndSurface(theNurbSurf);
	
	/*
    GLfloat light_ambient[] = { 1.0, 0.5, 0.5, 1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { -10.0, 5.0, 0.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);   
	*/
	//glutSolidSphere(4,30,30);



	
	// Render Grid 
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
	// Fin Grid
	glColor3f(0.0,1.0,0.0);
	glPointSize(10.0);
	glBegin(GL_POINTS);
		glVertex2f(0.0,0.0);
	glEnd();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LINE_SMOOTH);
	
	//Bezier
	glMap1f(GL_MAP1_VERTEX_3, 0.0,1.0,3,4, &ctrPoints01[0][0]);
	glEnable(GL_MAP1_VERTEX_3);

	int i;
	float res = 20.0f; //resolucion de la curva
	glColor3f(1.0,1.0,0.0);

	glBegin(GL_LINE_STRIP);
	for (i=0; i<=res; i++) {
		glEvalCoord1f((GLfloat) i / res);
	}
	glEnd();

	//Grafica ptos de control

	glPointSize(5.0);
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_POINTS);
		for (i=0; i<4; i++){
			glVertex3fv(&ctrPoints01[i][0]);
		}
	glEnd();
	
	glPushMatrix();

	//CurvaNurbs
	glColor3f(0.0,1.0,0.0);
	gluBeginCurve(theNurb01);
		gluNurbsCurve(theNurb01,8,knots01,3,&ctrlpointsCurveNurbs01[0][0],4,GL_MAP1_VERTEX_3);
	gluEndCurve(theNurb01);

	gluBeginCurve(theNurb02);
		gluNurbsCurve(theNurb02,8,knots02,3,&ctrlpointsCurveNurbs02[0][0],4,GL_MAP1_VERTEX_3);
	gluEndCurve(theNurb02);

	glPopMatrix();		

	glDisable(GL_BLEND);
	glDisable(GL_LINE_SMOOTH);

	glutSwapBuffers();
}

void animacion(int value) {
	
	glutTimerFunc(10,animacion,1);
    glutPostRedisplay();
	
}

int main (int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(960,540);

	glutCreateWindow("Nurbs Proyecto - Ola");

	init ();

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