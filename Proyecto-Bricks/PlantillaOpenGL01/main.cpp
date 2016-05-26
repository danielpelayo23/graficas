#include <iostream>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>
#include <ctime>



using namespace std;

#define DEF_floorGridScale	1.0f

#define PI 3.14159265

float floorGridXSteps	= 15.0f;
float floorGridZSteps	= 15.0f;
bool activateGrid = false;
float ballXMax, ballXMin, ballYMax, ballYMin;
float ballX;
float ballY;
float winExplodeX = 0;
float winExplodeY = 0;
float xSpeed = 0.0;
float ySpeed = 0.0;
float speedbonus = 0;
int refreshMillis = 10;
int duros[5];
int especiales[6];
bool gameActive = false;
bool gamePaused = false;
bool gameOver = false;
bool gameWin = false;
int totalLives;

typedef struct
		{
	float x1,y1;
	string color;
	int lives;
	bool bonus;
	bool bonusreduce;
	bool bonusacc;
	bool agarrobonus;
	bool duro;
	float xbonus,ybonus;
	float xexp,yexp;

		}brick;
brick br[5][7];
typedef struct
		{
	float x1,y1;
	string color;
	int lives;
	float height;
	float width;
	bool bonusreduce;
	bool bonusacc;
		}base;
base bs;







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

bool checkColission2(float Ax, float Ay, float Bx, float By,float Bwidth, float Bheight){
	if(sqrt(pow((Ax)-(Bx - Bwidth/2),2) + pow((Ay)-(By + Bheight),2)) < 0.25){
		return true;	
	}
	else if(sqrt(pow((Ax)-(Bx + Bwidth/2),2) + pow((Ay)-(By + Bheight),2)) < 0.25){
		return true;	
	}
	else if(sqrt(pow((Ax)-(Bx - Bwidth/2),2) + pow((Ay)-(By),2)) < 0.25){
		return true;	
	}
	else if(sqrt(pow((Ax)-(Bx + Bwidth/2),2) + pow((Ay)-(By),2)) < 0.25){
		return true;	
	}
	return false;
}

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
void drawText(float x, float y, std::string text,string color) {
	colorSelect(color);
	glRasterPos2f(x, y);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
	
}
void drawText2(float x, float y, std::string text,string color) {
	colorSelect(color);
	glRasterPos2f(x, y);
	glutBitmapString(GLUT_BITMAP_9_BY_15, (const unsigned char*)text.c_str());
    
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

void drawBrokenRectangle(float width,float height,string color){
	colorSelect(color);
	glBegin(GL_POLYGON);
			glVertex2f(-width/2, 0);
			glVertex2f(width/2,0);
			glVertex2f(width/2,height/2);
			glVertex2f(-width/2,height/2);
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

void drawBonus1(string color,brick br){

	colorSelect(color);	

	
	if (br.y1 > ballYMin + 0.75)
	{
		glPushMatrix();
		glTranslatef(0,br.ybonus,0);
		//ejesCoordenada(2);
		glScalef(0.25,0.25,1);
		drawCircle(color);
		colorSelect("red");
		glBegin(GL_POLYGON);
			glVertex2f(0,0.75);
			glVertex2f(-0.75,0);
			glVertex2f(0,-0.75);
			glVertex2f(0.75,0);
		glEnd();
		glScalef(4,4,1);
		glPopMatrix();
	}	
	
	if((br.y1-0.25 < -6.95) && (br.x1  > bs.x1-bs.width/2) && (br.x1  < bs.x1+bs.width/2) && (br.y1-0.25 > -7)){

		if (br.bonusreduce)
		{
			printf("<<<<AGARRE EL BONUSS REDUCIR>>>>(%f)\n",br.y1);
			bs.width = bs.width*0.85;
		}
		else if(br.bonusacc){
			printf("<<<<AGARRE EL BONUSS ACELERAR>>>>(%f)\n",br.y1);
			ySpeed = ySpeed*1.40;
			xSpeed = xSpeed*1.40;
		}

		
		
		}
	/*if((checkColission(br.x1,br.y1,bs.x1,bs.y1,bs.width,bs.height)) && (br.bonusacc) && (br.bonus)){
		br.agarrobonus = true;
		br.speedbonus=0;
		br.bonus = false;
		printf("<<<<AGARRE EL BONUSS ACELERAR>>>>(%f)\n",br.y1);
		ySpeed = ySpeed*1.40;
		xSpeed = xSpeed*1.40;
		}*/
	

	
}

void drawExplosion2(float x,float y){
		
		if (x<1 || y<1){
			glPushMatrix();
					glTranslatef(0.5*(x),-(y),0);
					glScalef(0.20,0.20,1);
					drawCircleBorder("green");
				glPopMatrix();
				glPushMatrix();
					glTranslatef((x),0.5*(y),0);
					glScalef(0.20,0.20,1);
					drawCircleBorder("red");
				glPopMatrix();
				glPushMatrix();
					glTranslatef(0.5*(x),(y),0);
					glScalef(0.2,0.20,1);
					drawCircleBorder("yellow");
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-(x)+0.02,0,0);
					glScalef(0.20,0.20,1);
					drawCircleBorder("white");
				glPopMatrix();
				glPushMatrix();
					glTranslatef(x,y,0);
					glScalef(0.20,0.20,1);
					drawCircleBorder("orange");
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-0.5*(y),y,0);
					glScalef(0.20,0.20,1);
					drawCircleBorder("blue");
				glPopMatrix();		
		}
}
void drawExplosion(brick br){
		
		if (br.xexp>1){
			br.duro = false;
			br.xexp = 0;			
		}
		else if(br.yexp > 1){
			br.duro = false;
			br.yexp = 0;
		}
		else{
			glPushMatrix();
					glTranslatef(0.5*(br.xexp),-(br.yexp),0);
					glScalef(0.20,0.20,1);
					drawCircleBorder("green");
				glPopMatrix();
				glPushMatrix();
					glTranslatef((br.xexp),0.5*(br.yexp),0);
					glScalef(0.20,0.20,1);
					drawCircleBorder("red");
				glPopMatrix();
				glPushMatrix();
					glTranslatef(0.5*(br.xexp),(br.yexp),0);
					glScalef(0.2,0.20,1);
					drawCircleBorder("yellow");
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-(br.xexp)+0.02,0,0);
					glScalef(0.20,0.20,1);
					drawCircleBorder("white");
				glPopMatrix();
				glPushMatrix();
					glTranslatef(br.xexp,br.yexp,0);
					glScalef(0.20,0.20,1);
					drawCircleBorder("orange");
				glPopMatrix();
				glPushMatrix();
					glTranslatef(-0.5*(br.yexp),br.yexp,0);
					glScalef(0.20,0.20,1);
					drawCircleBorder("blue");
				glPopMatrix();
		}
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

void brickinit(int fil,int col,float xpos,float ypos,bool duro, bool bonus, bool bonusreduce,bool bonusacc){

	br[fil][col].x1=xpos;
	br[fil][col].y1=ypos;
	//br[fil][col].color=color;
	
	br[fil][col].duro=duro;
	br[fil][col].bonus=bonus;
	if (duro)
	{
		br[fil][col].lives=2;
		br[fil][col].xexp=0;
		br[fil][col].yexp=0;
	}
	else{
		br[fil][col].lives=1;
	}
	if(bonus){
		br[fil][col].xbonus=0;
		br[fil][col].ybonus=0;
		br[fil][col].bonusreduce= bonusreduce;
		br[fil][col].bonusacc= bonusacc;
		br[fil][col].agarrobonus= false;
	}
}
void baseinit(){
	bs.x1 = 0;
	bs.y1 = -7;
	bs.lives = 5;
	bs.color = "yellow";
	bs.width = 4;
	bs.height = 0.5;
	bs.bonusreduce = false;
	bs.bonusacc = false;
}

void drawPoint(float x,float y, string color){
	colorSelect(color);
	glPointSize(5);
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
}

void resetExplosion(){

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7 ; j++ )
			{		
					br[i][j].xexp = 0;
					br[i][j].yexp = 0;		
			}
		}
}

void winExplode(){
	float xpos = -6;
	float ypos =2;
	glPushMatrix();
		glTranslatef(xpos,ypos,0);
		for (int i = 0; i < 5; i++)
		{
			xpos = -6;
			glPushMatrix();
			for (int j = 0; j < 7 ; j++ )
			{		
				

				drawExplosion2(winExplodeX,winExplodeY);
				winExplodeX += 0.001;
				winExplodeY += 0.001;
				xpos = xpos + 2	;
				glTranslatef(2,0,0);			
			}
			glPopMatrix();
			ypos = ypos +1.25;
			glTranslatef(0,1.25,0);

		}
	glPopMatrix();
}

bool checkWin(){
	bool allDead = false;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7 ; j++ )
			{						
				if (br[i][j].lives<=0){
					allDead = true;
				}
				else{
					allDead = false;
					break;
				}
			}
			if (allDead==false){
				break;
			}		
		
		}
		return allDead;
}
void drawBoard(){
	float xpos = -6;
	float ypos =2;
	
	glPushMatrix();
		glTranslatef(xpos,ypos,0);
		for (int i = 0; i < 5; i++)
		{
			xpos = -6;
			glPushMatrix();
			for (int j = 0; j < 7 ; j++ )
			{						
				if (br[i][j].lives > 0)
				{
					
					if (br[i][j].duro && br[i][j].lives == 2)
					{
						drawRectangle(1.5,0.75,"orange");
					}
					else if (br[i][j].duro && br[i][j].lives == 1)
					{
						drawBrokenRectangle(1.5,0.75,"red");
					}
					else{
						drawRectangle(1.5,0.75,"green");}
				}
				else
				{
						//drawRectangle(1.5,0.75,"black");
						if(br[i][j].bonus){
							if (gameActive)
							{
								br[i][j].ybonus += -speedbonus;
								br[i][j].y1 += -speedbonus;
							}

							drawBonus1("yellow",br[i][j]);
						}
						if(br[i][j].duro && br[i][j].xexp < 1 && br[i][j].yexp < 1){
							if (gameActive){
								drawExplosion(br[i][j]);
								br[i][j].xexp += 0.04;
								br[i][j].yexp += 0.02;
							}
						}
				}

					
					xpos = xpos + 2	;
					glTranslatef(2,0,0);
					
			}
			glPopMatrix();
			ypos = ypos +1.25;
			glTranslatef(0,1.25,0);

		}
	glPopMatrix();

	glPushMatrix();
			glTranslatef(-9.25,-7,0);
			drawRectangle(0.5,16,"red");
	glPopMatrix();
	glPushMatrix();
			glTranslatef(0,9,0);
			drawRectangle(19,0.5,"red");
	glPopMatrix();
	glPushMatrix();
			glTranslatef(9.25,-7,0);
			drawRectangle(0.5,16,"red");
	glPopMatrix();
}

void setAllExpPos(){



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


}


void initialization(){
	ballXMin = -9;
	ballXMax = 9;
	ballYMin = -7;// este yMin tiene que ser solo la base que se mueve
	ballYMax = 9;
	baseinit();
	ySpeed = -0.05;
	xSpeed = 0.05;
	speedbonus = 0.05;
	ballX = 0;
	ballY = -6;
	winExplodeX = 0;
	winExplodeY = 0;
	totalLives = 40;
	
	int e;
	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
			e = rand()%35;
			if (i == 0){
				duros[i] = e;
			}
			else{
				for (int j = 0; j < i; j++)
				{
					if (duros[j] == e)
					{
						j = -1;
						e = rand()%35;
					}
					else{
						duros[i] = e;
					}
				}
			
			}
			printf("%d ",duros[i]);		
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
			e = rand()%35;
			if (i == 0){
				especiales[i] = e;
			}
			else{
				for (int j = 0; j < i; j++)
				{
					if (especiales[j] == e)
					{
						j = -1;
						e = rand()%35;
					}
					else{
						especiales[i] = e;
					}
				}
			
			}
			printf("%d ",especiales[i]);		
	}
	printf("\n");


	float xpos = -6;
	float ypos =2;
	int aux = 0;
	bool duro = false;
	bool bonus = false;
	bool bonusacc = false;
	bool bonusreduce = false;
	int aux_especiales=0;
	glPushMatrix();
		glPopMatrix();
	glPushMatrix();
		glTranslatef(xpos,ypos,0);
		for (int i = 0; i < 5; i++)
		{
			xpos = -6;
			glPushMatrix();
			for (int j = 0; j < 7 ; j++ )
			{						

				for (int x = 0; x < 5; x++) //veremos si estamos en la posicion que hay un bloque duro
				{
					if (aux == duros[x])
					{
						duro = true;
					}
				}
				for (int y = 0; y < 6; y++) //veremos si estamos en la posicion que hay un bloque con bonus
				{
					if (aux == especiales[y])
					{
						bonus = true;
						if(aux_especiales < 3){
							bonusreduce = true;
						}
						else{
							bonusacc = true;
						}
						aux_especiales++;
					}

				}
				brickinit(i,j,xpos,ypos,duro,bonus,bonusreduce,bonusacc);
				printf("(%f,%f) %d \n",br[i][j].x1,br[i][j].y1,br[i][j].lives);
				xpos = xpos + 2	;
				aux++;
				glTranslatef(2,0,0);
				duro = false;
				bonus = false;
				bonusreduce = false;
				bonusacc = false;
				
					
			}
			printf("\n");
			glPopMatrix();
			ypos = ypos +1.25;
			glTranslatef(0,1.25,0);

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






void render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GLfloat zExtent, xExtent, xLocal, zLocal;
    int loopX, loopZ;
	float xpos = -6;
	float ypos = 2;
	
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
	
	glPushMatrix();
	glTranslatef(ballX,ballY,0.0f);
	glScalef(0.25,0.25,1);
	drawCircle("white");
	drawCircleBorder("black");
	glScalef(4,4,1);
	glPopMatrix();

	if(gameActive){
		ballX += xSpeed;
		ballY += -ySpeed;
	}



	glPushMatrix();
	glTranslatef(bs.x1,bs.y1,0);
	drawRectangle(bs.width,bs.height,"yellow");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10,-6.75,0);
	glScalef(0.25,0.25,1);
	if(bs.lives >= 1){
		drawCircle("white");
	}	
	glScalef(4,4,1);
	glTranslatef(1,0,0);
	glScalef(0.25,0.25,1);
	if(bs.lives >= 2){
		drawCircle("white");
	}
	glScalef(4,4,1);
	glTranslatef(1,0,0);
	glScalef(0.25,0.25,1);
	if(bs.lives >= 3){
		drawCircle("white");
	}
	glScalef(4,4,1);
		glTranslatef(1,0,0);
	glScalef(0.25,0.25,1);
	if(bs.lives >= 4){
		drawCircle("white");
	}
	glScalef(4,4,1);
		glTranslatef(1,0,0);
	glScalef(0.25,0.25,1);
	if(bs.lives >= 5){
		drawCircle("white");
	}
	glScalef(4,4,1);
	//ejesCoordenada(4);
	glPopMatrix();


	


	
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7 ; j++ )
			{								
				
				if (checkColission(ballX,ballY + 0.25,br[i][j].x1,br[i][j].y1,1.5,0.75)){
				
					if(br[i][j].lives > 0){
						totalLives--;
						br[i][j].lives = br[i][j].lives - 1;
						ySpeed= -ySpeed;

						//printf("PEGUE CON EL BLOQUE (%f,%f)!!! le quedan %d vidas\n",br[i][j].x1,br[i][j].y1,br[i][j].lives);
					}				

				}
				if (checkColission(ballX,ballY - 0.25,br[i][j].x1,br[i][j].y1,1.5,0.75)){
				
					if(br[i][j].lives > 0){
						totalLives--;
						br[i][j].lives = br[i][j].lives - 1;
						ySpeed= -ySpeed;
						//printf("PEGUE CON EL BLOQUE (%f,%f)!!! le quedan %d vidas\n",br[i][j].x1,br[i][j].y1,br[i][j].lives);

					}
				}
				if (checkColission(ballX+0.25,ballY,br[i][j].x1,br[i][j].y1,1.5,0.75)){
				
					if(br[i][j].lives > 0){
						totalLives--;
						br[i][j].lives = br[i][j].lives - 1;
						xSpeed= -xSpeed;
						//printf("PEGUE CON EL BLOQUE (%f,%f)!!! le quedan %d vidas\n",br[i][j].x1,br[i][j].y1,br[i][j].lives);
					}
				}	
				if (checkColission(ballX-0.25,ballY,br[i][j].x1,br[i][j].y1,1.5,0.75)){
				
					if(br[i][j].lives > 0){
						totalLives--;
						br[i][j].lives = br[i][j].lives - 1;
						xSpeed= -xSpeed;
						//printf("PEGUE CON EL BLOQUE (%f,%f)!!! le quedan %d vidas\n",br[i][j].x1,br[i][j].y1,br[i][j].lives);
					}
				}					
				if (checkColission2(ballX,ballY,br[i][j].x1,br[i][j].y1,1.5,0.75)){
				
					if(br[i][j].lives > 0){
						totalLives--;
						br[i][j].lives = br[i][j].lives - 1;
						//xSpeed= -xSpeed;
						//ySpeed= -ySpeed;
						//printf("PEGUE CON EL BLOQUE (%f,%f) EN LA ESQUINA!!!!! le quedan %d vidas\n",br[i][j].x1,br[i][j].y1,br[i][j].lives);
						float t = ((ballX - br[i][j].x1) / 1.5);
						float t2 = ((ballY - br[i][j].y1) / 0.5);
						if(t<0 && ballX < ballX + xSpeed){ // Chequear en que lado de la base pego la pelota
							xSpeed = -xSpeed;
						}
						else if(t>0 && ballX > ballX + xSpeed){
							xSpeed = -xSpeed;
						}
						if (t2<0 && ballY > ballY + ySpeed)
						{
							ySpeed = -ySpeed;
						}
						else if (t2>0 && ballY < ballY + ySpeed)
						{
							ySpeed = -ySpeed;
						}
						else if(t == 0){
							ySpeed = -ySpeed;						
						}
						else if(t2 == 0){
							xSpeed = -xSpeed;						
						}
					}

				}	
			}
		}
	if (ballX + 0.25 > ballXMax){ //Borde derecho de la pelota pega con la pared derecha
		ballX = ballXMax - 0.25;
		xSpeed= -xSpeed;
	}
	if (ballX - 0.25 < ballXMin){ //Borde izquierdo de la pelota pega con la pared izquierda
		ballX = ballXMin + 0.25;
		xSpeed= -xSpeed;
	}
	
	if (ballY + 0.25 > ballYMax){ ////Borde superior de la pelota pega con la pared superior

		ballY = ballYMax - 0.25;
		ySpeed= -ySpeed;
		
	}

	if (checkColission(ballX,ballY-0.25,bs.x1,bs.y1,bs.width,bs.height)==true ){ // pega en la parte superior de la base

		ySpeed= -ySpeed;
		float t = ((ballX - bs.x1) / 4);
		if(t<0 && ballX < ballX + xSpeed){ // Chequear en que lado de la base pego la pelota
			xSpeed = -xSpeed;
		}
		else if(t>0 && ballX > ballX + xSpeed){
			xSpeed = -xSpeed;
		}
	}
	if (checkColission2(ballX,ballY,bs.x1,bs.y1,bs.width,bs.height)==true ){ // pega en la esquina de la base
		
		ballY=-6;
		ySpeed= -ySpeed;
		//drejesCoordenada(2);
		
		//printf("PEGUE CON EN LA ESQUINA!!!!! le quedan \n");

		float t = ((ballX - bs.x1) / 4);
		if(t<0 && ballX < ballX + xSpeed){ // Chequear en que lado de la base pego la pelota
			xSpeed = -xSpeed;
		}
		else if(t>0 && ballX > ballX + xSpeed){
			xSpeed = -xSpeed;
		}
	}
	if (ballY-0.25 < ballYMin){//Borde Inferior de la pelota pega con la pared inferior
		ballY=-6.25;
		ballX = bs.x1;
		bs.lives--;
		if(bs.lives == 0){
			initialization();
			gameActive = false;
			gameOver = true;

		}
		ySpeed= -0.05;
		xSpeed = -0.05;	
	}

	if (checkWin() && gameOver == false){
		winExplode();
		gameWin=true;
		gameActive=false;
		drawText2(-1.4,0,"YOU WIN","green");
		drawText2(-6.5,-1,"Press Spacebar to play a New Game.","green");
		
	}
			//drawText2(-1.4,0,"YOU WIN","green");
		//drawText2(-6.5,-1,"Press Spacebar to play a New Game.","green");
	//	winExplode();
	//winExplode();

	if (bs.x1 + bs.width/2 > ballXMax)
	{
		bs.x1 = ballXMax - bs.width/2;
	}
	else if (bs.x1 -bs.width/2 < -ballXMax)
	{
		bs.x1 = -ballXMax + bs.width/2;
	}

	if (gameActive == false && gameOver)
	{
		glPushMatrix();
		drawText2(-2,0,"GAME OVER","green");
		drawText(-3.75,-1,"Press Spacebar to Play","green");
		glPopMatrix();

	}
	if (gameActive == false && gamePaused && gameWin == false)
	{
		glPushMatrix();
		drawText2(-1.1,0,"PAUSED","red");

		glPopMatrix();
	}

	drawText(10,-6,"LIVES","white");
	drawText2(-1,10,"BRICKS","white");
	drawText(-8.75,-9,"Press Spacebar to Play/Pause.","white");
	drawText(-8.75,-10,"Press left arrow (<-) or right arrow (->) to move.","white");
	


	glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y){
	switch(key){
			case 033: // Escape 
			glutLeaveMainLoop();
			break;
			case ' ': // SpaceBar 
				if (gameActive && gameWin==false){ //Pausa
					gameActive = false;
					gameOver = false;
					gamePaused = true;
				}
				else if(gameWin){  //Reiniciar juego luego de ganar

					initialization();
					gameWin=false;
					gamePaused = false;

				}
				else{// Reniciar juego luego de perder
					gameActive = true;
					gamePaused = false;
					gameOver = false;
				}
			break;
			case 'g':// usar grid
				if(activateGrid)
					activateGrid = false;
				else
					activateGrid = true;	
			break;
	}
	glutPostRedisplay();
}


void arrows(int key, int x, int y) {
	if(gameActive){
		switch (key) {		
			case GLUT_KEY_RIGHT:
				bs.x1 +=0.5;
			break;
			case GLUT_KEY_LEFT:
				bs.x1 +=-0.5;
			break;
			}

	}
	
	
}

int main (int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(800,600);



	glutCreateWindow("Opengl");
	initialization();
	glutReshapeFunc(changeViewport);
	glutDisplayFunc(render);
	glutSpecialFunc(arrows);
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