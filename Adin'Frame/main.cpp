#include <GL/glut.h>
#include <math.h>

//sun ray
void display1(float x1,float y1, float x2,float y2)
{
    //glClear(GL_COLOR_BUFFER_BIT);


    float dx= x2-x1;
    float dy= y2-y1;
    float m =dy/dx;
     float x = x1;
    float y = y1;


    glPointSize(5);

    glBegin(GL_POINTS);

    if (fabs(m) < 1)
    {
        while(x <= x2 && y <= y2)
        {
            glVertex2f(x, y);
            x=x+ 1;
            y = y+m;
        }
    }
    else
    {
        while(y<= y2)
        {
            glVertex2f(x, y);
            y=y +1;
            x =x +(1/m);
        }
    }

    glEnd();
    glFlush();
}
void display2(float x3,float y3, float x4,float y4)
{
    //glClear(GL_COLOR_BUFFER_BIT);


    float dx1= x4-x3;
    float dy1= y4-y3;
    float m =dy1/dx1;
     float x = x3;
    float y = y3;


    glPointSize(5);

    glBegin(GL_POINTS);

    if (fabs(m) < 1)
    {
        while(x <= x4 && y <= y4)
        {
            glVertex2f(x, y);
            x=x+ 1;
            y = y+m;
        }
    }
    else
    {
        while(y<= y4)
        {
            glVertex2f(x, y);
            y=y +1;
            x =x +(1/m);
        }
    }

    glEnd();
    glFlush();
}
void display3(float x5,float y5, float x6,float y6)
{
    //glClear(GL_COLOR_BUFFER_BIT);


    float dx2= x6-x5;
    float dy2= y6-y5;
    float m =dy2/dx2;
     float x = x5;
    float y = y5;


    glPointSize(5);

    glBegin(GL_POINTS);

    if (fabs(m) < 1)
    {
        while(x <= x6&& y <= y6)
        {
            glVertex2f(x, y);
            x=x+ 1;
            y = y+m;
        }
    }
    else
    {
        while(y<= y6)
        {
            glVertex2f(x, y);
            y=y +1;
            x =x +(1/m);
        }
    }

    glEnd();
    glFlush();
}
void display4(float x7,float y7, float x8,float y8)
{
    //glClear(GL_COLOR_BUFFER_BIT);


    float dx3= x8-x7;
    float dy3= y8-y7;
    float m =dy3/dx3;
     float x = x7;
    float y = y7;


    glPointSize(5);

    glBegin(GL_POINTS);

    if (fabs(m) < 1)
    {
        while(x <= x8&& y <= y8)
        {
            glVertex2f(x, y);
            x=x+ 1;
            y = y+m;
        }
    }
    else
    {
        while(y<= y8)
        {
            glVertex2f(x, y);
            y=y +1;
            x =x +(1/m);
        }
    }

    glEnd();
    glFlush();
}
void display5()
{
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1,  1, 1);
    glVertex3f(-1, 1, 1);

    glColor3f(1,0,0);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1,  1, -1);
    glVertex3f(1, -1, -1);

    glColor3f(0,0,1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1,  1, 1);
    glVertex3f(-1,  1, -1);

    glColor3f(0,0,1);
    glVertex3f(1, -1, -1);
    glVertex3f(1,  1, -1);
    glVertex3f(1,  1, 1);
    glVertex3f(1, -1, 1);

    glColor3f(0,1,0);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1,  1, 1);
    glVertex3f(1, 1, -1);

    glColor3f(0,1,1);
    glVertex3f(-1, -1, -1);
    glVertex3f(1,  -1, -1);
    glVertex3f(1,  -1, 1);
    glVertex3f(-1, -1, 1);

    glEnd();

}
float angle16=0;
float tx=0, ty=0;
float sx=1, sy=1;
float angle17=0;
float tx1 =0;
float thox=0;
bool thanosVisible= true;
bool thorVisible = true;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-30,30,-30,30);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);

    //blue sky
    glColor3f(0.53,0.80,0.92);
    glBegin(GL_QUADS);

    glVertex2f(-30,10);
    glVertex2f(-30,30);
    glVertex2f(30,30);
    glVertex2f(30,10);
    glEnd();

    //red sun
    glColor3f(1,0,0);
    float cX= 20;
    float cY=24;
    float r=4;
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
    {
        float angle= i*3.1416/180;
        float x=cX+r*cos(angle);
        float y=cY+r*sin(angle);
        glVertex2f(x,y);
    }
    glEnd();





    glColor3f(0,0.50,0);
    glBegin(GL_TRIANGLES);

    glVertex2f(-30,10);
    glVertex2f(-25,20);
    glVertex2f(-18,10);
    glEnd();

    glColor3f(0,0.39,0);
    glBegin(GL_POLYGON);
    glVertex2f(-18.7,11);
    glVertex2f(-13,18);
    glVertex2f(-6.1,11);
    glVertex2f(-7,10);
    glVertex2f(-18,10);
    glVertex2f(-18.7,11);
    glEnd();

    glColor3f(0,0.39,0);
    glBegin(GL_TRIANGLES);

    glVertex2f(-7,10);
    glVertex2f(0,18);
    glVertex2f(5,10);
    glEnd();

    glColor3f(0,0.55,0);
    glBegin(GL_POLYGON);

    glVertex2f(4.4,11);
    glVertex2f(7,14);
    glVertex2f(10,10);
    glVertex2f(5,10);
    glVertex2f(4.4,11);
    glEnd();

    glColor3f(0,0.39,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(9,10);
    glVertex2f(16,15);
    glVertex2f(22,10);
    glEnd();

    glColor3f(0,0.50,0);
    glBegin(GL_TRIANGLES);

    glVertex2f(20.8,10);
    glVertex2f(25,16);
    glVertex2f(30,10);
    glVertex2f(22,10);
    glEnd();

    glColor3f(1,1,1);
    display1(20, 16, 20, 20);
    glEnd();

    glColor3f(1,1,1);
    glLineWidth(3);
    glBegin(GL_LINES);

    glVertex2f(15,18);
    glVertex2f(17,20.0);

    glEnd();

    glColor3f(1,1,1);
    glLineWidth(3);
    glBegin(GL_LINES);

    glVertex2f(25,18);
    glVertex2f(23,20);

    glEnd();
    glColor3f(1,1,1);
    glLineWidth(3);
    glBegin(GL_LINES);

    glVertex2f(16.5,27);
    glVertex2f(14,28.5);

    glEnd();

    glColor3f(1,1,1);
    glLineWidth(3);
    glBegin(GL_LINES);

    glVertex2f(23.5,27);
    glVertex2f(26,28.5);

    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-18.0,17.5);
    glVertex2f(-19.0,18.5);
    glVertex2f(-18.5,18.5);
    glVertex2f(-18.0,18.0);
    glVertex2f(-17.5,18.5);
    glVertex2f(-17.0,18.5);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-8,16);
    glVertex2f(-9,17);
    glVertex2f(-8.5,17);
    glVertex2f(-8,16.5);
    glVertex2f(-7.5,17);
    glVertex2f(-7,17);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-3,18.5);
    glVertex2f(-4,19.5);
    glVertex2f(-3.5,19.5);
    glVertex2f(-3,19);
    glVertex2f(-2.5,19.5);
    glVertex2f(-2,19.5);
    glEnd();

    glColor3f(1,1,1);
    float cX1= -21;
    float cY1=26;
    float r1=2;
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
    {
        float angle1= i*3.1416/180;
        float x1=cX1+r1*cos(angle1);
        float y1=cY1+r1*sin(angle1);
        glVertex2f(x1,y1);
    }
    glEnd();

    glColor3f(1,1,1);
    float cX2= -18;
    float cY2=25;
    float r2=2;
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
    {
        float angle2= i*3.1416/180;
        float x2=cX2+r2*cos(angle2);
        float y2=cY2+r2*sin(angle2);
        glVertex2f(x2,y2);
    }
    glEnd();
    glColor3f(1,1,1);
    float cX3= -24;
    float cY3=25;
    float r3=2;
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
    {
        float angle3= i*3.1416/180;
        float x3=cX3+r3*cos(angle3);
        float y3=cY3+r3*sin(angle3);
        glVertex2f(x3,y3);
    }
    glEnd();
    glColor3f(1,1,1);
    float cX4= -21;
    float cY4=24;
    float r4=2;
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
    {
        float angle4= i*3.1416/180;
        float x4=cX4+r4*cos(angle4);
        float y4=cY4+r4*sin(angle4);
        glVertex2f(x4,y4);
    }
    glEnd();

    glColor3f(1,1,1);
    float cX5= -2;
    float cY5=25;
    float r5=2;
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
    {
        float angle5= i*3.1416/180;
        float x5=cX5+r5*cos(angle5);
        float y5=cY5+r5*sin(angle5);
        glVertex2f(x5,y5);
    }
    glEnd();

    glColor3f(1,1,1);
    float cX6= -5;
    float cY6=24;
    float r6=2;
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
    {
        float angle6= i*3.1416/180;
        float x6=cX6+r6*cos(angle6);
        float y6=cY6+r6*sin(angle6);
        glVertex2f(x6,y6);
    }
    glEnd();

    glColor3f(1,1,1);
    float cX7= 1;
    float cY7=24;
    float r7=2;
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
    {
        float angle7= i*3.1416/180;
        float x7=cX7+r7*cos(angle7);
        float y7=cY7+r7*sin(angle7);
        glVertex2f(x7,y7);
    }
    glEnd();

    glColor3f(1,1,1);
    float cX8= -2;
    float cY8=23;
    float r8=2;
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
    {
        float angle8= i*3.1416/180;
        float x8=cX8+r8*cos(angle8);
        float y8=cY8+r8*sin(angle8);
        glVertex2f(x8,y8);
    }
    glEnd();
    glColor3f(0.50,0,0);
    glBegin(GL_QUADS);

    glVertex2f(-30,7);
    glVertex2f(-30,10);
    glVertex2f(-26,10);
    glVertex2f(-26,7);
    glEnd();
    glColor3f(0.64,0.16,0.16);
    glBegin(GL_QUADS);

    glVertex2f(-26,7);
    glVertex2f(-26,10);
    glVertex2f(-22,10);
    glVertex2f(-22,7);
    glEnd();

    glColor3f(0.80,0.36,0.36);
    glBegin(GL_QUADS);

    glVertex2f(-22,7);
    glVertex2f(-22,10);
    glVertex2f(-18,10);
    glVertex2f(-18,7);
    glEnd();

    glColor3f(0.50,0,0);
    glBegin(GL_QUADS);

    glVertex2f(-18,7);
    glVertex2f(-18,10);
    glVertex2f(-14,10);
    glVertex2f(-14,7);
    glEnd();

    glColor3f(0.64,0.16,0.16);
    glBegin(GL_POLYGON);

    glVertex2f(-14,7);
    glVertex2f(-14,10);
    glVertex2f(-10,10);
    glVertex2f(-10,6);
    glVertex2f(-13,6);
    glVertex2f(-12,7);
    glEnd();

    glColor3f(0.80,0.36,0.36);
    glBegin(GL_QUADS);

    glVertex2f(-10,6);
    glVertex2f(-10,10);
    glVertex2f(-6,10);
    glVertex2f(-6,6);
    glEnd();

    glColor3f(0.50,0,0);
    glBegin(GL_QUADS);

    glVertex2f(-6,6);
    glVertex2f(-6,10);
    glVertex2f(-2,10);
    glVertex2f(-2,6);
    glEnd();

    glColor3f(0.64,0.16,0.16);
    glBegin(GL_QUADS);

    glVertex2f(-2,6);
    glVertex2f(-2,10);
    glVertex2f(2,10);
    glVertex2f(2,6);
    glEnd();

    glColor3f(0.80,0.36,0.36);
    glBegin(GL_QUADS);

    glVertex2f(2,6);
    glVertex2f(2,10);
    glVertex2f(6,10);
    glVertex2f(6,6);
    glEnd();

    glColor3f(0.50,0,0);
    glBegin(GL_QUADS);

    glVertex2f(6,6);
    glVertex2f(6,10);
    glVertex2f(10,10);
    glVertex2f(10,6);
    glEnd();

    glColor3f(0.64,0.16,0.16);
    glBegin(GL_POLYGON);

    glVertex2f(10,7);
    glVertex2f(10,10);
    glVertex2f(14,10);
    glVertex2f(14,7);
    glVertex2f(12,7);
    glVertex2f(13,6);
    glVertex2f(10,6);
    glEnd();

    glColor3f(0.80,0.36,0.36);
    glBegin(GL_QUADS);

    glVertex2f(14,7);
    glVertex2f(14,10);
    glVertex2f(18,10);
    glVertex2f(18,7);
    glEnd();

    glColor3f(0.50,0,0);
    glBegin(GL_QUADS);

    glVertex2f(18,7);
    glVertex2f(18,10);
    glVertex2f(22,10);
    glVertex2f(22,7);
    glEnd();

    glColor3f(0.64,0.16,0.16);
    glBegin(GL_QUADS);

    glVertex2f(22,7);
    glVertex2f(22,10);
    glVertex2f(26,10);
    glVertex2f(26,7);
    glEnd();

    glColor3f(0.80,0.36,0.36);
    glBegin(GL_QUADS);

    glVertex2f(26,7);
    glVertex2f(26,10);
    glVertex2f(30,10);
    glVertex2f(30,7);
    glEnd();

    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);

    glVertex2f(13,6);
    glVertex2f(12,7);
    glVertex2f(30,7);
    glVertex2f(30,6);
    glEnd();

    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);

    glVertex2f(-13,6);
    glVertex2f(-12,7);
    glVertex2f(-30,7);
    glVertex2f(-30,6);
    glEnd();

    glColor3f(0.80,0.36,0.36);
    glBegin(GL_QUADS);

    glVertex2f(-6,0);
    glVertex2f(-6,6);
    glVertex2f(-3,6);
    glVertex2f(-3,0);
    glEnd();

    glColor3f(0.50,0,0);
    glBegin(GL_QUADS);

    glVertex2f(-3,0);
    glVertex2f(-3,1);
    glVertex2f(3,1);
    glVertex2f(3,0);
    glEnd();

    glColor3f(0.64,0.16,0.16);
    glBegin(GL_QUADS);

    glVertex2f(3,0);
    glVertex2f(3,6);
    glVertex2f(6,6);
    glVertex2f(6,0);
    glEnd();

    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);

    glVertex2f(-30,-20);
    glVertex2f(-30,-18);
    glVertex2f(-18,-18);
    glVertex2f(-18,-20);
    glEnd();

    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);

    glVertex2f(-18,-20);
    glVertex2f(-18,-18);
    glVertex2f(-12.8,-18);
    glVertex2f(-11.8,-20);
    glEnd();

    glColor3f(0.50,0,0);
    glBegin(GL_QUADS);

    glVertex2f(-30,-24);
    glVertex2f(-30,-20);
    glVertex2f(-18,-20);
    glVertex2f(-18,-24);
    glEnd();

    glColor3f(0.64,0.16,0.16);
    glBegin(GL_QUADS);

    glVertex2f(-18,-24);
    glVertex2f(-18,-20);
    glVertex2f(-9,-20);
    glVertex2f(-9,-24);
    glEnd();

    glColor3f(0.80,0.36,0.36);
    glBegin(GL_QUADS);

    glVertex2f(-9,-24);
    glVertex2f(-9,-20);
    glVertex2f(0,-20);
    glVertex2f(0,-24);
    glEnd();

    glColor3f(0.50,0,0);
    glBegin(GL_QUADS);

    glVertex2f(0,-20);
    glVertex2f(8,-20);
    glVertex2f(8,-24);
    glVertex2f(0,-24);
    glEnd();

    glColor3f(0.64,0.16,0.16);
    glBegin(GL_QUADS);

    glVertex2f(8,-24);
    glVertex2f(18,-24);
    glVertex2f(18,-20);
    glVertex2f(8,-20);
    glEnd();

    glColor3f(0.80,0.36,0.36);
    glBegin(GL_QUADS);

    glVertex2f(30,-24);
    glVertex2f(30,-20);
    glVertex2f(18,-20);
    glVertex2f(18,-24);
    glEnd();

    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);

    glVertex2f(30,-18);
    glVertex2f(30,-20);
    glVertex2f(18,-20);
    glVertex2f(18,-18);
    glEnd();

    glColor3f(0.54,0,0);
    glBegin(GL_QUADS);

    glVertex2f(12,-20);
    glVertex2f(13,-18);
    glVertex2f(18,-18);
    glVertex2f(18,-20);
    glEnd();

    glColor3f(0.64,0.16,0.16);
    glBegin(GL_QUADS);

    glVertex2f(-30,-30);
    glVertex2f(-30,-24);
    glVertex2f(-26,-24);
    glVertex2f(-26,-30);
    glEnd();

    glColor3f(0.80,0.36,0.36);
    glBegin(GL_QUADS);

    glVertex2f(-18,-30);
    glVertex2f(-18,-24);
    glVertex2f(-14,-24);
    glVertex2f(-14,-30);
    glEnd();

    glColor3f(0.50,0,0);
    glBegin(GL_QUADS);

    glVertex2f(-14,-30);
    glVertex2f(-14,-24);
    glVertex2f(-6,-24);
    glVertex2f(-6,-30);
    glEnd();

    glColor3f(0.64,0.16,0.16);
    glBegin(GL_QUADS);

    glVertex2f(-6,-30);
    glVertex2f(-6,-24);
    glVertex2f(2,-24);
    glVertex2f(2,-30);
    glEnd();

    glColor3f(0.80,0.36,0.36);
    glBegin(GL_QUADS);

    glVertex2f(2,-30);
    glVertex2f(2,-24);
    glVertex2f(10,-24);
    glVertex2f(10,-30);
    glEnd();

    glColor3f(0.50,0,0);
    glBegin(GL_QUADS);

    glVertex2f(10,-30);
    glVertex2f(10,-24);
    glVertex2f(18,-24);
    glVertex2f(18,-30);
    glEnd();

    glColor3f(0.64,0.16,0.16);
    glBegin(GL_QUADS);

    glVertex2f(18,-30);
    glVertex2f(18,-24);
    glVertex2f(22,-24);
    glVertex2f(22,-30);
    glEnd();

    glColor3f(0.50,0,0);
    glBegin(GL_QUADS);

    glVertex2f(26,-30);
    glVertex2f(26,-24);
    glVertex2f(30,-24);
    glVertex2f(30,-30);
    glEnd();

    glColor3f(0.86,0.07,0.23);
    glBegin(GL_QUADS);

    glVertex2f(-3,-20);
    glVertex2f(-3,-16);
    glVertex2f(3,-16);
    glVertex2f(3,-20);
    glEnd();

    glColor3f(0.66,0.66,0.66);
    glBegin(GL_QUADS);

    glVertex2f(-1,-20);
    glVertex2f(-1,-17);
    glVertex2f(1,-17);
    glVertex2f(1,-20);
    glEnd();


    glColor3f(0,0,0);
    float cX9= 0;
    float cY9=-18;
    float r9=0.7;
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
    {
        float angle9= i*3.1416/180;
        float x9=cX9+r9*cos(angle9);
        float y9=cY9+r9*sin(angle9);
        glVertex2f(x9,y9);
    }
    glEnd();

    glColor3f(1,1,1);
    float cX10= 0;
    float cY10=-18;
    float r10=0.5;
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
    {
        float angle10= i*3.1416/180;
        float x10=cX10+r10*cos(angle10);
        float y10=cY10+r10*sin(angle10);
        glVertex2f(x10,y10);
    }
    glEnd();

    glColor3f(0.66,0.66,0.66);
    float cX11= 0;
    float cY11=-15.9;
    float r11=3;
    glBegin(GL_POLYGON);
    for(int i=0; i<180; i++)
    {
        float angle11= i*3.1416/180;
        float x11=cX11+r11*cos(angle11);
        float y11=cY11+r11*sin(angle11);
        glVertex2f(x11,y11);
    }
    glEnd();

    glColor3f(0.50,0,0);
    glBegin(GL_TRIANGLES);

    glVertex2f(-6,-20);
    glVertex2f(-3,-20);
    glVertex2f(-3,-16);
    glEnd();

    glColor3f(0.50,0,0);
    glBegin(GL_TRIANGLES);

    glVertex2f(6,-20);
    glVertex2f(3,-16);
    glVertex2f(3,-20);
    glEnd();

    if(thorVisible)
    {

    glLoadIdentity();
    glTranslatef(thox,0,0);

    glColor3f(1,0.89,0.76);
    float cX12= -24.5;
    float cY12=-9.56;
    float r12=1.6;
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
    {
        float angle12= i*3.1416/180;
        float x12=cX12+r12*cos(angle12);
        float y12=cY12+r12*sin(angle12);
        glVertex2f(x12,y12);
    }
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_QUADS);

    glVertex2f(-25.4,-9);
    glVertex2f(-24.6,-9.4);
    glVertex2f(-24.6,-9.8);
    glVertex2f(-25.4,-9.8);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_QUADS);

    glVertex2f(-24.2,-9.8);
    glVertex2f(-24.2,-9.4);
    glVertex2f(-23.4,-9);
    glVertex2f(-23.4,-9.8);
    glEnd();

    glColor3f(0.41,0.41,0.41);
    glBegin(GL_QUADS);

    glVertex2f(-26.5,-11.1);
    glVertex2f(-26.5,-15);
    glVertex2f(-22.5,-15);
    glVertex2f(-22.5,-11.1);
    glEnd();

    glColor3f(1,0.89,0.76);
    glBegin(GL_POLYGON);

    glVertex2f(-26,-11.5);
    glVertex2f(-24.5,-13);
    glVertex2f(-23.5,-12);
    glVertex2f(-21.3,-12);
    glVertex2f(-21.3,-11.2);
    glVertex2f(-22,-11.2);
    glVertex2f(-22,-11.5);
    glVertex2f(-26,-11.5);
    glEnd();

    glLoadIdentity();
    glTranslatef(thox, 0, 0);
    glTranslatef(tx, ty, 0);
    glTranslatef(-21.8,-11,0);
    glRotatef(angle17,0,0,1);
    glScalef(sx,sy,1);
    glTranslatef(21.8,11,0);
    //Hammer head
    glColor3f(0.60,0.60,0.60);
    glBegin(GL_QUADS);

    glVertex2f(-22.8,-9.4);
    glVertex2f(-20.8,-9.4);
    glVertex2f(-20.8,-10.6);
    glVertex2f(-22.8,-10.6);
    glEnd();

    //hammer handle
    glColor3f(0.35, 0.25, 0.15);
    glBegin(GL_QUADS);

    glVertex2f(-22.0,-10.6);
    glVertex2f(-21.6,-10.6);
    glVertex2f(-21.6,-12.5);
    glVertex2f(-22.0,-12.5);
    glEnd();

    glLoadIdentity();
    glTranslatef(thox, 0, 0);

    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-29,-13);
    glVertex2f(-26.5,-11.1);
    glVertex2f(-26.5,-12);
    glVertex2f(-29,-13.5);
    glEnd();

    glColor3f(0.43,0.50,0.56);
    glBegin(GL_QUADS);
    glVertex2f(-26.5,-15.0);
    glVertex2f(-25.0,-15.0);
    glVertex2f(-25.0,-18.0);
    glVertex2f(-27.5,-18.0);

    glEnd();

    glColor3f(0.43,0.50,0.56);
    glBegin(GL_QUADS);

    glVertex2f(-24,-15);
    glVertex2f(-24,-18);
    glVertex2f(-21.5,-18);
    glVertex2f(-22.5,-15);
    glEnd();

    }


    //new enemey Thanos

    if(thanosVisible)
    {

    glLoadIdentity();
    glColor3f(0.48,0.40,0.93);
    float cX13= 24.5;
    float cY13=-9.56;
    float r13=1.7;
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++)
    {
        float angle13= i*3.1416/180;
        float x13=cX13+r13*cos(angle13);
        float y13=cY13+r13*sin(angle13);
        glVertex2f(x13,y13);
    }
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_QUADS);

    glVertex2f(23.4,-8.8);
    glVertex2f(23.4,-9.6);
    glVertex2f(24.3,-9.6);
    glVertex2f(24.3,-9.2);
    glEnd();


    glColor3f(1,0,0);
    glBegin(GL_QUADS);

    glVertex2f(25.6,-8.8);
    glVertex2f(25.6,-9.6);
    glVertex2f(24.7,-9.6);
    glVertex2f(24.7,-9.2);
    glEnd();

    glColor3f(1,0.84,0);
    glBegin(GL_QUADS);

    glVertex2f(22,-15);
    glVertex2f(22,-11.1);
    glVertex2f(27,-11.1);
    glVertex2f(27,-15);
    glEnd();

    glColor3f(0.48,0.40,0.93);
    glBegin(GL_QUADS);

    glVertex2f(22,-11.2);
    glVertex2f(20.5,-11.2);
    glVertex2f(20.5,-12.5);
    glVertex2f(22,-12.5);
    glEnd();

    glLoadIdentity();
    glTranslatef(tx1,0,0);
    glScalef(sx,sy,1);
    glColor3f(1,0.84,0);
    glBegin(GL_POLYGON);

    //thanoshand
    glVertex2f(20.5,-11);
    glVertex2f(17,-11);
    glVertex2f(17,-13.2);
    glVertex2f(18.4,-13.2);
    glVertex2f(18.4,-12.7);
    glVertex2f(20.5,-12.7);
    glEnd();
    glLoadIdentity();


    glColor3f(0.48,0.40,0.93);
    glBegin(GL_QUADS);

    glVertex2f(22,-15);
    glVertex2f(20.5,-18);
    glVertex2f(24,-18);
    glVertex2f(24,-15);
    glEnd();

    glColor3f(0.48,0.40,0.93);
    glBegin(GL_QUADS);

    glVertex2f(27,-15);
    glVertex2f(28.5,-18);
    glVertex2f(25,-18);
    glVertex2f(25,-15);
    glEnd();
    }

    glLoadIdentity();
    glColor3f(1,1,1);
    //sun ray
    display1(20,16,20,20);
    display2(12,24,16,24);
    display3(20,28,20,30);
    display4(24,24,28,24);


    //rotating 3d cube
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,1,0.1,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0,3,-55);
    glRotatef(angle16,1,1,0.5);
    display5();

    glutSwapBuffers();



































    glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'w':ty += 0.5;
         break;
        case 's':ty -= 0.5;
         break;
        case 'a':tx -= 0.5; angle17 -= 5;
         break;
        case 'd':tx += 0.5; angle17 += 5;
         break;
        case '+':sx += 0.1; sy += 0.1;
         break;
        case '-':sx -= 0.1; sy -= 0.1;
         break;
        case 'r':angle17 += 5;
         break;
        case 'R':angle17 -= 5; break;
        case 't':tx1 -= 0.5; break;
        case 'y':tx1 += 0.5; break;
        case 'i':thox += 0.5; break;
        case 'u':thox -= 0.5; break;
        case 'b':
        case 'B':
            thorVisible = true;
            thanosVisible = true;
            tx=0; ty=0;
            thox=0;
            sx=1; sy=1;
            break;
        case 'x': exit(0);
    }
    if(thanosVisible)
    {
        float z= -21.8;
        float translate = z+tx;
        float hammerx= translate* sx;
        if(hammerx >= 20)
        {
            thanosVisible =false;

        }

    }
    if(thorVisible)
    {
        float THandx =17+tx1;
        if(THandx <= -20)
        {
            thorVisible=false;
        }
        if(thox >= 45)
        {
            thanosVisible=false;
        }
    }
    glutPostRedisplay();
}
void update(int value)
{
    //rotate cube
    angle16+= 1.5;
    if(angle16 > 360)
    {
        angle16-= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(16,update,0);

}
void init()
{
    glClearColor(0, 0, 0, 0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-30, 30, -30, 30, -30, 30);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(1980, 1080);
    glutCreateWindow("Gaming Arena- 2D/3D Scene");

    init();

    //glutDisplayFunc(display_F1);
    //glutKeyboardFunc(keyboard_F1);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    //glutTimerFunc(0, updateEnemy_F1, 0);
    //glutTimerFunc(16, update_F1, 0);
    //glutTimerFunc(0, updatePower_F1, 0);


    glutTimerFunc(16, update, 0);

    glutMainLoop();

    return 0;
}
