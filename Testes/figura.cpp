// 	g++ Testes/figura.cpp -o figura -I"freeglut\include" -L"freeglut\lib" -lfreeglut -lopengl32

#include <iostream>
#include <vector>
#include <GL/glut.h>

using namespace std;

float rotateX = 0;
float rotateY = 0;

float qntRotate = 10;

void init(void) {
    /* selecionar cor de fundo (preto) */
    glClearColor(0.0, 0.0, 0.0, 1.0); // set background color to black
}

void displayFcn(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    if (rotateX != 0)
    {
        glRotatef(rotateX, 1, 0, 0);
    }
    else if (rotateY != 0)
    {
        glRotatef(rotateY, 0, 1, 0);
    }

    glBegin(GL_POLYGON);

    glColor3f(1.0, .0, .0);
    glVertex3f(0.5, 0.0, 0.5);

    glColor3f(.0, 1.0, .0);
    glVertex3f(0.5, 0.0, 0.0);

    glColor3f(.0, .0, 1.0);
    glVertex3f(0.0, 0.5, 0.0);

    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.0, 0.0, 0.5);

    glEnd();

    glutSwapBuffers();
}

void keyboard_handler(unsigned char key, int x, int y)
{
    if (key == 'a')
    {
        rotateY = -qntRotate;
        //cout << "LEFT" << endl;
    }
    if (key == 'd')
    {
        rotateY = qntRotate;
        //cout << "RIGHT" << endl;
    }
    if (key == 'w')
    {
        rotateX = -qntRotate;
        //cout << "UP" << endl;
    }
    if (key == 's')
    {
        rotateX = qntRotate;
        //cout << "DOWN" << endl;
    }

    glutPostRedisplay();
}

void timer(int)
{
    glutPostRedisplay();
    if (rotateX != 0)   rotateX = 0;
    if (rotateY != 0)   rotateY = 0;
    glutTimerFunc(1000 / 60, timer, 0);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 400);
    glutInitWindowPosition(500, 500);
    glutCreateWindow("House");
    init();

    glutDisplayFunc(displayFcn);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard_handler);
    glutMainLoop();

    return 0;
}