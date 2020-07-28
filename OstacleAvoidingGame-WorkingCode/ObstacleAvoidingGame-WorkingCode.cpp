#include<Windows.h>
#include<gl/GL.h>
#include<gl/glut.h>
#include<math.h>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
using namespace std;

int angle = 0;
int x = 0;
int r = 0;
int Count = 0, speed = 0, x_axis = 0, obj = 0, score = 0, highscore = 0;
bool Right = false, Left = false, check = false, leftObs = false, midObs = false, End = false;
void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 640);
}
void stars()
{
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(1);
	for (int i = 1; i<100; i++){
		int x = rand() % 640;
		int  y = rand() % 640;
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
	}
}
/*void background(){
glBegin(GL_QUADS);   //Primitive
glColor3f(0.0, 0.0, 0.0);//Set drawing color
glVertex2i(0, 0);//vertices for points(coordinates)
glVertex2i(640, 0);
glColor3f(0.2, 0.0, 0.2);//Purple color
glVertex2i(640, 640);
glVertex2i(0, 640);
glEnd();
glFlush();
}*/
void object()
{
	if (r <= -30 || r >= 24){
		if (Right){
			//boby
			glBegin(GL_QUADS);
			glColor3f(0.0f, 0.0f, 255.0f);
			glVertex2f(492, 5);
			glVertex2f(542, 5);
			glVertex2f(542, 55);
			glVertex2f(492, 55);
			glEnd();
			//trinagle
			glBegin(GL_QUADS);
			glColor3f(255.0f, 0.0f, 0.0f);
			glVertex2f(492, 55);
			glVertex2f(542, 55);
			glVertex2f(517, 80);
			glVertex2f(492, 55);
			glEnd();
			//tail;
			glBegin(GL_QUADS);
			glColor3f(255.0f, 0.0f, 0.0f);
			glVertex2f(472, 5);
			glVertex2f(492, 5);
			glVertex2f(492, 25);
			glVertex2f(472, 5);
			glEnd();
			glBegin(GL_QUADS);
			glColor3f(255.0f, 0.0f, 0.0f);
			glVertex2f(542, 5);
			glVertex2f(562, 5);
			glVertex2f(542, 25);
			glVertex2f(542, 5);
			glEnd();
			r = 24;
		}
		else if (Left){
			//boby
			glBegin(GL_QUADS);
			glColor3f(0.0f, 0.0f, 255.0f);
			glVertex2f(60, 5);
			glVertex2f(110, 5);
			glVertex2f(110, 55);
			glVertex2f(60, 55);
			glEnd();
			//trinagle
			glBegin(GL_QUADS);
			glColor3f(255.0f, 0.0f, 0.0f);
			glVertex2f(60, 55);
			glVertex2f(110, 55);
			glVertex2f(85, 80);
			glVertex2f(60, 55);
			glEnd();
			//tail;
			glBegin(GL_QUADS);
			glColor3f(255.0f, 0.0f, 0.0f);
			glVertex2f(40, 5);
			glVertex2f(60, 5);
			glVertex2f(60, 25);
			glVertex2f(40, 5);
			glEnd();
			glBegin(GL_QUADS);
			glColor3f(255.0f, 0.0f, 0.0f);
			glVertex2f(110, 5);
			glVertex2f(130, 5);
			glVertex2f(110, 25);
			glVertex2f(110, 5);
			glEnd();
			r = -30;
		}
	}
	else{
		//boby
		glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 255.0f);
		glVertex2f(300 + (8 * r), 5);
		glVertex2f(350 + (8 * r), 5);
		glVertex2f(350 + (8 * r), 55);
		glVertex2f(300 + (8 * r), 55);
		glEnd();
		//trinagle
		glBegin(GL_QUADS);
		glColor3f(255.0f, 0.0f, 0.0f);
		glVertex2f(300 + (8 * r), 55);
		glVertex2f(350 + (8 * r), 55);
		glVertex2f(325 + (8 * r), 80);
		glVertex2f(300 + (8 * r), 55);
		glEnd();
		//tail;
		glBegin(GL_QUADS);
		glColor3f(255.0f, 0.0f, 0.0f);
		glVertex2f(280 + (8 * r), 5);
		glVertex2f(300 + (8 * r), 5);
		glVertex2f(300 + (8 * r), 25);
		glVertex2f(280 + (8 * r), 5);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(255.0f, 0.0f, 0.0f);
		glVertex2f(350 + (8 * r), 5);
		glVertex2f(370 + (8 * r), 5);
		glVertex2f(350 + (8 * r), 25);
		glVertex2f(350 + (8 * r), 5);
		glEnd();
	}
}
void Timer(int iUnused)
{
	if (End == false){
		if (x > 300)
		{
			x = 0;
			Count++; speed++; obj++; score++;
		}
		//angle = angle + 10;
		glutPostRedisplay();
		glutTimerFunc(1, Timer, 1);
		if (Count % 2 == 0){
			check = true;
		}
		x++;
	}
}
void drawText(const char *text, int length, float x, float y) {
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2f(x, y);
	for (int i = 0; i<length; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}
void scroring()
{
	/*string text;
	stringstream conv;
	conv << score;
	text = "Score: " + conv.str();
	drawText(text.data(), text.size(), 200.0f, 500.0f);
	if (End == false){

	}*/
	if (End){
		glutPostRedisplay();
		string text1, text2;
		stringstream conv;
		conv << score;
		text1 = "Game Over";
		text2 = "Your Score: " + conv.str();
		drawText(text1.data(), text1.size(), 250.0f, 500.0f);
		drawText(text2.data(), text2.size(), 250.0f, 400.0f);
	}
	else{
		string text;
		stringstream conv, conv1;
		conv << score;
		conv1 << highscore;
		text = "Highest Score: " + conv1.str() + " Score: " + conv.str();
		drawText(text.data(), text.size(), 200.0f, 500.0f);
	}
	/*string text;
	stringstream conv, conv1;
	conv << score;
	conv1 << highscore;
	text = "Highest Score: " + conv1.str() + " Score: " + conv.str();
	drawText(text.data(), text.size(), 200.0f, 500.0f);*/
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//background();
	stars();
	object();
	scroring();

	if (check){
		glPushMatrix();
		glTranslatef(100, -x * 2, 0);
		glBegin(GL_QUADS);
		glVertex2i(100, 600);
		glVertex2i(300, 600);
		glVertex2i(300, 620);
		glVertex2i(100, 620);
		glEnd();
		midObs = true;
		//glViewport(200, 150, 800, 500);
		//obstacle();
		glPopMatrix();
		check = false;
	}
	else{
		glPushMatrix();
		//glViewport(390, 150, 600, 500);
		glTranslatef(-50, -x * 2, 0);
		glBegin(GL_QUADS);
		glVertex2i(100, 600);
		glVertex2i(250, 600);
		glVertex2i(250, 620);
		glVertex2i(100, 620);
		glEnd();
		leftObs = true;
		//obstacle1();
		glPopMatrix();

		glPushMatrix();
		//glViewport(390, 150, 600, 500);
		glTranslatef(300, -x * 2, 0);
		glBegin(GL_QUADS);
		glVertex2i(100, 600);
		glVertex2i(250, 600);
		glVertex2i(250, 620);
		glVertex2i(100, 620);
		glEnd();
		//obstacle1();
		glPopMatrix();
	}
	if (leftObs == true){
		//Left Obstacle
		if (r >= -30 && r <= -14){
			if (x == 270){
				//Sleep(5000);
				//exit(0);
				End = true;
				scroring();
				leftObs = false;
				midObs = false;
			}
			else{
				leftObs = false;
				midObs = false;
			}
		}
		//Right Obstacle
		else if (r >= 8 && r <= 24){
			if (x == 270){
				//Sleep(5000);
				//exit(0);
				End = true;
				scroring();
				leftObs = false;
				midObs = false;
			}
			else{
				leftObs = false;
				midObs = false;
			}
		}
		else{
			leftObs = false;
		}
	}
	else if (midObs == true){
		//Mid Obstacle
		if (r >= -18 && r <= 20){
			if (x == 270){
				//Sleep(5000);
				//exit(0);
				End = true;
				scroring();
				midObs = false;
			}
			else{
				midObs = false;
			}
		}
	}
	else{
		midObs = false;
		leftObs = false;
	}

	if (speed == 5){
		glutTimerFunc(1, Timer, 0);
		speed = -5;
	}
	//glutSwapBuffers();
	glFlush();
}

void myKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 's':
		glutTimerFunc(0, Timer, 0);
		if (End){
			End = false;
			if (highscore < score){
				highscore = score;
				score = 0;
			}
			else{
				//highscore = score;
				score = 0;
			}
		}
		break;
	case 'a':
		r = r - 2;
		if (r == -30){
			Left = true;
			Right = false;
		}
		break;
	case 'd':
		r = r + 2;
		if (r == 24){
			Right = true;
			Left = false;
		}
		break;
	}
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set display mode
	glutInitWindowSize(640, 480);  //set window size
	glutInitWindowPosition(100, 150);//set window position
	glutCreateWindow("ObstacleAvoidingGame"); //create window
	glutDisplayFunc(myDisplay);//register redraw function
	glutKeyboardFunc(myKeyboard);
	//glutTimerFunc(0, Timer, 0);
	myInit();
	glutMainLoop();// go into perpetual loop
}
