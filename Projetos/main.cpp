#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <vector>
//LINUX #include <GL/glut.h>

using namespace std;

vector<float> positions_q = {80.0f, 80.0f, 80.0f, 80.0f, 80.0f, 80.0f};

vector<int> going_up = {1, 0, 0, 0, 0, 0};

float square_size = 62.0f;

void init(void) {
    /* selecionar cor de fundo (preto) */
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION); //Projecao 2D

    glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0); //Definindo os limites da Porta de Visao (ViewPort)

}

void displayFcn(void) {
    /* Limpar todos os pixels  */
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < 6; i++)
    {
        if (i == 0) glColor3f(1.0, .0, .0);
        if (i == 1) glColor3f(1.0, 1.0, .0);
        if (i == 2) glColor3f(.0, 1.0, .0);
        if (i == 3) glColor3f(.0, 1.0, 1.0);
        if (i == 4) glColor3f(.0, .0, 1.0);
        if (i == 5) glColor3f(1.0, 1.0, 1.0);

        float x = 80.0f * (i + 1);
        //glTranslatef(0.1, .0, .0);
        glBegin(GL_POLYGON);
        glVertex3f(x - square_size, positions_q[i], -1.0f);
        glVertex3f(x - square_size, positions_q[i] - square_size, -1.0f);
        glVertex3f(x, positions_q[i] - square_size, -1.0f);
        glVertex3f(x, positions_q[i], -1.0f);
        glEnd();
    }

    /* N�o esperar! */
    glFlush();
}

void timer(int x)
{
    glutPostRedisplay();

    // 60 vezes por segundo (1000 milisegundos)
    glutTimerFunc(1000 / 60, timer, x);

    for (int i = 0; i < going_up.size(); i++)
    {
        if (going_up[i] == 1)
        {
            if (positions_q[i] < 200)
            {
                if (i + 1 < going_up.size() && going_up[i + 1] == 0 && positions_q[i] == 108)
                {
                    going_up[i + 1] = 1;
                }
                positions_q[i] += 1.0;
            }
            else
            {
                going_up[i] = -1;
            }
        }
        else if (going_up[i] == -1)
        {
            if (positions_q[i] > 80)
            {
                positions_q[i] -= 1.0;
            }
            else
            {
                going_up[i] = 1;
            }
        }
    }
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 400);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Onda");

    init();

    glutDisplayFunc(displayFcn);
    glutTimerFunc(0, timer, 1);

    glutMainLoop();


    return 0;

}

