#include<stdlib.h>
#include <glut.h>
#include <math.h>

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
void awan();
void kaki();
void badan();
void belakang();
void alas();
void mesin();
void imbuhan();
void pengaitbelakang();
void pengaitdepan();
void pengaitban();
void dekbarang();
void pegas();
void beton();
void ban();

const double PI = 3.141592653589793;
int i,j;

void lingkaran(int radius, int jumlah_titik, float x_tengah, float y_tengah,float z) 
{
	glBegin(GL_POLYGON);
	for (i=0;i<=360;i++){
		float sudut=i*(2*PI/jumlah_titik);
		float x=x_tengah+radius*cos(sudut);
		float y=y_tengah+radius*sin(sudut);
		glVertex3f(x,y,z);
	}
	glEnd();
}

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
    gluLookAt(0.0f, 10.0f, 140.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);
    glRotatef(zrot, 0, 0, 1);
    glTranslatef(xfar, 0, 0);
    glTranslatef(0, yfar, 0);
    glTranslatef(0, 0, zfar);
	
	kaki();
    badan();
    belakang();
	alas();
	beton();
	mesin();
	imbuhan();
	pengaitbelakang();
	pengaitdepan();
	pengaitban();
	dekbarang();
	pegas();
	awan();
	ban();

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

void awan()
{
	//awan1
	glColor3f(1, 1, 1);
	glTranslatef(30,280,-130);
	for (int c=0;c<=2;c++)
	{
		int d=-15;
		glTranslatef(0,0,0+d);
		for(int a=0;a<=3;a++)
		{
			int b=15;
			glTranslatef(0+b,0,0);
			glutSolidSphere(10,10,10);
		}
		glTranslatef(-53,15,0);
		for(int a=0;a<=2;a++)
		{
			int b=15;
			glTranslatef(0+b,0,0);
			glutSolidSphere(10,10,10);
		}
		glTranslatef(-42,-30,0);
		for(int a=0;a<=2;a++)
		{
			int b=15;
			glTranslatef(0+b,0,0);
			glutSolidSphere(10,10,10);
		}
		glTranslatef(-55,15,0);
	}
	glTranslatef(25,-285,180);

	//awan 2
	glColor3f(1, 1, 1);
	glTranslatef(-130,280,-130);
	for (int c=0;c<=2;c++)
	{
		int d=-15;
		glTranslatef(0,0,0+d);
		for(int a=0;a<=3;a++)
		{
			int b=15;
			glTranslatef(0+b,0,0);
			glutSolidSphere(10,10,10);
		}
		glTranslatef(-53,15,0);
		for(int a=0;a<=2;a++)
		{
			int b=15;
			glTranslatef(0+b,0,0);
			glutSolidSphere(10,10,10);
		}
		glTranslatef(-42,-30,0);
		for(int a=0;a<=2;a++)
		{
			int b=15;
			glTranslatef(0+b,0,0);
			glutSolidSphere(10,10,10);
		}
		glTranslatef(-55,15,0);
	}
	glTranslatef(130,-280,180);

	//awan 3
	glColor3f(1, 1, 1);
	glTranslatef(-230,280,-130);
	for (int c=0;c<=2;c++)
	{
		int d=-15;
		glTranslatef(0,0,0+d);
		for(int a=0;a<=3;a++)
		{
			int b=15;
			glTranslatef(0+b,0,0);
			glutSolidSphere(10,10,10);
		}
		glTranslatef(-53,15,0);
		for(int a=0;a<=2;a++)
		{
			int b=15;
			glTranslatef(0+b,0,0);
			glutSolidSphere(10,10,10);
		}
		glTranslatef(-42,-30,0);
		for(int a=0;a<=2;a++)
		{
			int b=15;
			glTranslatef(0+b,0,0);
			glutSolidSphere(10,10,10);
		}
		glTranslatef(-55,15,0);
	}
	glTranslatef(230,-280,170);
}
void beton()
{
	glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-70, 30, 20);
	glColor3f(0, 0, 0);
    glVertex3f(-70, 0, 15);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(0, 0, 15);
	glColor3f(1, 1, 1);
    glVertex3f(0, 30, 20);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-70, 30, -20);
	glColor3f(0, 0, 0);
    glVertex3f(-70, 0, -15);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(0, 0, -15);
	glColor3f(1, 1, 1);
    glVertex3f(0, 30, -20);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-70, 0, 15);
	glColor3f(0, 0, 0);
    glVertex3f(-70, 0, -15);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(0, 0, -15);
	glColor3f(1, 1, 1);
    glVertex3f(0, 0, 15);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-70, 35, 30);
	glColor3f(0, 0, 0);
    glVertex3f(-70, 35, -30);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(0, 35, -30);
	glColor3f(1, 1, 1);
    glVertex3f(0, 35, 30);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-70, 30, 20);
	glColor3f(0, 0, 0);
    glVertex3f(-70, 32, 30);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(0, 32, 30);
	glColor3f(1, 1, 1);
    glVertex3f(0, 30, 20);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-70, 30, -20);
	glColor3f(0, 0, 0);
    glVertex3f(-70, 32, -30);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(0, 32, -30);
	glColor3f(1, 1, 1);
    glVertex3f(0, 30, -20);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-70, 35, -30);
	glColor3f(0, 0, 0);
    glVertex3f(-70, 32, -30);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(0, 32, -30);
	glColor3f(1, 1, 1);
    glVertex3f(0, 35, -30);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-70, 35, 30);
	glColor3f(0, 0, 0);
    glVertex3f(-70, 32, 30);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(0, 32, 30);
	glColor3f(1, 1, 1);
    glVertex3f(0, 35, 30);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0, 35, -30);
	glColor3f(0, 0, 0);
    glVertex3f(0, 32, -30);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(0, 30, -20);
	glColor3f(1, 1, 1);
    glVertex3f(0, 30, 20);
	glVertex3f(0, 32, 30);
	glVertex3f(0, 35, 30);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(0, 30, -20);
	glColor3f(0, 0, 0);
    glVertex3f(0, 0, -15);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(0, 0, 15);
	glColor3f(1, 1, 1);
    glVertex3f(0, 30, 20);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-70, 35, -30);
	glColor3f(0, 0, 0);
    glVertex3f(-70, 32, -30);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-70, 30, -20);
	glColor3f(1, 1, 1);
    glVertex3f(-70, 30, 20);
	glVertex3f(-70, 32, 30);
	glVertex3f(-70, 35, 30);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-70, 30, -20);
	glColor3f(0, 0, 0);
    glVertex3f(-70, 0, -15);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-70, 0, 15);
	glColor3f(1, 1, 1);
    glVertex3f(-70, 30, 20);
    glEnd();
}
void kaki()
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
    glColor3f(0.7, 0.7, 0);
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
	//kaca
	//depan
	glColor3f(1,1,1);
    glVertex3f(87, 55, 13.1);
    glVertex3f(86, 65, 13.1);
    glVertex3f(80, 65, 13.1);
    glVertex3f(79, 55, 13.1);
    //belakang
    glVertex3f(87, 55, -13.1);
    glVertex3f(86, 65, -13.1);
    glVertex3f(80, 65, -13.1);
    glVertex3f(79, 55, -13.1);
	glEnd();
}
void badan() {
	//depan
	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(45, 53, 10);
    glVertex3f(75, 71, 10);
    glVertex3f(75, 90, 10);
    glVertex3f(5, 90, 10);
    glVertex3f(5, 53, 10);
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
    //edit
    glBegin(GL_POLYGON);
    glVertex3f(-195, 53, 10);
    glVertex3f(-195, 95, 10);
    glVertex3f(-335, 70, 10);
    glVertex3f(-350, 53, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-153, 53, 10);
    glVertex3f(-153, 95, 10);
    glVertex3f(-195, 95, 10);
    glVertex3f(-195, 53, 10);
    glEnd();
    //edit

    //bolong depan

    glBegin(GL_POLYGON);
    glVertex3f(5, 70, 10);
    glVertex3f(5, 53, 10);
    glVertex3f(-90, 53, 10);
    glVertex3f(-90, 70, 10);
    glEnd();

	glBegin(GL_POLYGON);
    glVertex3f(-90, 60, 10);
    glVertex3f(-90, 53, 10);
    glVertex3f(-153, 53, 10);
    glVertex3f(-153, 60, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-127, 60, 10);
    glVertex3f(-127, 80, 10);
    glVertex3f(-137, 80, 10);
    glVertex3f(-137, 60, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-107, 60, 10);
    glVertex3f(-107, 80, 10);
    glVertex3f(-117, 80, 10);
    glVertex3f(-117, 60, 10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-87, 60, 10);
    glVertex3f(-87, 80, 10);
    glVertex3f(-97, 80, 10);
    glVertex3f(-97, 60, 10);
    glEnd();

    //bolong belakang

    glBegin(GL_POLYGON);
    glVertex3f(5, 70, -10);
    glVertex3f(5, 53, -10);
    glVertex3f(-90, 53, -10);
    glVertex3f(-90, 70, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glVertex3f(-90, 60, -10);
    glVertex3f(-90, 53, -10);
    glVertex3f(-153, 53, -10);
    glVertex3f(-153, 60, -10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-153, 53, -10);
    glVertex3f(-153, 95, -10);
    glVertex3f(-195, 95, -10);
    glVertex3f(-195, 53, -10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-127, 60, -10);
    glVertex3f(-127, 80, -10);
    glVertex3f(-137, 80, -10);
    glVertex3f(-137, 60, -10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-107, 60, -10);
    glVertex3f(-107, 80, -10);
    glVertex3f(-117, 80, -10);
    glVertex3f(-117, 60, -10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-87, 60, -10);
    glVertex3f(-87, 80, -10);
    glVertex3f(-97, 80, -10);
    glVertex3f(-97, 60, -10);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glVertex3f(45, 53, -10);
    glVertex3f(75, 71, -10);
    glVertex3f(75, 90, -10);
    glVertex3f(5, 90, -10);
    glVertex3f(5, 53, -10);
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

    //edit
    glBegin(GL_POLYGON);
    glVertex3f(-195, 53, -10);
    glVertex3f(-195, 95, -10);
    glVertex3f(-335, 70, -10);
    glVertex3f(-350, 53, -10);
    glEnd();
    //tutup bawah

    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-350, 53, 10);
    glVertex3f(-350, 53, -10);
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
    //tutup atas 
    glBegin(GL_POLYGON);
    glVertex3f(93, 95, 10);
    glVertex3f(93, 95, -10);
    glVertex3f(-195, 95, -10);
    glVertex3f(-195, 95, 10);
    glEnd();
    //tutup atas belakang
    glBegin(GL_POLYGON);
    glVertex3f(-195, 95, -10);
    glVertex3f(-195, 95, 10);
    glVertex3f(-335, 70, 10);
    glVertex3f(-335, 70, -10);
    glEnd();
    //tutup samping belakang
    glBegin(GL_POLYGON);
    glVertex3f(-335, 70, 10);
    glVertex3f(-335, 70, -10);
    glVertex3f(-350, 53, -10);
    glVertex3f(-350, 53, 10);
    glEnd();
}
void dekbarang()
{
	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(87, 70, 10);
    glVertex3f(78, 70, 10);
    glVertex3f(78, 71, 10);
    glVertex3f(87, 71, 10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(87, 70, -10);
    glVertex3f(78, 70, -10);
    glVertex3f(78, 71, -10);
    glVertex3f(87, 71, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(87, 70, 10);
    glVertex3f(78, 70, 10);
    glVertex3f(78, 70, -10);
    glVertex3f(87, 70, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(87, 71, 10);
    glVertex3f(78, 71, 10);
    glVertex3f(78, 71, -10);
    glVertex3f(87, 71, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(78, 70, 10);
    glVertex3f(78, 71, 10);
    glVertex3f(78, 71, -10);
    glVertex3f(78, 70, -10);

    glEnd();
	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(87, 70, 10);
    glVertex3f(87, 71, 10);
    glVertex3f(87, 71, -10);
    glVertex3f(87, 70, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(87, 70, 10);
    glVertex3f(91, 77, 10);
    glVertex3f(91, 77, -10);
    glVertex3f(87, 70, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(87, 71, 10);
    glVertex3f(91, 76, 10);
    glVertex3f(91, 76, -10);
    glVertex3f(87, 71, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(87, 71, 10);
    glVertex3f(87, 70, 10);
    glVertex3f(91, 76, 10);
    glVertex3f(91, 77, 10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(87, 71, -10);
    glVertex3f(87, 70, -10);
    glVertex3f(91, 76, -10);
    glVertex3f(91, 77, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(91, 76, 10);
    glVertex3f(102, 76, 10);
    glVertex3f(102, 76, -10);
    glVertex3f(91, 76, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(91, 77, 10);
    glVertex3f(101, 77, 10);
    glVertex3f(101, 77, -10);
    glVertex3f(91, 77, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(91, 76, 10);
    glVertex3f(102, 76, 10);
    glVertex3f(102, 77, 10);
    glVertex3f(91, 77, 10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(91, 76, -10);
    glVertex3f(102, 76, -10);
    glVertex3f(102, 77, -10);
    glVertex3f(91, 77, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(101, 76, -10);
    glVertex3f(101, 76, 10);
    glVertex3f(101, 82, 10);
    glVertex3f(101, 82, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(102, 76, -10);
    glVertex3f(102, 76, 10);
    glVertex3f(102, 81, 10);
    glVertex3f(102, 81, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(101, 76, 10);
    glVertex3f(101, 82, 10);
    glVertex3f(102, 82, 10);
    glVertex3f(102, 76, 10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(101, 76, -10);
    glVertex3f(101, 82, -10);
    glVertex3f(102, 82, -10);
    glVertex3f(102, 76, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(91, 76, 10);
    glVertex3f(101, 76, 10);
    glVertex3f(102, 77, 10);
    glVertex3f(92, 77, 10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(91, 76, -10);
    glVertex3f(101, 76, -10);
    glVertex3f(102, 77, -10);
    glVertex3f(92, 77, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(102, 81, -10);
    glVertex3f(102, 81, 10);
    glVertex3f(112, 81, 10);
    glVertex3f(112, 81, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(101, 82, -10);
    glVertex3f(101, 82, 10);
    glVertex3f(111, 82, 10);
    glVertex3f(111, 82, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(101, 81, 10);
    glVertex3f(101, 82, 10);
    glVertex3f(112, 82, 10);
    glVertex3f(112, 81, 10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(101, 81, -10);
    glVertex3f(101, 82, -10);
    glVertex3f(112, 82, -10);
    glVertex3f(112, 81, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(111, 82, 10);
    glVertex3f(111, 92, 10);
    glVertex3f(111, 92, -10);
    glVertex3f(111, 82, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex3f(112, 82, 10);
    glVertex3f(112, 92, 10);
    glVertex3f(112, 92, -10);
    glVertex3f(112, 82, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(111, 81, 10);
    glVertex3f(111, 92, 10);
    glVertex3f(112, 92, 10);
    glVertex3f(112, 81, 10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(111, 81, -10);
    glVertex3f(111, 92, -10);
    glVertex3f(112, 92, -10);
    glVertex3f(112, 81, -10);
    glEnd();

	glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex3f(111, 92, -10);
    glVertex3f(111, 92, 10);
    glVertex3f(112, 92, 10);
    glVertex3f(112, 92, -10);
    glEnd();

	//besi depan
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
    glVertex3f(111, 91, 10);
    glVertex3f(93, 91, 10);
    glVertex3f(93, 90, 10);
    glVertex3f(111, 90, 10);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
    glVertex3f(111, 88, 10);
    glVertex3f(93, 88, 10);
    glVertex3f(93, 87, 10);
    glVertex3f(111, 87, 10);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
    glVertex3f(111, 85, 10);
    glVertex3f(93, 85, 10);
    glVertex3f(93, 84, 10);
    glVertex3f(111, 84, 10);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
    glVertex3f(101, 81, 10);
    glVertex3f(93, 81, 10);
    glVertex3f(93, 80, 10);
    glVertex3f(101, 80, 10);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
    glVertex3f(101, 79, 10);
    glVertex3f(85, 79, 10);
    glVertex3f(85, 78, 10);
    glVertex3f(101, 78, 10);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
    glVertex3f(85, 75, 10);
    glVertex3f(90, 75, 10);
    glVertex3f(89, 74, 10);
    glVertex3f(85, 74, 10);
    glEnd();

	//besi belakang
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
    glVertex3f(111, 91, -10);
    glVertex3f(93, 91, -10);
    glVertex3f(93, 90, -10);
    glVertex3f(111, 90, -10);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
    glVertex3f(111, 88, -10);
    glVertex3f(93, 88, -10);
    glVertex3f(93, 87, -10);
    glVertex3f(111, 87, -10);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
    glVertex3f(111, 85, -10);
    glVertex3f(93, 85, -10);
    glVertex3f(93, 84, -10);
    glVertex3f(111, 84, -10);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
    glVertex3f(101, 81, -10);
    glVertex3f(93, 81, -10);
    glVertex3f(93, 80, -10);
    glVertex3f(101, 80, -10);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
    glVertex3f(101, 79, -10);
    glVertex3f(85, 79, -10);
    glVertex3f(85, 78, -10);
    glVertex3f(101, 78, -10);
    glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
    glVertex3f(85, 75, -10);
    glVertex3f(90, 75, -10);
    glVertex3f(89, 74, -10);
    glVertex3f(85, 74, -10);
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
    glColor3f(1, 1, 0);
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
}
void alas()
{
	//tanah
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0, 0);
    glVertex3f(220, -6, 200);
    glVertex3f(220, -6, -200);
    glVertex3f(-320, -6, -200);
    glVertex3f(-320, -6, 200);
    glEnd();
    //jalan
    glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.9);
    glVertex3f(220, -5, -80);
    glVertex3f(220, -5, 80);
    glVertex3f(-320, -5, 80);
    glVertex3f(-320, -5, -80);
    glEnd();
    //lis jalan
    glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
    glVertex3f(220, -4, -5);
    glVertex3f(220, -4, 5);
    glVertex3f(-320, -4, 5);
    glVertex3f(-320, -4, -5);
    glEnd();
    //trotoar1
    glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 0.5);
    glVertex3f(220, 3, 120);
    glVertex3f(220, 3, 80);
    glVertex3f(-320, 3, 80);
    glVertex3f(-320, 3, 120);
    glEnd();
    //bawah
    glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 0.5);
    glVertex3f(220, -5, 120);
    glVertex3f(220, -5, 80);
    glVertex3f(-320, -5, 80);
    glVertex3f(-320, -5, 120);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(220, 3, 120);
    glVertex3f(220, 3, 80);
    glVertex3f(-320, 3, 80);
    glVertex3f(-320, 3, 120);
    glEnd();
    //tutup depan
    glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 0.5);
    glVertex3f(220, 3, 120);
    glVertex3f(220, -6, 120);
    glVertex3f(-320, -6, 120);
    glVertex3f(-320, 3, 120);
    glEnd();
    //tutup belakang
    glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 0.5);
    glVertex3f(220, 3, 80);
    glVertex3f(220, -6, 80);
    glVertex3f(-320, -6, 80);
    glVertex3f(-320, 3, 80);
    glEnd();
     //trotoar2
    glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 0.5);
    glVertex3f(220, 3, -80);
    glVertex3f(220, 3, -120);
    glVertex3f(-320, 3, -120);
    glVertex3f(-320, 3, -80);
    glEnd();
    //bawah
    glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 0.5);
    glVertex3f(220, -5, -80);
    glVertex3f(220, -5, -120);
    glVertex3f(-320, -5, -120);
    glVertex3f(-320, -5, -80);
    glEnd();
     //lis
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(220, 3, -80);
    glVertex3f(220, 3, -120);
    glVertex3f(-320, 3, -120);
    glVertex3f(-320, 3, -80);
    glEnd();
    //tutup depan
    glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 0.5);
    glVertex3f(220, 3, -80);
    glVertex3f(220, -6, -80);
    glVertex3f(-320, -6, -80);
    glVertex3f(-320, 3, -80);
    glEnd();
    //tutup belakang
	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 0.5);
    glVertex3f(220, -6, -120);
    glVertex3f(220, 3, -120);
    glVertex3f(-320, 3, -120);
    glVertex3f(-320, -6, -120);
    glEnd();
     //besi
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 3, 140);
    glVertex3f(100, 3, 130);
    glVertex3f(-200, 3, 130);
    glVertex3f(-200, 3, 140);
    glEnd();
    //bawah
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, -5, 140);
    glVertex3f(100, -5, 130);
    glVertex3f(-200, -5, 130);
    glVertex3f(-200, -5, 140);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(100, 3, 140);
    glVertex3f(100, 3, 130);
    glVertex3f(-200, 3, 130);
    glVertex3f(-200, 3, 140);
    glEnd();
    //tutup depan
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 3, 140);
    glVertex3f(100, -6, 140);
    glVertex3f(-200, -6, 140);
    glVertex3f(-200, 3, 140);
    glEnd();
    //tutup belakang
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 3, 130);
    glVertex3f(100, -6, 130);
    glVertex3f(-200, -6, 130);
    glVertex3f(-200, 3, 130);
    glEnd();
    //besi2
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 3, 155);
    glVertex3f(100, 3, 145);
    glVertex3f(-200, 3, 145);
    glVertex3f(-200, 3, 155);
    glEnd();
    //bawah
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, -5, 155);
    glVertex3f(100, -5, 145);
    glVertex3f(-200, -5, 145);
    glVertex3f(-200, -5, 155);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(100, 3, 155);
    glVertex3f(100, 3, 145);
    glVertex3f(-200, 3, 145);
    glVertex3f(-200, 3, 155);
    glEnd();
    //tutup depan
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 3, 155);
    glVertex3f(100, -6, 155);
    glVertex3f(-200, -6, 155);
    glVertex3f(-200, 3, 155);
    glEnd();
    //tutup belakang
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 3, 145);
    glVertex3f(100, -6, 145);
    glVertex3f(-200, -6, 145);
    glVertex3f(-200, 3, 145);
    glEnd();
    //besi3
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 3, 170);
    glVertex3f(100, 3, 160);
    glVertex3f(-200, 3, 160);
    glVertex3f(-200, 3, 170);
    glEnd();
    //bawah
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, -5, 170);
    glVertex3f(100, -5, 160);
    glVertex3f(-200, -5, 160);
    glVertex3f(-200, -5, 170);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(100, 3, 170);
    glVertex3f(100, 3, 160);
    glVertex3f(-200, 3, 160);
    glVertex3f(-200, 3, 170);
    glEnd();
    //tutup depan
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 3, 170);
    glVertex3f(100, -6, 170);
    glVertex3f(-200, -6, 170);
    glVertex3f(-200, 3, 170);
    glEnd();
    //tutup belakang
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 3, 160);
    glVertex3f(100, -6, 160);
    glVertex3f(-200, -6, 160);
    glVertex3f(-200, 3, 160);
    glEnd();
     //besi4
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 12, 162);
    glVertex3f(100, 12, 152);
    glVertex3f(-200, 12, 152);
    glVertex3f(-200, 12, 162);
    glEnd();
    //bawah
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 4, 162);
    glVertex3f(100, 4, 152);
    glVertex3f(-200, 4, 152);
    glVertex3f(-200, 4, 162);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(100, 12, 162);
    glVertex3f(100, 12, 152);
    glVertex3f(-200, 12, 152);
    glVertex3f(-200, 12, 162);
    glEnd();
    //tutup depan
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 12, 162);
    glVertex3f(100, 5, 162);
    glVertex3f(-200, 5, 162);
    glVertex3f(-200, 12, 162);
    glEnd();
    //tutup belakang
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 12, 152);
    glVertex3f(100, 5, 152);
    glVertex3f(-200, 5, 152);
    glVertex3f(-200, 12, 152);
    glEnd();
    //besi5
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 12, 147);
    glVertex3f(100, 12, 137);
    glVertex3f(-200, 12, 137);
    glVertex3f(-200, 12, 147);
    glEnd();
    //bawah
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 4, 147);
    glVertex3f(100, 4, 137);
    glVertex3f(-200, 4, 137);
    glVertex3f(-200, 4, 147);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(100, 12, 147);
    glVertex3f(100, 12, 137);
    glVertex3f(-200, 12, 137);
    glVertex3f(-200, 12, 147);
    glEnd();
    //tutup depan
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 12, 147);
    glVertex3f(100, 5, 147);
    glVertex3f(-200, 5, 147);
    glVertex3f(-200, 12, 147);
    glEnd();
    //tutup belakang
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 12, 137);
    glVertex3f(100, 5, 137);
    glVertex3f(-200, 5, 137);
    glVertex3f(-200, 12, 137);
    glEnd();
     //besi6
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 21, 155);
    glVertex3f(100, 21, 145);
    glVertex3f(-200, 21, 145);
    glVertex3f(-200, 21, 155);
    glEnd();
    //bawah
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 13, 155);
    glVertex3f(100, 13, 145);
    glVertex3f(-200, 13, 145);
    glVertex3f(-200, 13, 155);
    glEnd();
    //lis
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(100, 21, 155);
    glVertex3f(100, 21, 145);
    glVertex3f(-200, 21, 145);
    glVertex3f(-200, 21, 155);
    glEnd();
    //tutup depan
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 21, 155);
    glVertex3f(100, 14, 155);
    glVertex3f(-200, 14, 155);
    glVertex3f(-200, 21, 155);
    glEnd();
    //tutup belakang
    glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
    glVertex3f(100, 21, 145);
    glVertex3f(100, 14, 145);
    glVertex3f(-200, 14, 145);
    glVertex3f(-200, 21, 145);
    glEnd();

}
void ban()
{
	glTranslatef(-58,6,15);
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
	glTranslatef(58,-7,-15);
	glColor3f(0.9, 0.9, 0);
    int n = 16;
    for (int m = 0; m < 10; m++) {        
        lingkaran(4, 60, 22+n, 7, 16);
        lingkaran(4, 60, 22 + n, 7, -24);
        lingkaran(4, 60, -42 + -n, 7, 16);
        lingkaran(4, 60, -42 + -n, 7, -24);
        n += 16;
    }
}
void mesin() {

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(135, 38, 16);
    glVertex3f(135, 60, 16);
    glVertex3f(123, 60, 16);
    glVertex3f(123, 38, 16);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(135, 38, -16);
    glVertex3f(135, 60, -16);
    glVertex3f(123, 60, -16);
    glVertex3f(123, 38, -16);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(135, 38, 16);
    glVertex3f(135, 60, 16);
    glVertex3f(135, 60, -16);
    glVertex3f(135, 38, -16);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(123, 38, 16);
    glVertex3f(123, 60, 16);
    glVertex3f(123, 60, -16);
    glVertex3f(123, 38, -16);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(123, 60, 16);
    glVertex3f(123, 60, -16);
    glVertex3f(135, 60, -16);
    glVertex3f(135, 60, 16);
    glEnd();
    //besi mesin 1

    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(137, 38, 18);
    glVertex3f(136, 38, 18);
    glVertex3f(136, 65, 18);
    glVertex3f(137, 65, 18);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(107, 38, 18);
    glVertex3f(106, 38, 18);
    glVertex3f(106, 65, 18);
    glVertex3f(107, 65, 18);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(122, 38, 18);
    glVertex3f(121, 38, 18);
    glVertex3f(121, 65, 18);
    glVertex3f(122, 65, 18);
    glEnd();

    // besi 1 belakang

    glBegin(GL_POLYGON);
    glVertex3f(137, 38, 17);
    glVertex3f(136, 38, 17);
    glVertex3f(136, 65, 17);
    glVertex3f(137, 65, 17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(107, 38, 17);
    glVertex3f(106, 38, 17);
    glVertex3f(106, 65, 17);
    glVertex3f(107, 65, 17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(122, 38, 17);
    glVertex3f(121, 38, 17);
    glVertex3f(121, 65, 17);
    glVertex3f(122, 65, 17);
    glEnd();

    //besi 2

    
    glBegin(GL_POLYGON);
    glVertex3f(137, 38, 0);
    glVertex3f(136, 38, 0);
    glVertex3f(136, 65, 0);
    glVertex3f(137, 65, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(107, 38, 0);
    glVertex3f(106, 38, 0);
    glVertex3f(106, 65, 0);
    glVertex3f(107, 65, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(122, 38, 0);
    glVertex3f(121, 38, 0);
    glVertex3f(121, 65, 0);
    glVertex3f(122, 65, 0);
    glEnd();

    //besi 2 belakang

    glBegin(GL_POLYGON);
    glVertex3f(137, 38, -1);
    glVertex3f(136, 38, -1);
    glVertex3f(136, 65, -1);
    glVertex3f(137, 65, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(107, 38, -1);
    glVertex3f(106, 38, -1);
    glVertex3f(106, 65, -1);
    glVertex3f(107, 65, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(122, 38, -1);
    glVertex3f(121, 38, -1);
    glVertex3f(121, 65, -1);
    glVertex3f(122, 65, -1);
    glEnd();

    //besi 3

    glBegin(GL_POLYGON);
    glVertex3f(137, 38, -17);
    glVertex3f(136, 38, -17);
    glVertex3f(136, 65,-17);
    glVertex3f(137, 65, -17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(107, 38, -17);
    glVertex3f(106, 38, -17);
    glVertex3f(106, 65, -17);
    glVertex3f(107, 65, -17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(122, 38, -17);
    glVertex3f(121, 38, -17);
    glVertex3f(121, 65, -17);
    glVertex3f(122, 65, -17);
    glEnd();

    //besi 3 belakang

    glBegin(GL_POLYGON);
    glVertex3f(137, 38, -18);
    glVertex3f(136, 38, -18);
    glVertex3f(136, 65, -18);
    glVertex3f(137, 65, -18);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(107, 38, -18);
    glVertex3f(106, 38, -18);
    glVertex3f(106, 65, -18);
    glVertex3f(107, 65, -18);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(122, 38, -18);
    glVertex3f(121, 38, -18);
    glVertex3f(121, 65, -18);
    glVertex3f(122, 65, -18);
    glEnd();

    // besi atas z

    glBegin(GL_POLYGON);
    glVertex3f(121, 65, 18);
    glVertex3f(122, 65, 18);
    glVertex3f(121, 65, -18);
    glVertex3f(122, 65, -18);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(107, 65, 18);
    glVertex3f(106, 65, 18);
    glVertex3f(106, 65, -18);
    glVertex3f(107, 65, -18);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(137, 65, 18);
    glVertex3f(136, 65, 18);
    glVertex3f(136, 65, -18);
    glVertex3f(137, 65, -18);
    glEnd();

    // besi atas x

    glBegin(GL_POLYGON);
    glVertex3f(106, 65, 0);
    glVertex3f(106, 65, -1);
    glVertex3f(137, 65, -1);
    glVertex3f(137, 65, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(106, 65, 18);
    glVertex3f(106, 65, 17);
    glVertex3f(137, 65, 17);
    glVertex3f(137, 65, 18);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(106, 65, -18);
    glVertex3f(106, 65, -17);
    glVertex3f(137, 65, -17);
    glVertex3f(137, 65, -18);
    glEnd();

    //tutup 1
    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(137, 38, 17);
    glVertex3f(137, 38, 18);
    glVertex3f(137, 65, 18);
    glVertex3f(137, 65, 17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(136, 38, 17);
    glVertex3f(136, 38, 18);
    glVertex3f(136, 65, 18);
    glVertex3f(136, 65, 17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(107, 38, 17);
    glVertex3f(107, 38, 18);
    glVertex3f(107, 65, 18);
    glVertex3f(107, 65, 17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(106, 38, 17);
    glVertex3f(106, 38, 18);
    glVertex3f(106, 65, 18);
    glVertex3f(106, 65, 17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(122, 38, 17);
    glVertex3f(122, 38, 18);
    glVertex3f(122, 65, 18);
    glVertex3f(122, 65, 17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(121, 38, 17);
    glVertex3f(121, 38, 18);
    glVertex3f(121, 65, 18);
    glVertex3f(121, 65, 17);
    glEnd();

    //tutup 2
    glBegin(GL_POLYGON);
    glVertex3f(137, 38, -1);
    glVertex3f(137, 38, 0);
    glVertex3f(137, 65, 0);
    glVertex3f(137, 65, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(136, 38, -1);
    glVertex3f(136, 38, 0);
    glVertex3f(136, 65, 0);
    glVertex3f(136, 65, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(107, 38, -1);
    glVertex3f(107, 38, 0);
    glVertex3f(107, 65, 0);
    glVertex3f(107, 65, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(106, 38,-1);
    glVertex3f(106, 38, 0);
    glVertex3f(106, 65, 0);
    glVertex3f(106, 65, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(122, 38, -1);
    glVertex3f(122, 38, 0);
    glVertex3f(122, 65, 0);
    glVertex3f(122, 65, -1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(121, 38, -1);
    glVertex3f(121, 38, 0);
    glVertex3f(121, 65, 0);
    glVertex3f(121, 65, -1);
    glEnd();

    //tutup 3

    glBegin(GL_POLYGON);
    glVertex3f(137, 38, -17);
    glVertex3f(137, 38, -18);
    glVertex3f(137, 65, -18);
    glVertex3f(137, 65, -17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(136, 38, -17);
    glVertex3f(136, 38, -18);
    glVertex3f(136, 65, -18);
    glVertex3f(136, 65, -17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(107, 38, -17);
    glVertex3f(107, 38, -18);
    glVertex3f(107, 65, -18);
    glVertex3f(107, 65, -17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(106, 38, -17);
    glVertex3f(106, 38, -18);
    glVertex3f(106, 65, -18);
    glVertex3f(106, 65, -17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(122, 38, -17);
    glVertex3f(122, 38, -18);
    glVertex3f(122, 65, -18);
    glVertex3f(122, 65, -17);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(121, 38, -17);
    glVertex3f(121, 38, -18);
    glVertex3f(121, 65, -18);
    glVertex3f(121, 65, -17);
    glEnd();

	//kotakhitam
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(160, 25, 14);
    glVertex3f(160, 65, 14);
    glVertex3f(142, 65, 14);
    glVertex3f(142, 25, 14);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(160, 25, -14);
    glVertex3f(160, 65, -14);
    glVertex3f(142, 65, -14);
    glVertex3f(142, 25, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(160, 25, 14);
    glVertex3f(160, 65, 14);
    glVertex3f(160, 65, -14);
    glVertex3f(160, 25, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(142, 25, 14);
    glVertex3f(142, 65, 14);
    glVertex3f(142, 65, -14);
    glVertex3f(142, 25, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(142, 65, 14);
    glVertex3f(142, 65, -14);
    glVertex3f(160, 65, -14);
    glVertex3f(160, 65, 14);
    glEnd();
    
    //kaca
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f(155, 30, 15);
    glVertex3f(155, 60, 15);
    glVertex3f(147, 60, 15);
    glVertex3f(147, 30, 15);
    glEnd();

	glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f(155, 30, -15);
    glVertex3f(155, 60, -15);
    glVertex3f(147, 60, -15);
    glVertex3f(147, 30, -15);
    glEnd();
    
    //tangga depan
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(170, 38, 15);
    glVertex3f(170, 40, 15);
    glVertex3f(160, 40, 15);
    glVertex3f(160, 38, 15);
    glEnd();

	glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(170, 38, -15);
    glVertex3f(170, 40, -15);
    glVertex3f(160, 40, -15);
    glVertex3f(160, 38, -15);
    glEnd();

	glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(170, 38, 15);
    glVertex3f(170, 40, 15);
    glVertex3f(192, 0, 15);
    glVertex3f(190, 0, 15);
    glEnd();

	glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(170, 38, -15);
    glVertex3f(170, 40, -15);
    glVertex3f(192, 0, -15);
    glVertex3f(190, 0, -15);
    glEnd();
	
	glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(167, 25, 15);
    glVertex3f(167, 27, -15);
    glVertex3f(160, 27, -15);
    glVertex3f(160, 25, 15);
    glEnd();
    
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(167, 25, -15);
    glVertex3f(167, 27, -15);
    glVertex3f(180, 0, -15);
    glVertex3f(182, 0, -15);
    glEnd();
    
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(167, 25, 15);
    glVertex3f(167, 27, 15);
    glVertex3f(180, 0, 15);
    glVertex3f(182, 0, 15);
    glEnd();
    
    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(164, 20, 15);
    glVertex3f(164, 22, -15);
    glVertex3f(171, 22, -15);
    glVertex3f(171, 20, 15);
    glEnd();
    
    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(168, 15, 15);
    glVertex3f(168, 17, -15);
    glVertex3f(175, 17, -15);
    glVertex3f(175, 15, 15);
    glEnd();
    
    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(172, 10, 15);
    glVertex3f(172, 12, -15);
    glVertex3f(179, 12, -15);
    glVertex3f(179, 10, 15);
    glEnd();
    
    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(176, 5, 15);
    glVertex3f(176, 7, -15);
    glVertex3f(183, 7, -15);
    glVertex3f(183, 5, 15);
    glEnd();

	
}
void imbuhan() {
    //depan
    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-165, 46, 19);
    glVertex3f(-165, 70, 19);
    glVertex3f(-155, 70, 19);
    glVertex3f(-155, 50, 19);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-165, 46, 15);
    glVertex3f(-165, 60, 15);
    glVertex3f(-155, 60, 15);
    glVertex3f(-155, 50, 15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-165, 60, 15);
    glVertex3f(-165, 60, 10);
    glVertex3f(-155, 60, 10);
    glVertex3f(-155, 60, 15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-165, 70, 19);
    glVertex3f(-165, 70, 10);
    glVertex3f(-155, 70, 10);
    glVertex3f(-155, 70, 19);
    glEnd(); 

    //tutup depan

    glBegin(GL_POLYGON);
    glVertex3f(-165, 46, 19);
    glVertex3f(-165, 70, 19);
    glVertex3f(-165, 70, 15);
    glVertex3f(-165, 46, 15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-155, 50, 19);
    glVertex3f(-155, 70, 19);
    glVertex3f(-155, 70, 15);
    glVertex3f(-155, 50, 15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-165, 70, 19);
    glVertex3f(-165, 70, 10);
    glVertex3f(-165, 60, 10);
    glVertex3f(-165, 60, 19);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-155, 70, 19);
    glVertex3f(-155, 70, 10);
    glVertex3f(-155, 60, 10);
    glVertex3f(-155, 60, 19);
    glEnd();

    //tutup belakang

    glBegin(GL_POLYGON);
    glVertex3f(-165, 46, -19);
    glVertex3f(-165, 70, -19);
    glVertex3f(-165, 70, -15);
    glVertex3f(-165, 46, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-155, 50, -19);
    glVertex3f(-155, 70, -19);
    glVertex3f(-155, 70, -15);
    glVertex3f(-155, 50, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-165, 70, -19);
    glVertex3f(-165, 70, -10);
    glVertex3f(-165, 60, -10);
    glVertex3f(-165, 60, -19);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-155, 70, -19);
    glVertex3f(-155, 70, -10);
    glVertex3f(-155, 60, -10);
    glVertex3f(-155, 60, -19);
    glEnd();

    //belakang

    glBegin(GL_POLYGON);
    glVertex3f(-165, 46, -19);
    glVertex3f(-165, 70, -19);
    glVertex3f(-155, 70, -19);
    glVertex3f(-155, 50, -19);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-165, 46, -15);
    glVertex3f(-165, 60, -15);
    glVertex3f(-155, 60, -15);
    glVertex3f(-155, 50, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-165, 60, -15);
    glVertex3f(-165, 60, -10);
    glVertex3f(-155, 60, -10);
    glVertex3f(-155, 60, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-165, 70, -19);
    glVertex3f(-165, 70, -10);
    glVertex3f(-155, 70, -10);
    glVertex3f(-155, 70, -19);
    glEnd();

    //tengah depan
    glColor3f(0.7 ,0.7 , 0);
    glBegin(GL_POLYGON);
    glVertex3f(25, 36, 5);
    glVertex3f(35, 39, 5);
    glVertex3f(35, 53, 5);
    glVertex3f(25, 53, 5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(35, 39, 5);
    glVertex3f(35, 53, 5);
    glVertex3f(35, 53, -5);
    glVertex3f(35, 39,-5);
    glEnd();

    //tengah depan,belakang

    glBegin(GL_POLYGON);
    glVertex3f(25, 36, -5);
    glVertex3f(35, 39, -5);
    glVertex3f(35, 53, -5);
    glVertex3f(25, 53, -5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(25, 36, -5);
    glVertex3f(25, 36, 5);
    glVertex3f(25, 53, 5);
    glVertex3f(25, 53, -5);
    glEnd();
}
void pengaitbelakang() {
    //depan
    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-60, 30, 19);
    glVertex3f(-60, 70, 19);
    glVertex3f(-50, 70, 19);
    glVertex3f(-50, 30, 19);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-60, 30, 15);
    glVertex3f(-60, 60, 15);
    glVertex3f(-50, 60, 15);
    glVertex3f(-50, 30, 15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-60, 60, 15);
    glVertex3f(-60, 60, 10);
    glVertex3f(-50, 60, 10);
    glVertex3f(-50, 60, 15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-60, 70, 19);
    glVertex3f(-60, 70, 10);
    glVertex3f(-50, 70, 10);
    glVertex3f(-50, 70, 19);
    glEnd(); 

    //tutup depan

    glBegin(GL_POLYGON);
    glVertex3f(-60, 30, 19);
    glVertex3f(-60, 70, 19);
    glVertex3f(-60, 70, 15);
    glVertex3f(-60, 30, 15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-50, 30, 19);
    glVertex3f(-50, 70, 19);
    glVertex3f(-50, 70, 15);
    glVertex3f(-50, 30, 15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-60, 70, 19);
    glVertex3f(-60, 70, 10);
    glVertex3f(-60, 60, 10);
    glVertex3f(-60, 60, 19);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-50, 70, 19);
    glVertex3f(-50, 70, 10);
    glVertex3f(-50, 60, 10);
    glVertex3f(-50, 60, 19);
    glEnd();

    //tutup belakang

    glBegin(GL_POLYGON);
    glVertex3f(-60, 30, -19);
    glVertex3f(-60, 70, -19);
    glVertex3f(-60, 70, -15);
    glVertex3f(-60, 30, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-50, 30, -19);
    glVertex3f(-50, 70, -19);
    glVertex3f(-50, 70, -15);
    glVertex3f(-50, 30, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-60, 70, -19);
    glVertex3f(-60, 70, -10);
    glVertex3f(-60, 60, -10);
    glVertex3f(-60, 60, -19);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-50, 70, -19);
    glVertex3f(-50, 70, -10);
    glVertex3f(-50, 60, -10);
    glVertex3f(-50, 60, -19);
    glEnd();

    //belakang

    glBegin(GL_POLYGON);
    glVertex3f(-60, 30, -19);
    glVertex3f(-60, 70, -19);
    glVertex3f(-50, 70, -19);
    glVertex3f(-50, 30, -19);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-60, 30, -15);
    glVertex3f(-60, 60, -15);
    glVertex3f(-50, 60, -15);
    glVertex3f(-50, 30, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-60, 60, -15);
    glVertex3f(-60, 60, -10);
    glVertex3f(-50, 60, -10);
    glVertex3f(-50, 60, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-60, 70, -19);
    glVertex3f(-60, 70, -10);
    glVertex3f(-50, 70, -10);
    glVertex3f(-50, 70, -19);
    glEnd();
}
void pengaitdepan() {
    //depan
    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-10, 30, 19);
    glVertex3f(-10, 70, 19);
    glVertex3f(-20, 70, 19);
    glVertex3f(-20, 30, 19);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-10, 30, 15);
    glVertex3f(-10, 60, 15);
    glVertex3f(-20, 60, 15);
    glVertex3f(-20, 30, 15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-10, 60, 15);
    glVertex3f(-10, 60, 10);
    glVertex3f(-20, 60, 10);
    glVertex3f(-20, 60, 15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-10, 70, 19);
    glVertex3f(-10, 70, 10);
    glVertex3f(-20, 70, 10);
    glVertex3f(-20, 70, 19);
    glEnd(); 

    //tutup depan

    glBegin(GL_POLYGON);
    glVertex3f(-10, 30, 19);
    glVertex3f(-10, 70, 19);
    glVertex3f(-10, 70, 15);
    glVertex3f(-10, 30, 15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-20, 30, 19);
    glVertex3f(-20, 70, 19);
    glVertex3f(-20, 70, 15);
    glVertex3f(-20, 30, 15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-10, 70, 19);
    glVertex3f(-10, 70, 10);
    glVertex3f(-10, 60, 10);
    glVertex3f(-10, 60, 19);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-20, 70, 19);
    glVertex3f(-20, 70, 10);
    glVertex3f(-20, 60, 10);
    glVertex3f(-20, 60, 19);
    glEnd();

    //tutup belakang

    glBegin(GL_POLYGON);
    glVertex3f(-10, 30, -19);
    glVertex3f(-10, 70, -19);
    glVertex3f(-10, 70, -15);
    glVertex3f(-10, 30, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-20, 30, -19);
    glVertex3f(-20, 70, -19);
    glVertex3f(-20, 70, -15);
    glVertex3f(-20, 30, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-10, 70, -19);
    glVertex3f(-10, 70, -10);
    glVertex3f(-10, 60, -10);
    glVertex3f(-10, 60, -19);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-20, 70, -19);
    glVertex3f(-20, 70, -10);
    glVertex3f(-20, 60, -10);
    glVertex3f(-20, 60, -19);
    glEnd();

    //belakang

    glBegin(GL_POLYGON);
    glVertex3f(-10, 30, -19);
    glVertex3f(-10, 70, -19);
    glVertex3f(-20, 70, -19);
    glVertex3f(-20, 30, -19);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-10, 30, -15);
    glVertex3f(-10, 60, -15);
    glVertex3f(-20, 60, -15);
    glVertex3f(-20, 30, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-10, 60, -15);
    glVertex3f(-10, 60, -10);
    glVertex3f(-20, 60, -10);
    glVertex3f(-20, 60, -15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-10, 70, -19);
    glVertex3f(-10, 70, -10);
    glVertex3f(-20, 70, -10);
    glVertex3f(-20, 70, -19);
    glEnd();
}
void pengaitban()
{
	int b=0;
	for(int c=0;c<=1;c++)
	{
		for(int a=0;a<=9;a++)
		{
			glBegin(GL_POLYGON);
			glColor3f(0.7, 0.7, 0);
			glVertex3f(156-b, 10, 18);
			glVertex3f(156-b, 13, 18);
			glVertex3f(157-b, 13, 18);
			glVertex3f(157-b, 10, 18);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 10, 19);
			glVertex3f(156-b, 13, 19);
			glVertex3f(157-b, 13, 19);
			glVertex3f(157-b, 10, 19);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 10, 18);
			glVertex3f(156-b, 13, 18);
			glVertex3f(156-b, 13, 19);
			glVertex3f(156-b, 10, 19);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(157-b, 10, 18);
			glVertex3f(157-b, 13, 18);
			glVertex3f(157-b, 13, 19);
			glVertex3f(157-b, 10, 19);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 10, 18);
			glVertex3f(156-b, 10, 20);
			glVertex3f(157-b, 10, 20);
			glVertex3f(157-b, 10, 18);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 11, 18);
			glVertex3f(156-b, 11, 20);
			glVertex3f(157-b, 11, 20);
			glVertex3f(157-b, 11, 18);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 10, 18);
			glVertex3f(156-b, 10, 20);
			glVertex3f(156-b, 11, 20);
			glVertex3f(156-b, 11, 18);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(157-b, 10, 18);
			glVertex3f(157-b, 10, 20);
			glVertex3f(157-b, 11, 20);
			glVertex3f(157-b, 11, 18);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 10, 18);
			glVertex3f(156-b, 11, 18);
			glVertex3f(157-b, 11, 18);
			glVertex3f(157-b, 10, 18);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 10, 20);
			glVertex3f(156-b, 11, 20);
			glVertex3f(157-b, 11, 20);
			glVertex3f(157-b, 10, 20);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 6, 19);
			glVertex3f(156-b, 10, 19);
			glVertex3f(157-b, 10, 19);
			glVertex3f(157-b, 6, 19);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 6, 20);
			glVertex3f(156-b, 10, 20);
			glVertex3f(157-b, 10, 20);
			glVertex3f(157-b, 6, 20);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 6, 19);
			glVertex3f(156-b, 10, 19);
			glVertex3f(156-b, 10, 20);
			glVertex3f(156-b, 6, 20);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(157-b, 6, 19);
			glVertex3f(157-b, 10, 19);
			glVertex3f(157-b, 10, 20);
			glVertex3f(157-b, 6, 20);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 10, -18);
			glVertex3f(156-b, 13, -18);
			glVertex3f(157-b, 13, -18);
			glVertex3f(157-b, 10, -18);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 10, -19);
			glVertex3f(156-b, 13, -19);
			glVertex3f(157-b, 13, -19);
			glVertex3f(157-b, 10, -19);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 10, -18);
			glVertex3f(156-b, 13, -18);
			glVertex3f(156-b, 13, -19);
			glVertex3f(156-b, 10, -19);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(157-b, 10, -18);
			glVertex3f(157-b, 13, -18);
			glVertex3f(157-b, 13, -19);
			glVertex3f(157-b, 10, -19);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 10, -18);
			glVertex3f(156-b, 10, -20);
			glVertex3f(157-b, 10, -20);
			glVertex3f(157-b, 10, -18);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 11, -18);
			glVertex3f(156-b, 11, -20);
			glVertex3f(157-b, 11, -20);
			glVertex3f(157-b, 11, -18);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 10, -18);
			glVertex3f(156-b, 10, -20);
			glVertex3f(156-b, 11, -20);
			glVertex3f(156-b, 11, -18);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(157-b, 10, -18);
			glVertex3f(157-b, 10, -20);
			glVertex3f(157-b, 11, -20);
			glVertex3f(157-b, 11, -18);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 10, -18);
			glVertex3f(156-b, 11, -18);
			glVertex3f(157-b, 11, -18);
			glVertex3f(157-b, 10, -18);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 10, -20);
			glVertex3f(156-b, 11, -20);
			glVertex3f(157-b, 11, -20);
			glVertex3f(157-b, 10, -20);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 6, -19);
			glVertex3f(156-b, 10, -19);
			glVertex3f(157-b, 10, -19);
			glVertex3f(157-b, 6, -19);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 6, -20);
			glVertex3f(156-b, 10, -20);
			glVertex3f(157-b, 10, -20);
			glVertex3f(157-b, 6, -20);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(156-b, 6, -19);
			glVertex3f(156-b, 10, -19);
			glVertex3f(156-b, 10, -20);
			glVertex3f(156-b, 6, -20);
			glEnd();

			glBegin(GL_POLYGON);
			glVertex3f(157-b, 6, -19);
			glVertex3f(157-b, 10, -19);
			glVertex3f(157-b, 10, -20);
			glVertex3f(157-b, 6, -20);
			glEnd();

			b+=16;
		}
		b=240;
	}
}
void pegas() {
    glColor3f(0.7, 0.7, 0);
    //depan
    glBegin(GL_POLYGON);
    glVertex3f(-310, 70, 15);
    glVertex3f(-310, 80, 15);
    glVertex3f(-300, 80, 15);
    glVertex3f(-300, 70, 15);
    glEnd();
    //tutup deapan
    glBegin(GL_POLYGON);
    glVertex3f(-310, 70, 15);
    glVertex3f(-310, 70, 10);
    glVertex3f(-300, 70, 10);
    glVertex3f(-300, 70, 15);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glVertex3f(-310, 70, -15);
    glVertex3f(-310, 80, -15);
    glVertex3f(-300, 80, -15);
    glVertex3f(-300, 70, -15);
    glEnd();
    //tutup belakang
    glBegin(GL_POLYGON);
    glVertex3f(-310, 70, -15);
    glVertex3f(-310, 70, -10);
    glVertex3f(-300, 70, -10);
    glVertex3f(-300, 70, -15);
    glEnd();
    //batang
    glBegin(GL_POLYGON);
    glVertex3f(-310, 70, 15);
    glVertex3f(-310, 70, -15);
    glVertex3f(-310, 80, -15);
    glVertex3f(-310, 80, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-300, 70, 15);
    glVertex3f(-300, 70, -15);
    glVertex3f(-300, 80, -15);
    glVertex3f(-300, 80, 15);
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    glVertex3f(-310, 80, 15);
    glVertex3f(-310, 85, 10);
    glVertex3f(-300, 85, 10);
    glVertex3f(-300, 80, 15);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-310, 80, -15);
    glVertex3f(-310, 85, -10);
    glVertex3f(-300, 85, -10);
    glVertex3f(-300, 80, -15);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-310, 85, 10);
    glVertex3f(-310, 85, -10);
    glVertex3f(-300, 85, -10);
    glVertex3f(-300, 85, 10);
    glEnd();
    //atas z
    glBegin(GL_POLYGON);
    glVertex3f(-310, 80, 15);
    glVertex3f(-310, 85, 10);
    glVertex3f(-310, 85, -10);
    glVertex3f(-310, 80, -15);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-300, 80, 15);
    glVertex3f(-300, 85, 10);
    glVertex3f(-300, 85, -10);
    glVertex3f(-300, 80, -15);
    glEnd();
    glColor3f(0, 0, 0);
    lingkaran(2, 55, -305, 75, 15.2);
    lingkaran(2, 55, -305, 75, -15.2);
    //panjang
    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-310, 70, 14);
    glVertex3f(-300, 70, 14);
    glVertex3f(-300, 60, 14);
    glVertex3f(-308, 56, 14);
    glEnd();

    glBegin(GL_POLYGON);    
    glVertex3f(-308, 56, 14);
    glVertex3f(-306, 58, 14);
    glVertex3f(-302, 48, 14);
    glVertex3f(-304, 46, 14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-300, 60, 14);
    glVertex3f(-302, 59, 14);
    glVertex3f(-299, 51, 14);
    glVertex3f(-297, 53, 14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-304, 46, 14);
    glVertex3f(-297, 53, 14);
    glVertex3f(-296, 51, 14);
    glVertex3f(-303, 44, 14);
    glEnd();
    
    glBegin(GL_POLYGON);
    glVertex3f(-303, 44, 14);
    glVertex3f(-301, 46, 14);
    glVertex3f(-296, 36, 14);
    glVertex3f(-298, 34, 14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-296, 51, 14);
    glVertex3f(-298, 49, 14);
    glVertex3f(-293, 39, 14);
    glVertex3f(-291, 41, 14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-291, 41, 14);
    glVertex3f(-298, 34, 14);
    glVertex3f(-297, 32, 14);
    glVertex3f(-290, 39, 14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-290, 39, 14);
    glVertex3f(-292, 37, 14);
    glVertex3f(-289, 31, 14);
    glVertex3f(-287, 33, 14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-297, 32, 14);
    glVertex3f(-295, 34, 14);
    glVertex3f(-292, 28, 14);
    glVertex3f(-294, 26, 14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-287, 33, 14);
    glVertex3f(-294, 26, 14);
    glVertex3f(-293, 24, 14);
    glVertex3f(-286, 31, 14);
    glEnd();
    //panjang tutup
    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-310, 70, 12);
    glVertex3f(-300, 70, 12);
    glVertex3f(-300, 60, 12);
    glVertex3f(-308, 56, 12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-308, 56, 12);
    glVertex3f(-306, 58, 12);
    glVertex3f(-302, 48, 12);
    glVertex3f(-304, 46, 12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-300, 60, 12);
    glVertex3f(-302, 59, 12);
    glVertex3f(-299, 51, 12);
    glVertex3f(-297, 53, 12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-304, 46, 12);
    glVertex3f(-297, 53, 12);
    glVertex3f(-296, 51, 12);
    glVertex3f(-303, 44, 12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-303, 44, 12);
    glVertex3f(-301, 46, 12);
    glVertex3f(-296, 36, 12);
    glVertex3f(-298, 34, 12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-296, 51, 12);
    glVertex3f(-298, 49, 12);
    glVertex3f(-293, 39, 12);
    glVertex3f(-291, 41, 12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-291, 41, 12);
    glVertex3f(-298, 34, 12);
    glVertex3f(-297, 32, 12);
    glVertex3f(-290, 39, 12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-290, 39, 12);
    glVertex3f(-292, 37, 12);
    glVertex3f(-289, 31, 12);
    glVertex3f(-287, 33, 12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-297, 32, 12);
    glVertex3f(-295, 34, 12);
    glVertex3f(-292, 28, 12);
    glVertex3f(-294, 26, 12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-287, 33, 12);
    glVertex3f(-294, 26, 12);
    glVertex3f(-293, 24, 12);
    glVertex3f(-286, 31, 12);
    glEnd();
    //tutup z

    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-310, 70, 14);
    glVertex3f(-310, 70, 12);
    glVertex3f(-308, 56, 12);
    glVertex3f(-308, 56, 14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-300, 70, 12);
    glVertex3f(-300, 70, 14);
    glVertex3f(-300, 60, 14);
    glVertex3f(-300, 60, 12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-300, 60, 14);
    glVertex3f(-300, 60, 12);
    glVertex3f(-286, 31, 12);
    glVertex3f(-286, 31, 14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-308, 56, 14);
    glVertex3f(-308, 56, 12);
    glVertex3f(-293, 24, 12);
    glVertex3f(-293, 24, 14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-286, 31, 14);
    glVertex3f(-286, 31, 12);
    glVertex3f(-293, 24, 12);
    glVertex3f(-293, 24, 14);
    glEnd();

    //panjang belakang

    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-310, 70, -14);
    glVertex3f(-300, 70, -14);
    glVertex3f(-300, 60, -14);
    glVertex3f(-308, 56, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-308, 56, -14);
    glVertex3f(-306, 58, -14);
    glVertex3f(-302, 48, -14);
    glVertex3f(-304, 46, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-300, 60, -14);
    glVertex3f(-302, 59, -14);
    glVertex3f(-299, 51, -14);
    glVertex3f(-297, 53, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-304, 46, -14);
    glVertex3f(-297, 53, -14);
    glVertex3f(-296, 51, -14);
    glVertex3f(-303, 44, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-303, 44, -14);
    glVertex3f(-301, 46, -14);
    glVertex3f(-296, 36, -14);
    glVertex3f(-298, 34, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-296, 51, -14);
    glVertex3f(-298, 49, -14);
    glVertex3f(-293, 39, -14);
    glVertex3f(-291, 41, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-291, 41, -14);
    glVertex3f(-298, 34, -14);
    glVertex3f(-297, 32, -14);
    glVertex3f(-290, 39, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-290, 39, -14);
    glVertex3f(-292, 37, -14);
    glVertex3f(-289, 31, -14);
    glVertex3f(-287, 33, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-297, 32, -14);
    glVertex3f(-295, 34, -14);
    glVertex3f(-292, 28, -14);
    glVertex3f(-294, 26, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-287, 33, -14);
    glVertex3f(-294, 26, -14);
    glVertex3f(-293, 24, -14);
    glVertex3f(-286, 31, -14);
    glEnd();
    //panjang tutup
    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-310, 70, -12);
    glVertex3f(-300, 70, -12);
    glVertex3f(-300, 60, -12);
    glVertex3f(-308, 56, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-308, 56, -12);
    glVertex3f(-306, 58, -12);
    glVertex3f(-302, 48, -12);
    glVertex3f(-304, 46, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-300, 60, -12);
    glVertex3f(-302, 59, -12);
    glVertex3f(-299, 51, -12);
    glVertex3f(-297, 53, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-304, 46, -12);
    glVertex3f(-297, 53, -12);
    glVertex3f(-296, 51, -12);
    glVertex3f(-303, 44, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-303, 44, -12);
    glVertex3f(-301, 46, -12);
    glVertex3f(-296, 36, -12);
    glVertex3f(-298, 34, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-296, 51, -12);
    glVertex3f(-298, 49, -12);
    glVertex3f(-293, 39, -12);
    glVertex3f(-291, 41, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-291, 41, -12);
    glVertex3f(-298, 34, -12);
    glVertex3f(-297, 32, -12);
    glVertex3f(-290, 39, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-290, 39, -12);
    glVertex3f(-292, 37, -12);
    glVertex3f(-289, 31, -12);
    glVertex3f(-287, 33, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-297, 32, -12);
    glVertex3f(-295, 34, -12);
    glVertex3f(-292, 28, -12);
    glVertex3f(-294, 26, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-287, 33, -12);
    glVertex3f(-294, 26, -12);
    glVertex3f(-293, 24, -12);
    glVertex3f(-286, 31, -12);
    glEnd();
    //tutup z

    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-310, 70, -14);
    glVertex3f(-310, 70, -12);
    glVertex3f(-308, 56, -12);
    glVertex3f(-308, 56, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-300, 70, -12);
    glVertex3f(-300, 70, -14);
    glVertex3f(-300, 60, -14);
    glVertex3f(-300, 60, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-300, 60, -14);
    glVertex3f(-300, 60, -12);
    glVertex3f(-286, 31, -12);
    glVertex3f(-286, 31, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-308, 56, -14);
    glVertex3f(-308, 56, -12);
    glVertex3f(-293, 24, -12);
    glVertex3f(-293, 24, -14);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-286, 31, -14);
    glVertex3f(-286, 31, -12);
    glVertex3f(-293, 24, -12);
    glVertex3f(-293, 24, -14);
    glEnd();

	//per
	glBegin(GL_POLYGON);
    glColor3f(0.7, 0.7, 0);
    glVertex3f(-292, 25, 13.5);
    glVertex3f(-287, 30, 13.5);
    glVertex3f(-276, 8, 13.5);
    glVertex3f(-282, 5, 13.5);    
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-292, 25, 12.5);
    glVertex3f(-287, 30, 12.5);
    glVertex3f(-276, 8, 12.5);
    glVertex3f(-282, 5, 12.5);
    glEnd();

    //tutup
    glColor3f(0.7,0.7,0);
    glBegin(GL_POLYGON);
    glVertex3f(-287, 30, 13.5);
    glVertex3f(-287, 30, 12.5);
    glVertex3f(-276, 8, 12.5);
    glVertex3f(-276, 8, 13.5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-292, 25, 12.5);
    glVertex3f(-292, 25, 13.5);
    glVertex3f(-282, 5, 13.5);
    glVertex3f(-282, 5, 12.5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-276, 8, 12.5);
    glVertex3f(-276, 8, 13.5);
    glVertex3f(-282, 5, 13.5);
    glVertex3f(-282, 5, 12.5);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.7, 0);
    glVertex3f(-292, 25, -13.5);
    glVertex3f(-287, 30, -13.5);
    glVertex3f(-276, 8, -13.5);
    glVertex3f(-282, 5, -13.5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-292, 25, -12.5);
    glVertex3f(-287, 30, -12.5);
    glVertex3f(-276, 8, -12.5);
    glVertex3f(-282, 5, -12.5);
    glEnd();

    //tutup
    glColor3f(0.7, 0.7, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-287, 30, -13.5);
    glVertex3f(-287, 30,-12.5);
    glVertex3f(-276, 8, -12.5);
    glVertex3f(-276, 8, -13.5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-292, 25, -12.5);
    glVertex3f(-292, 25,-13.5);
    glVertex3f(-282, 5, -13.5);
    glVertex3f(-282, 5, -12.5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-276, 8, -12.5);
    glVertex3f(-276, 8, -13.5);
    glVertex3f(-282, 5, -13.5);
    glVertex3f(-282, 5, -12.5);
    glEnd();

	//tahan
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0);
	//depan
	glVertex3f(-287, 3, 14);
	glVertex3f(-287, 0, 14);
	glVertex3f(-221, 31, 14);
	glVertex3f(-221, 34, 14);
	//belakang
	glVertex3f(-287, 3, -14);
	glVertex3f(-287, 0, -14);
	glVertex3f(-221, 31, -14);
	glVertex3f(-221, 34, -14);
	//atas
	glColor3f(0.7, 0.7, 0);
	glVertex3f(-287, 3, -14);
	glVertex3f(-287, 3, 14);
	glVertex3f(-221, 34, 14);
	glVertex3f(-221, 34, -14);
	//bawah
	glVertex3f(-287, 0, -14);
	glVertex3f(-287, 0, 14);
	glVertex3f(-221, 31, 14);
	glVertex3f(-221, 31, -14);
	glEnd();
}