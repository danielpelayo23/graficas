#include <iostream>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>


using namespace std;

#define DEF_floorGridScale	1.0f

#define PI 3.14159265

float floorGridXSteps	= 7.0f;
float floorGridZSteps	= 7.0f;
bool  cabeza = false;
float anguloCabeza = 0;
bool  brazoDer = false;
float brazoDerAnguloSup = 0;
float brazoDerAnguloMed = 0;
float brazoDerAnguloInf = 0;
bool brazoIzq = false;
float brazoIzqAnguloSup = 0;
float brazoIzqAnguloMed = 0;
float brazoIzqAnguloInf = 0;
bool torso = false;
float anguloTorso = 0;
bool piernaDer = false;
float piernaDerAnguloSup = 0;
float piernaDerAnguloMed = 0;
float piernaDerAnguloInf = 0;
bool piernaIzq = false;
float piernaIzqAnguloSup = 0;
float piernaIzqAnguloMed = 0;
float piernaIzqAnguloInf = 0;
bool todo = false;
bool activateGrid = false;

typedef struct
		{
	float x1,y1;
	string color;
	int lives;
		}brick;
brick br[13][5];




float ballRadius = 1;
float ballXMax, ballXMin, ballYMax, ballYMin;
float ballX = 0.0f;
float ballY = 0.0f;
float baseX = 0.0f;
float baseY = -7.0f;
float xSpeed = 0.05;
float ySpeed = 0.05;
int refreshMillis = 10;



void ejesCoordenada(float w) {
	
	glLineWidth(w);
	glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(0,10);
		glVertex2f(0,-10);
		glColor3f(0.0,0.0,1.0);
		glVertex2f(10,0);
		glVertex2f(-10,0);
	glEnd();

	glLineWidth(w-1.0);
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

void drawRectangle(float width,float height,string color){
	colorSelect(color);
	glBegin(GL_POLYGON);
			glVertex2f(-width/2, 0);
			glVertex2f(width/2,0);
			glVertex2f(width/2,height);
			glVertex2f(-width/2,height);
		glEnd();
}
void drawRectangle2(float x,float y,float width,float height,string color){
	colorSelect(color);
	glBegin(GL_POLYGON);
		glVertex2f(x -width/2, y);
		glVertex2f(x +width/2,y);
		glVertex2f(x + width/2,y+height);
		glVertex2f(x -width/2,y+height);
	glEnd();
}
void drawRectangleBorder(float width,float height,string color){
	colorSelect(color);
	glBegin(GL_LINE_LOOP);
			glVertex2f(-width/2, 0);
			glVertex2f(width/2,0);
			glVertex2f(width/2,height);
			glVertex2f(-width/2,height);
		glEnd();
}

void brickinit(int fil,int col,float xpos,float ypos){

	br[fil][col].x1=xpos;
	br[fil][col].y1=ypos;
	//br[fil][col].color=color;
	br[fil][col].lives=1;
	//drawRectangle(1.5,0.75,color);
}

void drawBoard(){
	float xpos = -6;
	float ypos =2;
	glPushMatrix();
		glPopMatrix();
	glPushMatrix();
		glTranslatef(xpos,ypos,0);
		for (int i = 0; i < 5; i++)
		{
			xpos = -6;
			glPushMatrix();
			for (int j = 0; j < 7 ; j = j++ )
			{						
				if (br[i][j].lives > 0)
				{
					drawRectangle(1.5,0.75,"green");
				}
				else{
					drawRectangle(1.5,0.75,"black");
				}
					
					xpos = xpos + 2	;
					glTranslatef(2,0,0);
			}
			glPopMatrix();
			ypos = ypos +1;
			glTranslatef(0,1,0);

		}
	glPopMatrix();

	glPushMatrix();
			glTranslatef(-7.25,-7,0);
			drawRectangle(0.5,14,"red");
	glPopMatrix();
	glPushMatrix();
			glTranslatef(0,7,0);
			drawRectangle(15,0.5,"red");
	glPopMatrix();
	glPushMatrix();
			glTranslatef(7.25,-7,0);
			drawRectangle(0.5,14,"red");
	glPopMatrix();
}



void changeViewport(int w, int h) {
	float aspectRatio;

	glViewport(0,0,w,h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	aspectRatio = (float) w / (float) h;
	if (w<=h)
		glOrtho(-13,13,-13/aspectRatio,13/aspectRatio,-1.0,1.0);
	else
		glOrtho(-13*aspectRatio,13*aspectRatio,-13,13,-1.0,1.0);

	ballXMin = -7;
	ballXMax = 7;
	ballYMin = -7;// este yMin tiene que ser solo la base que se mueve
	ballYMax = 7;
	



	float xpos = -6;
	float ypos =2;
	glPushMatrix();
		glPopMatrix();
	glPushMatrix();
		glTranslatef(xpos,ypos,0);
		for (int i = 0; i < 5; i++)
		{
			xpos = -6;
			glPushMatrix();
			for (int j = 0; j < 7 ; j = j++ )
			{						
					brickinit(i,j,xpos,ypos);
					xpos = xpos + 2	;
					glTranslatef(2,0,0);
			}
			glPopMatrix();
			ypos = ypos +1;
			glTranslatef(0,1,0);

		}
	glPopMatrix();
}

void Timer(int value){
	glutPostRedisplay();
	glutTimerFunc(refreshMillis, Timer,0);
}



void drawSquare(string color){
	colorSelect(color);
	glBegin(GL_POLYGON);
		glVertex2f(-1.0,1.0);
		glVertex2f(1.0,1.0);
		glVertex2f(1.0,-1.0);
		glVertex2f(-1.0,-1.0);
	glEnd();
}



void drawCircle(string color)
{
	colorSelect(color);
	glBegin(GL_LINES);
		for(int i =0; i <= 360; i++){
			float angle = i * PI / 180;
			float x = cos(angle);
			float y = sin(angle);
			glVertex2d(0,0);
			glVertex2d(x,y);
		}
	glEnd();
}


void drawHalfCircle(string color)
{
	colorSelect(color);
	glBegin(GL_POLYGON);
		for(int i =180; i <= 360; i++){
			float angle = i * PI / 180;
			float x = cos(angle);
			float y = sin(angle);
			glVertex2d(x,y);
		}
	glEnd();
}
void drawCircleBorder(string color)
{
	colorSelect(color);
	glBegin(GL_LINE_LOOP);
		for(int i =0; i <= 360; i++){
			float angle = i * PI / 180;
			float x = cos(angle);
			float y = sin(angle);
			glVertex2d(x,y);
		}
	glEnd();
}
void drawHalfCircle2(float xpos,float ypos,float radius, string color)
{
	colorSelect(color);
	glBegin(GL_LINE_STRIP);
		for(int i =220; i <= 320; i++){
			float angle = i * PI / 180;
			float x = xpos +radius*cos(angle);
			float y = ypos +radius*sin(angle);
			glVertex2d(x,y);
		}
	glEnd();
}
void drawTriangle(){
	glBegin(GL_TRIANGLES);
		glVertex2f(0.0,1.0);
		glVertex2f(1.0,0.0);
		glVertex2f(-1.0,0.0);
	glEnd();
}

void drawPoint(float x,float y, string color){
	colorSelect(color);
	glPointSize(5);
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
}


//observo si choca la pelota con el objeto B
// ejemplo: Pelota A(0,0), MuroSup B(0,7) width = 15, height = 0.5
//if1: 0 + 0.5 > 0 - 7.5 .... true
//if2: 0 - 0.5 < 0 + 7.5 ..... true
//if3: 0 + 0.5 > 7 ............ false
//if4: 0 - 0.5 < 7 + 0.5 ...... true
// ejemplo: Pelota A(0,6.6), MuroSup B(0,7) width = 15, height = 0.5
//if1: 0 + 0.5 > 0 - 7.5 .... true
//if2: 0 - 0.5 < 0 + 7.5 ..... true
//if3: 6.6 + 0.5 > 7 ............ true **
//if4: 6.6 - 0.5 < 7 + 0.5 ...... true
//no funciona... hay q ver la manera general de describir un choque

bool checkColission(float Ax, float Ay, float Bx, float By,float Bwidth, float Bheight){
	if(Ax < Bx - Bwidth/2){//Borde derecho de A pega con borde izquierdo de B
		return false;
	}
	else if(Ax > Bx + Bwidth/2){//Borde izquierdo de A pega con borde derecho del B // La parte izquierda de la pelota estaZ
		return false;
	}
	else if(Ay < By ){//Borde superior de A pega con borde inferior de B // La parte superior de la pelota esta por encima de la parte inferior del rectangulo
		return false;
	}
	else if( Ay>  By + Bheight){//Borde inferior de A pega con borde superior de B // La parte inferior de la pelota esta por debajo de la parte superior del rectangulo
		return false;
	}
	return true;
}


void render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GLfloat zExtent, xExtent, xLocal, zLocal;
    int loopX, loopZ;
	
	/* Render Grid */
	if (activateGrid) {
		glLineWidth(0.1);
		glPushMatrix();
		glColor3f( 0.0f, 0.7f, 0.7f );
		glBegin( GL_LINES );
			zExtent = DEF_floorGridScale * floorGridZSteps;
			for(loopX = -floorGridXSteps; loopX <= floorGridXSteps; loopX++ ){
				xLocal = DEF_floorGridScale * loopX;
				glVertex3f( xLocal, -zExtent, 0.0f );
				glVertex3f( xLocal, zExtent,  0.0f );
			}
			xExtent = DEF_floorGridScale * floorGridXSteps;
			for(loopZ = -floorGridZSteps; loopZ <= floorGridZSteps; loopZ++ ){
				zLocal = DEF_floorGridScale * loopZ;
				glVertex3f( -xExtent, zLocal, 0.0f );
				glVertex3f(  xExtent, zLocal, 0.0f );
			}
		glEnd();
		glPopMatrix();
	}
	
	drawBoard();
	//ejesCoordenada(4);
	/*Fin*/
	glPushMatrix();
	glTranslatef(0,ballYMin,0);
	//ejesCoordenada(4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,ballYMax + 1,0);
	//ejesCoordenada(4);
	glPopMatrix();
glPushMatrix();
	glTranslatef(ballXMin  - 1,0,0);
	//ejesCoordenada(4);
	glPopMatrix();

	glPushMatrix();
	//glTranslatef(0,ballYMin-1,0);
	//ejesCoordenada(4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(baseX,baseY,0);
	drawRectangle(4,0.5,"yellow");
	//ejesCoordenada(4);
	glPopMatrix();

	

	glPushMatrix();
	glTranslatef(ballX,ballY,0.0f);
	glScalef(0.5,0.5,1);
	drawCircle("white");
	drawCircleBorder("black");
	glScalef(1.5,1.5,1);
	//glutSwapBuffers();
	//ejesCoordenada(4);
	glPopMatrix();


	ballX += xSpeed;
	ballY += -ySpeed;
	if (checkColission(ballX + 0.5,ballY,7.25,ballYMin,0.5,14)==true){ //Borde derecho de la pelota pega con la pared derecha
		xSpeed= -xSpeed;
	}
	if (checkColission(ballX - 0.5,ballY,-7.25,ballYMin,0.5,14)==true){ //Borde izquierdo de la pelota pega con la pared izquierda
		xSpeed= -xSpeed;
	}
	
	if (checkColission(ballX,ballY+0.5,0,7,15,0.5)==true){ ////Borde superior de la pelota pega con la pared superior
		//ballY=ballYMax;
		ySpeed= -ySpeed;
	}

	if (checkColission(ballX,ballY-0.5,baseX,baseY,4,0.5)==true ){ // pega en la parte superior de la base

		ySpeed= -ySpeed;
		float t = ((ballX - baseX) / 4);
		if(t<0 && ballX < ballX + xSpeed){ // Chequear en que lado de la base pego la pelota
			xSpeed = -xSpeed;
		}
		else if(t>0 && ballX > ballX + xSpeed){
			xSpeed = -xSpeed;
		}
	}
	if (checkColission(ballX,ballY-0.5,0,-8,14,1)==true ){//Borde Inferior de la pelota pega con la pared inferior
		ballY=0;
		ballX =0;
		ySpeed= -ySpeed;
	}

	drawPoint(0,0,"yellow");
	for (int i = 0; i < 5; i++)
	{
		
		for (int j = 0; j < 7 ; j++)
		{
			
			/*glPushMatrix();
			glTranslatef(i,j,0);
			ejesCoordenada(2);
			glPopMatrix();*/
			if (checkColission(ballX,ballY + 0.5,br[i][j].x1,br[i][j].y1,1.5,0.75))
			{
				if(br[i][j].lives > 0){
					ySpeed= -ySpeed;
					br[i][j].lives = br[i][j].lives - 1;
				}
				else{
					ySpeed = ySpeed;
				}
			}	
					
		}
					
	}

	if (baseX +2 > ballXMax)
	{
		baseX = ballXMax - 2;
	}
	else if (baseX -2 < -ballXMax)
	{
		baseX = -ballXMax + 2;
	}

	glPushMatrix();
	glTranslatef(0,7,0);
	//ejesCoordenada(2);
	glPopMatrix();

	


	glutSwapBuffers();
}



void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 033: // Escape 
			glutLeaveMainLoop();
			break;
		case '0':
			// sin seleccion
			piernaDer = false;
			piernaIzq = false;
			brazoDer = false;
			brazoIzq = false;
			cabeza = false;
			torso = false;
			todo = false;
			glPopMatrix();
			
			break;
		case '9':
			// selecciono todo para pintar todo de blanco
			piernaDer = false;
			piernaIzq = false;
			brazoDer = false;
			brazoIzq = false;
			cabeza = false;
			torso = false;
			todo = true;
			glPopMatrix();
			
			break;

		case 'g':
			// usar grid
			if(activateGrid)
				activateGrid = false;
			else
				activateGrid = true;

			glPopMatrix();
			
			break;
		case '1':
			// selecciona pierna derecha
			piernaDer = true;
			piernaIzq = false;
			brazoDer = false;
			brazoIzq = false;
			cabeza = false;
			torso = false;
			todo = false;
			glPopMatrix();
			
			break;
		case '2':
			// selecciona pierna izquierda
			piernaDer = false;
			piernaIzq = true;
			brazoDer = false;
			brazoIzq = false;
			cabeza = false;
			torso = false;
			todo = false;
			break;
		case '3':
			// selecciona brazo derecho
			piernaDer = false;
			piernaIzq = false;
			brazoDer = true;
			brazoIzq = false;
			cabeza = false;
			torso = false;
			todo = false;
			break;
		case '4':
			// selecciona brazo izquierdo
			piernaDer = false;
			piernaIzq = false;
			brazoDer = false;
			brazoIzq = true;
			cabeza = false;
			torso = false;
			todo = false;
			break;
		case '5':
			// selecciona cabeza
			
			break;
		case '6':
			// selecciona torso
			piernaDer = false;
			piernaIzq = false;
			brazoDer = false;
			brazoIzq = false;
			cabeza = false;
			torso = true;
			todo = false;
			break;	
		case 'a':
		case 'A':
			if (piernaDer){//X DER
				ballXMax += 1;}
			else if (piernaIzq){// X IZQ
				ballXMin += 1;}
			else if (brazoDer){ //Y SUP
				ballYMax += 1;}
			else if (brazoIzq){// Y INF
				ballYMin += 1;}
			break;
		case 'z':
		case 'Z':
			if (piernaDer){
				ballXMax += -1;}
			else if (piernaIzq){
				ballXMin += -1;}
			else if (brazoDer){
				ballYMax += -1;}
			else if (brazoIzq){
				ballYMin += -1;}
			break;
		case 's':
		case 'S':
			baseX +=0.5;
			break;
		case 'x':
		case 'X':
			baseX +=-0.5;
			break;
		case 'd':
		case 'D':
			if (piernaDer){
				piernaDerAnguloInf += 5;}
			else if (piernaIzq){
				piernaIzqAnguloInf += 5;}
			else if(brazoDer){
				brazoDerAnguloInf += 5;}
			else if(brazoIzq){
				brazoIzqAnguloInf += 5;}
			break;
		case 'c':
		case 'C':
			if (piernaDer){
				piernaDerAnguloInf += -5;}
			else if (piernaIzq){
				piernaIzqAnguloInf += -5;}
			else if(brazoDer){
				brazoDerAnguloInf += -5;}
			else if(brazoIzq){
				brazoIzqAnguloInf += -5;}
			break;

	}
	
	glutPostRedisplay();
}

int main (int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(800,600);

	glutCreateWindow("Opengl");

	glutReshapeFunc(changeViewport);
	glutDisplayFunc(render);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(0,Timer,0);
	
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}
	
	//glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
	

	return 0;

}