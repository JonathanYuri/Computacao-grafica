#include <iostream>
#include <vector>
#include <GL/glut.h>

using namespace std;

vector<float> positions_q = { 80.0f, 80.0f, 80.0f, 80.0f, 80.0f, 80.0f };

vector<int> going_up = { 1, 0, 0, 0, 0, 0 };

float square_size = 62.0f;

bool is_paused = true;
float year = 0.0;

int SLICES = 15;
int STACKS = 15;
float VIRTUAL_TIME = 0.6; //determines how fast is our virtual time
// the higher, the faster
float EARTH_RADIUS = 0.1;
float MARS_RADIUS = EARTH_RADIUS / 1.88;
float MOON1_RADIUS = EARTH_RADIUS / 3.66;
float MOON2_RADIUS = EARTH_RADIUS / 7;
float SUN_RADIUS = EARTH_RADIUS * 4;

void init(void) {
    /* selecionar cor de fundo (preto) */
    glClearColor(0.0, 0.0, 0.0, 1.0); // set background color to black
}

extern "C" double* interp(int N_x, int N_xp, const double* x, const double* xp, const double* yp, double left, double right) {

    double* y = new double[N_x];
    for (int i = 0; i < N_x; i++) y[i] = left;

    int ip = 0;
    int ip_next = 1;
    int i = 0;

    while (i < N_x) {
        double m = (yp[ip_next] - yp[ip]) / (xp[ip_next] - xp[ip]);
        double q = yp[ip] - m * xp[ip];
        //std::cout << m << " "<< q<<std::endl;
        while (x[i] < xp[ip_next]) {
            if (x[i] >= xp[ip])
                y[i] = m * x[i] + q;
            //std::cout << y[i] << std::endl; // debug: OK
            i += 1;
            if (i >= N_x) { break; }
            //std::cout << i << " " <<ip <<std::endl;
        }
        ip += 1;
        ip_next += 1;
        if (ip_next == N_xp) {
            while (i < N_x) {
                y[i] = right;
                i++;
            }
            break;
        }
    }

    return y;
}

double period_to_angle(int max) {
    /*
    Maps the current position of our object given the current time and their
    cicle.The position is represented by an angle between 0° and 360°
    */
    // return interp(year % max, [0, max], [0, 360])
    //                    x     ,  xp    ,    fp

    double a[1] = { (int)year % max };
    double b[2] = { 0, max };
    double c[2] = { 0, 360 };

    double *r = interp(1, 2, a, b, c, 0, 0);
    return r[0];
}

void draw_mars(){
    glPushMatrix();

    //clockwise rotation around the previous object(sun, in this case)
    glRotatef(-period_to_angle(687), 0, 1, 0);
    glTranslatef(1, 0, 0);

    glPushMatrix();
    glRotatef(period_to_angle(24), 0, 1, 0); // mars' spin around its own axis(y)
    glColor4f(1.0, 0.0, 0.0, 1.0); // red
    glutWireSphere(MARS_RADIUS, SLICES, STACKS);
    glPopMatrix();

    glPopMatrix();
}

void draw_sun()
{
    glColor4f(1.0, 1.0, 0.0, 1.0); // yellow
    glutSolidSphere(SUN_RADIUS, SLICES * 2, STACKS * 2);
}

void draw_moon_1()
{
    glPushMatrix();

    //rotation around the previous object(earth, in this case)
    glRotatef(period_to_angle(27.3), 0, 1, 0);
    glTranslatef(0.2, 0, 0);

    glPushMatrix();
    glRotatef(period_to_angle(27), 0, 1, 0); // moon1's spin around its own axis(y)
    glColor4f(0.6, 0.6, 0.6, 1.0); // light gray
    glutWireSphere(MOON1_RADIUS, SLICES, STACKS);
    glPopMatrix();

    glPopMatrix();
}

void draw_moon_2()
{
    glPushMatrix();

    //rotation around the previous object(earth, in this case)

    //glRotatef(period_to_angle(400), 1, 0, 0) # around y axis
    //glTranslatef(0, 0.25, 0) # around y axis

    glRotatef(period_to_angle(400), 1, 1, 0); // around xy axis
    glTranslatef(-0.2, 0.2, 0); // around xy axis

    glPushMatrix();
    glRotatef(period_to_angle(400), 0, 1, 0); // moon2's spin around its own axis(y)
    glColor4f(0, 1, 0, 1.0); //green
    glutWireSphere(MOON2_RADIUS, SLICES, STACKS);
    glPopMatrix();

    glPopMatrix();
}

void draw_earth_with_two_moons()
{
    glPushMatrix();

    // counterclockwise rotation around the previous object(sun, in this case)
    glRotatef(period_to_angle(365), 0, 1, 0);
    glTranslatef(0.8, 0, 0);

    glPushMatrix();
    glRotatef(period_to_angle(24), 0, 1, 0); // earth's spin around its own axis(y)
    glColor4f(0.0, 0.0, 1.0, 1.0); // blue
    glutWireSphere(EARTH_RADIUS, SLICES, STACKS);
    glPopMatrix();

    draw_moon_1();
    draw_moon_2();

    glPopMatrix();
}

void displayFcn(void) {
    /* Limpar todos os pixels  */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    draw_sun();
    draw_earth_with_two_moons();
    draw_mars();

    glutSwapBuffers();
}

void keyboard_handler(unsigned char key, int x, int y)
{
    if (key == 'y') {// pause / start the application if the Y - key is pressed
        cout << "Y-key was pressed" << endl;
        is_paused = !is_paused;
        //cout << "redisplay2" << endl;
        glutPostRedisplay();
    }
}

void timer(int)
{
    if (!is_paused)
    {
        year += VIRTUAL_TIME;
        //cout << "redisplay " << year << endl;
        glutPostRedisplay();
    }

    // 60 vezes por segundo (1000 milisegundos)
    glutTimerFunc(1000 / 60, timer, 0);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 400);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Solar System");
    init();

    glutDisplayFunc(displayFcn);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard_handler);
    glutMainLoop();

    return 0;
}