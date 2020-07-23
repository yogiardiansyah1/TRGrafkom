#include<stdlib.h>
#include <glut.h>
int is_depth, p, o;
float xrot = 0.0f;
float yrot = 0.0f;
float zrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
float xfar = 0.0f;
float yfar = 0.0f;
float zfar = 0.0f;
bool mouseDown = false;

void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void size(int, int);
void mouse(int, int, int, int);
void mouseMotion(int, int);
void rumah();
void badan();
void belakang();
void alas();
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Yogi Ardiansyah - 672018220");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(size);
    glutKeyboardFunc(keyboard);

    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutIdleFunc(display);

    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0, 0.7, 1.0, 0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9);
    glLineWidth(6);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 10.0f, 20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);
    glRotatef(zrot, 0, 0, 1);
    glTranslatef(xfar, 0, 0);
    glTranslatef(0, yfar, 0);
    glTranslatef(0, 0, zfar);

    rumah();
    badan();
    belakang();
	alas();

    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'n':
    case 'N':
        o += 1;
        display();
        break;
    case '9':
        yfar += 3;
        break;
    case '7':
        yfar -= 3;
        break;
    case '6':
        xfar -= 3;
        break;
    case '4':
        xfar += 3;
        break;
    case '2':
        zfar -= 3;
        break;
    case '8':
        zfar += 3;
        break;
    case 'd':
    case 'D':
        yrot -= 3;
        break;
    case 'a':
    case 'A':
        yrot += 3;
        break;
    case 's':
    case 'S':
        xrot -= 3;
        break;
    case 'w':
    case 'W':
        xrot += 3;
        break;
    case '1':
        zrot += 3;
        break;
    case '3':
        zrot -= 3;
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
        break;
    }
    display();
}

void size(int w, int h)
{
    if (h == 0)
        h = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100, w / h, 5, 500);
    glTranslatef(0, -5, -150);
    glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
    {
        mouseDown = false;
    }
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}


void rumah()
{
    ///////////bagian 1
    //depan
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);

    glVertex3f(157, 13, 20);
    glVertex3f(157, 33, 20);
    glVertex3f(91, 50, 20);
    glVertex3f(76, 50, 20);
    glVertex3f(12, 33, 20);
    glVertex3f(12, 13, 20);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    
    glVertex3f(157, 13, -20);
    glVertex3f(157, 33, -20);
    glVertex3f(91, 50, -20);
    glVertex3f(76, 50, -20);
    glVertex3f(12, 33, -20);
    glVertex3f(12, 13, -20);
    glEnd();

    //tutup
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0);
    // atas
    glVertex3f(91, 50, 20);
    glVertex3f(91, 50, -20);
    glVertex3f(76, 50, -20);
    glVertex3f(76, 50, 20);
    //bawah
    glVertex3f(157, 13, 20);
    glVertex3f(157, 13, -20);
    glVertex3f(12, 13, -20);
    glVertex3f(12, 13, 20);
    //kanan
    glVertex3f(157, 13, -20);
    glVertex3f(157, 33, -20);
    glVertex3f(157, 33, 20);
    glVertex3f(157, 13, 20);
    //kiri
    glVertex3f(12, 13, -20);
    glVertex3f(12, 33, -20);
    glVertex3f(12, 33, 20);
    glVertex3f(12, 13, 20);
    //kiri atas
    glVertex3f(12, 33, -20);
    glVertex3f(76, 50, -20);
    glVertex3f(76, 50, 20);
    glVertex3f(12, 33, 20);
    //kanan atas
    glVertex3f(157, 33, -20);
    glVertex3f(91, 50, -20);
    glVertex3f(91, 50, 20);
    glVertex3f(157, 33, 20);
    glEnd();

    ////////////bagian 2
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    //depan
    glVertex3f(91, 50, 13);
    glVertex3f(88, 70, 13);
    glVertex3f(78, 70, 13);
    glVertex3f(76, 50, 13);
    //belakang
    glVertex3f(91, 50, -13);
    glVertex3f(88, 70, -13);
    glVertex3f(78, 70, -13);
    glVertex3f(76, 50, -13);
    //atas
    glVertex3f(88, 70, -13);
    glVertex3f(78, 70, -13);
    glVertex3f(78, 70, 13);
    glVertex3f(88, 70, 13);
    //kanan
    glVertex3f(91, 50, -13);
    glVertex3f(91, 50, 13);
    glVertex3f(78, 70, 13);
    glVertex3f(78, 70, -13);
    //kiri
    glVertex3f(76, 50, -13);
    glVertex3f(76, 50, 13);
    glVertex3f(88, 70, 13);
    glVertex3f(88, 70, -13);
    glEnd();


}

void badan() {
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    //depan
    glVertex3f(45, 53, 10);
    glVertex3f(75, 71, 10);
    glVertex3f(75, 90, 10);
    glVertex3f(-157, 90, 10);
    glVertex3f(-157, 53, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(75, 71, 10);
    glVertex3f(85, 71, 10);
    glVertex3f(85, 80, 10);
    glVertex3f(75, 80, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-157, 80, 10);
    glVertex3f(93, 80, 10);
    glVertex3f(93, 95, 10);
    glVertex3f(-157, 95, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-157, 53, 10);
    glVertex3f(-157, 95, 10);
    glVertex3f(-228, 74, 10);
    glVertex3f(-248, 53, 10);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glVertex3f(45, 53, -10);
    glVertex3f(75, 71, -10);
    glVertex3f(75, 90, -10);
    glVertex3f(-157, 90, -10);
    glVertex3f(-157, 53, -10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(75, 71, -10);
    glVertex3f(85, 71, -10);
    glVertex3f(85, 80, -10);
    glVertex3f(75, 80, -10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-157, 80, -10);
    glVertex3f(93, 80, -10);
    glVertex3f(93, 95, -10);
    glVertex3f(-157, 95, -10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-157, 53, -10);
    glVertex3f(-157, 95, -10);
    glVertex3f(-228, 74, -10);
    glVertex3f(-248, 53, -10);
    glEnd();
    
    //tutup

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f(-248, 53, 10);
    glVertex3f(-248, 53, -10);
    glVertex3f(45, 53, -10);
    glVertex3f(45, 53, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(45, 53, -10);
    glVertex3f(45, 53, 10);
    glVertex3f(75, 71, 10);
    glVertex3f(75, 71, -10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(75, 71, 10);
    glVertex3f(75, 71, -10);
    glVertex3f(85, 71, -10);
    glVertex3f(85, 71, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(85, 71, -10);
    glVertex3f(85, 71, 10);
    glVertex3f(85, 80, 10);
    glVertex3f(85, 80, -10);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(85, 80, 10);
    glVertex3f(85, 80, -10);
    glVertex3f(93, 80, -10);
    glVertex3f(93, 80, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(93, 80, -10);
    glVertex3f(93, 80, 10);
    glVertex3f(93, 95, 10);
    glVertex3f(93, 95, -10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(93, 95, 10);
    glVertex3f(93, 95, -10);
    glVertex3f(-157, 95, -10);
    glVertex3f(-157, 95, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-157, 95, -10);
    glVertex3f(-157, 95, 10);
    glVertex3f(-228, 74, 10);
    glVertex3f(-228, 74, -10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-228, 74, 10);
    glVertex3f(-228, 74, -10);
    glVertex3f(-248, 53, -10);
    glVertex3f(-248, 53, 10);
    glEnd();

}

void belakang() {
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    //depan
    glVertex3f(-227, 13, 20);
    glVertex3f(-227, 33, 20);
    glVertex3f(-161, 50, 20);
    glVertex3f(-146, 50, 20);
    glVertex3f(-82, 33, 20);
    glVertex3f(-82, 13, 20);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glVertex3f(-227, 13, -20);
    glVertex3f(-227, 33, -20);
    glVertex3f(-161, 50, -20);
    glVertex3f(-146, 50, -20);
    glVertex3f(-82, 33, -20);
    glVertex3f(-82, 13, -20);
    glEnd();

    //tutup
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f(-227, 13, -20);
    glVertex3f(-227, 13, 20);
    glVertex3f(-82, 13, 20);
    glVertex3f(-82, 13, -20);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-82, 13, 20);
    glVertex3f(-82, 13, -20);
    glVertex3f(-82, 33, -20);
    glVertex3f(-82, 33, 20);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-82, 33, -20);
    glVertex3f(-82, 33, 20);
    glVertex3f(-146, 50, 20);
    glVertex3f(-146, 50, -20);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-146, 50, 20);
    glVertex3f(-146, 50, -20);
    glVertex3f(-161, 50, -20);
    glVertex3f(-161, 50, 20);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-161, 50, -20);
    glVertex3f(-161, 50, 20);
    glVertex3f(-227, 33, 20);
    glVertex3f(-227, 33, -20);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-227, 33, 20);
    glVertex3f(-227, 33, -20);
    glVertex3f(-227, 13, -20);
    glVertex3f(-227, 13, 20);
    glEnd();
        
	glTranslatef(-2,7,20);
	glColor3f(0,0,0);
	for (int a=1;a<=10;a++)
	{
	glTranslatef(16,0,0);
	glutSolidTorus(2,5,10,20);
	}
	glTranslatef(16,0,-40);
	for (int a=1;a<=10;a++)
	{
	glTranslatef(-16,0,0);
	glutSolidTorus(2,5,10,20);
	}
	glTranslatef(-80,0,0);
	for (int a=1;a<=10;a++)
	{
	glTranslatef(-16,0,0);
	glutSolidTorus(2,5,10,20);
	}
	glTranslatef(-16,0,40);
	for (int a=1;a<=10;a++)
	{
	glTranslatef(16,0,0);
	glutSolidTorus(2,5,10,20);
	}
}
void alas()
{
	//rumput
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
    glVertex3f(290, -7, 160);
    glVertex3f(290, -7, -160);
    glVertex3f(-390, -7, -160);
    glVertex3f(-390, -7, 160);
    glEnd();
    //jalan
    glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
    glVertex3f(290, -6, -80);
    glVertex3f(290, -6, 80);
    glVertex3f(-390, -6, 80);
    glVertex3f(-390, -6, -80);
    glEnd();
    //lis jalan
    glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
    glVertex3f(290, -5, -5);
    glVertex3f(290, -5, 5);
    glVertex3f(-390, -5, 5);
    glVertex3f(-390, -5, -5);
    glEnd();
}