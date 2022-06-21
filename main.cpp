#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
static float cloud1 = -20, ty = 0;

void circle(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    int i=0;
    float angle;
    GLfloat PI= 2.0f * 3.1416;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    for(i=0;i<100;i++)
    {
        angle = 2 * PI * i/100;
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)* ry));
    }
    glEnd();
}

void cloudMove()
{
    cloud1 += .002;
    if(cloud1 > 400){
        cloud1 = -20;
    }
    glutPostRedisplay();
}
void movingCloud()
{
    glColor3f(1,1,1);
    cloudMove();
    glPushMatrix();
        glTranslatef(cloud1,-15,0);
        circle(3,5,5,88);
        circle(3,5,8,91);
        circle(3,5,12,92);
        circle(3,5,12,87);
        circle(3,5,7,85);

        glTranslatef(cloud1,-15,0);
        circle(3,5,5,88);
        circle(3,5,8,91);
        circle(3,5,12,92);
        circle(3,5,12,87);
        circle(3,5,7,85);
    glPopMatrix();


}



void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    movingCloud();



    glBegin(GL_TRIANGLES);
        glColor3f(0.0f,0.0f,1.0f);

        glVertex3d(60.0,40.0,0.0);
        glVertex3d(35.0,60.0,0.0);
        glVertex3d(10.0,40.0,0.0);

    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3d(60.0,0.0,0.0);
        glVertex3d(60.0,40.0,0.0);
        glVertex3d(10.0,40.0,0.0);
        glVertex3d(10.0,0.0,0.0);
        //door
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3d(40.0,0.0,0.0);
        glVertex3d(40.0,25.0,0.0);
        glVertex3d(30.0,25.0,0.0);
        glVertex3d(30.0,0.0,0.0);

        glColor3f(1.0f,1.0f,1.0f);
        glVertex3d(25.0,10.0,0.0);
        glVertex3d(25.0,20.0,0.0);
        glVertex3d(15.0,20.0,0.0);
        glVertex3d(15.0,10.0,0.0);


        glColor3f(1.0f,1.0f,1.0f);
        glVertex3d(55.0,10.0,0.0);
        glVertex3d(55.0,20.0,0.0);
        glVertex3d(45.0,20.0,0.0);
        glVertex3d(45.0,10.0,0.0);






    glEnd();







    glFlush();
}


void init(void)
{
    glClearColor(0.0, 1.0, 1.0, 0.0);
    glOrtho(0, 100.0, 0, 100.0, 0, 100.0);
}

int main()
{
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Transformation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
