#include <iostream>
#include <GL/glut.h>

using namespace std;

float cores[4][3] = {1.0, 1.0, 1.0,
                     1.0, 0.0, 0.0,
                     0.0, 1.0, 0.0,
                     0.0, 0.0, 1.0 };

int corAtual[4] = { 0, 1, 2, 3 };

void init(void) {
    /* selecionar cor de fundo (preto) */
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION); //Projecao 2D

    glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0); //Definindo os limites da Porta de Visao (ViewPort)
}

void displayFcn(void) {
    /* Limpar todos os pixels  */
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, .0);
    glBegin(GL_POLYGON);
    glVertex3f(249.0f, 250.0f, -1.0f);
    glVertex3f(249.0f, 100.0f, -1.0f);
    glVertex3f(251.0f, 100.0f, -1.0f);
    glVertex3f(251.0f, 250.0f, -1.0f);
    glEnd();

    /* Desenhar um pol�gono branco  */
    glColor3f(cores[corAtual[0]][0], cores[corAtual[0]][1], cores[corAtual[0]][2]);
    glBegin(GL_TRIANGLES);
    glVertex2f(250.0f, 250.0f);
    glVertex2f(230.0f, 200.0f);
    glVertex2f(270.0f, 200.0f);
    glEnd();

    /* Desenhar um pol�gono vermelho */
    glColor3f(cores[corAtual[1]][0], cores[corAtual[1]][1], cores[corAtual[1]][2]);
    glBegin(GL_TRIANGLES);
    glVertex2f(250.0f, 250.0f);
    glVertex2f(300.0f, 230.0f);
    glVertex2f(300.0f, 270.0f);
    glEnd();

    /* Desenhar um pol�gono verde */
    glColor3f(cores[corAtual[2]][0], cores[corAtual[2]][1], cores[corAtual[2]][2]);
    glBegin(GL_TRIANGLES);
    glVertex2f(250.0f, 250.0f);
    glVertex2f(230.0f, 300.0f);
    glVertex2f(270.0f, 300.0f);
    glEnd();

    /* Desenhar um pol�gono vermelho */
    glColor3f(cores[corAtual[3]][0], cores[corAtual[3]][1], cores[corAtual[3]][2]);
    glBegin(GL_TRIANGLES);
    glVertex2f(250.0f, 250.0f);
    glVertex2f(200.0f, 270.0f);
    glVertex2f(200.0f, 230.0f);
    glEnd();


    /* N�o esperar! */
    glFlush();
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/1, timer, 0);

    for (int i = 0; i < 4; i++)
    {
        corAtual[i] += 1;
        corAtual[i] = corAtual[i] % 4;
    }
}


int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 400);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Flor de Abril");

    init();

    glutDisplayFunc(displayFcn);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();


    return 0;

}