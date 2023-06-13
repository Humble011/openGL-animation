#include <stdio.h>
#include <gl/glut.h>
#include <math.h>

GLfloat rotation = 90.0;
float posX = 0, posY = 0, posZ = 0;
bool value = false;
bool flag = true, flag2 = true;
float cloud_X = 0;
float cloud_Y = 0;
float cloud_X2 = 0;
float cloud_Y2 = 0;
int cloudStatus = 1;

void flame()
{
	if (value)
	{
		if (flag == true){
			glColor3f(1.0, 0.25, 0.0);
			flag = false;
		}
		else{
			glColor3f(1.0, 0.816, 0.0);
			flag = true;
		}
	}
	else
	{
		glColor3f(0.3, 1.2, 0.0);
	}
	
	float x = 0.03, y = -0.008;
	glBegin(GL_POLYGON);
	glVertex3f(x + 0.56, y + .35, 0.0);
	glVertex3f(x + 0.54, y + .31, 0.0);
	glVertex3f(x + 0.58, y + 0.28, 0.0);
	glVertex3f(x + 0.61, y + 0.31, 0.0);
	glVertex3f(x + 0.59, y + 0.35, 0.0);

	if (value)
	{
		if (flag2 == true){
			glColor3f(1.0, 0.816, 0.0);
			flag2 = false;
		}
		else{
			glColor3f(1.0, 0.25, 0.0);
			flag2 = true;
		}
	}
	else
	{
		glColor3f(0.3, 1.2, 0.0);
	}

	glVertex3f(x + 0.56, y + .35, 0.0);
	glVertex3f(x + 0.54, y + .31, 0.0);
	glVertex3f(x + 0.58, y + 0.28, 0.0);
	glVertex3f(x + 0.61, y + 0.31, 0.0);
	glVertex3f(x + 0.59, y + 0.35, 0.0);
	glEnd();
}

void rocket(){
	float x = 0.03, y = 0;
	
	glBegin(GL_QUADS);
	glColor3f(0.3, 1.2, 0.0);
	glPointSize(100.0);
	glColor3f(0.3, 0.28, 0.28);
	glPointSize(100.0);
	//body
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(x + 0.55, y + .35, 0.0);
	glVertex3f(x + 0.6, y + .35, 0.0);
	glVertex3f(x + 0.6, y + 0.6, 0.0);
	glVertex3f(x + 0.55, y + 0.6, 0.0);
	glFlush();
	//head
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(x + 0.6, y + 0.6, 0.0);
	glVertex3f(x + 0.55, y + 0.6, 0.0);
	glVertex3f(x + 0.574, y + 0.65, 0.0);
	glVertex3f(x + 0.6, y + 0.6, 0.0);
	glFlush();
	//smoke1
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(x + 0.56, y + 0.34, 0.0);
	glVertex3f(x + 0.57, y + 0.34, 0.0);
	glVertex3f(x + 0.57, y + 0.35, 0.0);
	glVertex3f(x + 0.56, y + 0.35, 0.0);
	glFlush();
	//smoke2
	glVertex3f(x + 0.58, y + 0.34, 0.0);
	glVertex3f(x + 0.59, y + 0.34, 0.0);
	glVertex3f(x + 0.59, y + 0.35, 0.0);
	glVertex3f(x + 0.58, y + 0.35, 0.0);
	glFlush();
	//left wing
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(x + 0.55, y + 0.37, 0.0);
	glVertex3f(x + 0.55, y + 0.425, 0.0);
	glVertex3f(x + 0.51, y + 0.365, 0.0);
	glVertex3f(x + 0.55, y + 0.37, 0.0);
	glFlush();
	//right wing
	glVertex3f(x + 0.6, y + 0.37, 0.0);
	glVertex3f(x + 0.6, y + 0.425, 0.0);
	glVertex3f(x + 0.64, y + 0.365, 0.0);
	glVertex3f(x + 0.6, y + 0.37, 0.0);
	
	glEnd();

	//new
	flame();
}

void building()
{
	//Building1
	glColor3f(0.4, 0.4, 0.4);
	glPointSize(100.0);
	glVertex3f(0.06, 0.31, 0.0);//top leftx,y,z
	glVertex3f(0.15, 0.31, 0.6);//top right
	glVertex3f(0.15, 0.1, 0.4);//bottom right
	glVertex3f(0.06, 0.1, 0.0);//bottom left
	glFlush();

	//Building2
	glColor3f(0.4, 0.4, 0.4);
	glPointSize(100.0);
	glVertex3f(0.0, 0.36, 0.0);//top leftx,y,z
	glVertex3f(0.05, 0.36, 0.6);//top right
	glVertex3f(0.05, 0.1, 0.4);//bottom right
	glVertex3f(0.0, 0.1, 0.0);//bottom left
	glFlush();
}

void windowFigure()
{
	glColor3f(0.58, 0.87, 0.98);
	float y = .01;
	for (int i = 0; i < 5; i++)
	{
		//left window
		glVertex3f(0.005, 0.11 + y, 0.0);
		glVertex3f(0.019, 0.11 + y, 0.0);
		glVertex3f(0.019, 0.13 + y, 0.0);
		glVertex3f(0.005, 0.13 + y, 0.0);
		glFlush();
		//right window
		glVertex3f(0.03, 0.11 + y, 0.0);
		glVertex3f(0.044, 0.11 + y, 0.0);
		glVertex3f(0.044, 0.13 + y, 0.0);
		glVertex3f(0.03, 0.13 + y, 0.0);
		glFlush();
		y += .05;
	}

	//2nd building
	y = 0;
	for (int i = 0; i < 4; i++)
	{
		//left window
		glVertex3f(0.07, 0.11 + y, 0.0);
		glVertex3f(0.095, 0.11 + y, 0.0);
		glVertex3f(0.095, 0.14 + y, 0.0);
		glVertex3f(0.07, 0.14 + y, 0.0);
		glFlush();
		//right window
		glVertex3f(0.11, 0.11 + y, 0.0);
		glVertex3f(0.136, 0.11 + y, 0.0);
		glVertex3f(0.136, 0.14 + y, 0.0);
		glVertex3f(0.11, 0.14 + y, 0.0);
		glFlush();
		y += .05;
	}
}

void roadDivider()
{

	//Roaddivider
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(100.0);
	glVertex3f(0.2, 0.155, 0.0);//top rightx,y,
	glVertex3f(0.18, 0.14, 0.6);//top left
	glVertex3f(0.18, 0.13, 0.4);//top left
	glVertex3f(0.2, 0.145, 0.0);//bottom right
	glFlush();

	glColor3f(1.0, 1.0, 1.0);
	glPointSize(100.0);
	glVertex3f(0.28, 0.21, 0.0);//botom leftx,y,z
	glVertex3f(0.26, 0.195, 0.6);//
	glVertex3f(0.26, 0.185, 0.4);//bottom left
	glVertex3f(0.28, 0.197, 0.0);//botom right
	glFlush();

	glColor3f(1.0, 1.0, 1.0);
	glPointSize(100.0);
	glVertex3f(0.36, 0.26, 0.0);//botom leftx,y,z
	glVertex3f(0.34, 0.246, 0.6);//top left
	glVertex3f(0.34, 0.2379, 0.4);//top right
	glVertex3f(0.36, 0.25, 0.0);//right botom
	glFlush();


	glColor3f(1.0, 1.0, 1.0);
	glPointSize(100.0);
	glVertex3f(0.44, 0.31, 0.0);//top rightx,y,z
	glVertex3f(0.42, 0.297, 0.6);//top left
	glVertex3f(0.42, 0.285, 0.4);//bottom left
	glVertex3f(0.44, 0.299, 0.0);//bottom right
	glFlush();
}

void tree()
{	
	//tree
	glColor3f(0.65,0.19, 0.0);
	glPointSize(100.0);
	glVertex3f(0.82, 0.3, 0.0);//botom leftx,y,z
	glVertex3f(0.815, 0.3, 0.6);//botom left
	glVertex3f(0.807, 0.15, 0.4);//top right
	glVertex3f(0.831, 0.15, 0.0);//bottom right
	glFlush();

	glColor3f(0.65,0.19, 0.0);
	glPointSize(100.0);
	glVertex3f(0.879, 0.21, 0.0);// leftx,y,z
	glVertex3f(0.872, 0.21, 0.6);//bottom lef
	glVertex3f(0.865, 0.1, 0.4);//bottom right
	glVertex3f(0.89, 0.1, 0.0);
	glFlush();

	glColor3f(0.65,0.19, 0.0);
	glPointSize(100.0);
	glVertex3f(0.945, 0.28, 0.0);//top left x,y,z
	glVertex3f(0.938, 0.28, 0.6);//botom right
	glVertex3f(0.932, 0.16, 0.4);//top right
	glVertex3f(0.955, 0.16, 0.0);//right bottom
	glFlush();
	//leaf
	glColor3f(0.18, 0.30, 0.18);
	glPointSize(100.0);
	glVertex3f(0.822, 0.39, 0.0);//top rightx,y,z
	glVertex3f(0.822, 0.39, 0.6);//top left
	glVertex3f(0.88, 0.28, 0.4);//bottom right
	glVertex3f(0.76, 0.28, 0.0);//bottom left
	glFlush();

	////leaf2
	glColor3f(0.18, 0.30, 0.18);
	glPointSize(100.0);
	glVertex3f(0.94, 0.39, 0.0);//top rightx,y,z
	glVertex3f(0.94, 0.39, 0.6);//top left
	glVertex3f(0.99, 0.28, 0.4);//bottom right
	glVertex3f(0.89, 0.28, 0.0);//bottom left
	glFlush();

	////leaf3
	glColor3f(0.18, 0.30, 0.18);
	glPointSize(100.0);
	glVertex3f(0.87, 0.31, 0.0);//top rightx,y,z
	glVertex3f(0.87, 0.31, 0.6);//top left
	glVertex3f(0.94, 0.21, 0.4);//bottom right
	glVertex3f(0.84, 0.21, 0.0);//bottom left
	glFlush();
	glEnd();

}

void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
	glPointSize(100.0);
	for(int ii = 0; ii < num_segments; ii++){
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);
		float x = r * cosf(theta);
		float y = r * sinf(theta);
		glVertex2f(x+cx,y+cy);
	}
	glEnd();
	glFlush();
}


void drawCloud()
{	
	DrawCircle(0.010, 0.90, 0.03, 1000);
	DrawCircle(0.035, 0.87, 0.04, 1000);
	DrawCircle(0.020, 0.85, 0.02, 1000);
	DrawCircle(0.001, 0.86, 0.03, 1000);
	
	DrawCircle(0.110, 0.80, 0.03, 1000);
	DrawCircle(0.135, 0.77, 0.04, 1000);
	DrawCircle(0.120, 0.75, 0.02, 1000);
	DrawCircle(0.101, 0.76, 0.03, 1000);
}

void cloud()
{		
	if(cloudStatus == 1){
		cloud_X += 0.001;
	}
	
	if(cloud_X > 1100){
		cloud_X = -650;
	}
	
	glPushMatrix();
	glTranslatef(cloud_X, cloud_Y, 0.0);
	drawCloud();
	glPopMatrix();
}

void nasa()
{
	glColor3f(0.0, 0.0, 0.0);
	float x = .05, y = 0;
	glBegin(GL_LINES);
	//Drawing N
	glVertex2f(x + .5, y + .1);
	glVertex2f(x + .5, y + .15);

	glVertex2f(x + .5, y + .15);
	glVertex2f(x + .52, y + .1);

	glVertex2f(x + .52, y + .1);
	glVertex2f(x + .52, y + .15);
	//Drawing A
	glVertex2f(x + .53, y + .1);
	glVertex2f(x + .54, y + .15);

	glVertex2f(x + .535, y + .12);
	glVertex2f(x + .545, y + .12);

	glVertex2f(x + .54, y + .15);
	glVertex2f(x + .55, y + .1);
	//Drawing S
	glVertex2f(x + .56, y + .1);
	glVertex2f(x + .58, y + .1);

	glVertex2f(x + .58, y + .1);
	glVertex2f(x + .58, y + .125);

	glVertex2f(x + .56, y + .125);
	glVertex2f(x + .58, y + .125);

	glVertex2f(x + .56, y + .125);
	glVertex2f(x + .56, y + .15);

	glVertex2f(x + .56, y + .15);
	glVertex2f(x + .58, y + .15);
	//Drawing A
	x += .06;
	glVertex2f(x + .53, y + .1);
	glVertex2f(x + .54, y + .15);

	glVertex2f(x + .535, y + .12);
	glVertex2f(x + .545, y + .12);

	glVertex2f(x + .54, y + .15);
	glVertex2f(x + .55, y + .1);

	glEnd();
	glFlush();
}



void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	//background(green)
	glBegin(GL_QUADS);
	glColor3f(0.3, 1.2, 0.0);
	glPointSize(100.0);
	glVertex3f(0.0, 0.0, 0.0);//botom left
	glVertex3f(1.0, 0.0, 0.6);//botom right
	glVertex3f(1.0, 0.4, 0.4);//top right
	glVertex3f(0.0, 0.4, 0.0);//top left
	glFlush();
	

	//Road
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(100.0);
	glVertex3f(0.15, 0.14, 0.0);//botom leftx,y,z
	glVertex3f(0.47, 0.34, 0.6);//botom right
	glVertex3f(0.47, 0.3, 0.4);//top right
	glVertex3f(0.15, 0.1, 0.0);//top left x,y,z

	glFlush();

	building();
	windowFigure();
	roadDivider();
	


	//Rocket stand
	glColor3f(0.5, 0.5, 0.5);
	glPointSize(100.0);
	glVertex3f(0.53, 0.5, 0.0);//botom leftx,y,z
	glVertex3f(0.58, 0.5, 0.6);//botom right
	glVertex3f(0.58, 0.52, 0.4);//top right
	glVertex3f(0.53, 0.52, 0.0);
	glFlush();


	glColor3f(0.25, 0.25, 0.25);
	glPointSize(100.0);
	glVertex3f(0.53, 0.6, 0.0);//botom leftx,y,z
	glVertex3f(0.518, 0.6, 0.6);//botom right
	glVertex3f(0.518, 0.31, 0.4);//top right
	glVertex3f(0.53, 0.31, 0.0);
	glFlush();

	glColor3f(0.25, 0.25, 0.25);
	glPointSize(100.0);
	glVertex3f(0.69, 0.6, 0.0);//botom leftx,y,z
	glVertex3f(0.678, 0.6, 0.6);//botom right
	glVertex3f(0.678, 0.31, 0.4);//top right
	glVertex3f(0.69, 0.31, 0.0);
	glFlush();
	//end stand
	
	tree();
<<<<<<< HEAD
=======
	
>>>>>>> 868d149ce77c24be062fe75e48c0f49bf79f10d4
	cloud();

	//rocket
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(posX, posY, posZ);
	rocket();
	glPopMatrix();
	glFlush();
	nasa();

}




void init(){
	glClearColor(0.19, 0.6, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void makedelay(int)
{
	for (int ii = 0; ii<100; ii++)
		posY += .0001;
	display();
	glutTimerFunc(100, makedelay, 1);
}
void resetRocketPosition()
{
    posX = 0.0;
    posY = 0.0;
    posZ = 0.0;
}

float move_unit = 0.1f;
void keyboardown(int key, int x, int y)
{
	switch (key){
	case GLUT_KEY_UP:
		glutTimerFunc(100, makedelay, 1);
		value = true;
		break;
	case GLUT_KEY_DOWN:
	resetRocketPosition();
		break;


	}
	glutPostRedisplay();
}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("KELOMPOK 1 - PELUNCUNRAN ROKET");
	glutDisplayFunc(display);
	init();
	glutSpecialFunc(keyboardown);
	glutMainLoop();
}
