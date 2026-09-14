#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;




//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$_GLOBAL VARIABLES_$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
float playerX_f2 = -10.7f;
float playerY_f2 = -13.0f;

float bulletX_f2 = -20.0f;
float bulletY_f2 = -8.8f;

bool bulletActive_f2 = false;

bool enemyAlive_f2 = true;
bool enemyFalling_f2 = false;

float enemyFallAngle_f2 = 0.0f;

float gemRotation_f2 = 0.0f;




//$$$$$$$$$$$$$$$$$$$$$$$$$$$$_OBJECT FUNCTIONS_$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void LineDraw_f2(float x1, float y1, float z1, float x2, float y2, float z2){
    glLineWidth(3.5f);
    glBegin(GL_LINES);
    glVertex3f(x1,y1,z1);
    glVertex3f(x2,y2,z2);
    glEnd();
}


void TriangleDraw_f2(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
    glEnd();
}


void QuadDraw_f2(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4) {
    glBegin(GL_QUADS);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
}


void CircleDraw_f2(float cX,float cY,float cZ,float cR,int circleType){
    float start=0;
    float cond=360;

    if(circleType==1){
            start=0; cond=180;
    }else if(circleType==2){
            start=180; cond=360;
    }

    glBegin(GL_POLYGON);
    for(int i=(int)start;i<=(int)cond;i++){
        float a=i*3.14159265f/180.0f;
        glVertex3f(cX+cR*cos(a),cY+cR*sin(a),cZ);
    }
    glEnd();
}


void LINE_DDA_f2(float x1,float y1,float x2,float y2, int pointSize=5){


    float dx= x2-x1;
    float dy= y2-y1;
    float m =dy/dx;
    float x = x1;
    float y = y1;

    glPointSize(pointSize);

    glBegin(GL_POINTS);

    if (fabs(m) < 1)
    {
        while(x <= x2 && y <= y2)
        {
            glVertex2i(x, y);
            x=x+ 1;
            y = y+m;
        }
    }
    else
    {
        while(y<= y2)
        {
            glVertex2i(x, y);
            y=y +1;
            x =x +(1/m);
        }
    }

    glEnd();

    glFlush();
}


void midPointLine_f2(int x1,int y1,int x2,int y2){
    int dx=abs(x2-x1),dy=abs(y2-y1),sx=(x1<x2)?1:-1,sy=(y1<y2)?1:-1,err=dx-dy;
    glBegin(GL_POINTS);
    while(true){
        glVertex2i(x1,y1);
        if(x1==x2 && y1==y2) break;
        int e2=2*err;
        if(e2>-dy){err-=dy;x1+=sx;}
        if(e2<dx){err+=dx;y1+=sy;}
    }
    glEnd();
}




//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$_SCENE FUNCTIONS_$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void drawSky_f2(){

    //$$$SKY$$$
    glColor3f(0.35f,0.72f,0.92f);
    QuadDraw_f2(-30,12.22,29.83,2.80,30,30,-30,30);


    //$$$$CLOUD$$$$
    glColor3f(0.95f,0.98f,1.0f);
        CircleDraw_f2(-2.8f, 24.5f, 0, 2.0f, 3);
        CircleDraw_f2( 0.2f, 25.2f, 0, 2.6f, 3);
        CircleDraw_f2( 3.2f, 24.5f, 0, 2.0f, 3);
        CircleDraw_f2( 0.2f, 23.4f, 0, 2.2f, 3);

}



void drawMountains_f2(){

    // $$$$$$$$$$$$$$$$$ PAHAR $$$$$$$$$$$$$$$$$$$$4
    glColor3f(0.25f,0.30f,0.34f);

    TriangleDraw_f2(-30,9,-23,22,-16,9);
    TriangleDraw_f2(-23,9,-15,26,-7,9);
    TriangleDraw_f2(-15,9,-8,19,0,9);

    TriangleDraw_f2(0,9,7,22,14,9);
    TriangleDraw_f2(7,9,15,28,23,9);
    TriangleDraw_f2(14,9,20,21,26,9);



    //$$$$$$$$ VITORER PAHAR TRIANAGE $$$$$$$$$$$$$$
    glColor3f(0.48f,0.50f,0.45f);

    TriangleDraw_f2(-29.8f,9,-23,22,-20.0f,9);
    TriangleDraw_f2(-22.8f,9,-15,26,-11.5f,9);
    TriangleDraw_f2(-14.8f,9,-8,19,-4.5f,9);

    TriangleDraw_f2(0.2f,9,7,22,10.0f,9);
    TriangleDraw_f2(7.2f,9,15,28,18.5f,9);
    TriangleDraw_f2(14.2f,9,20,21,23.0f,9);


    // $$$$$$$$$$$$$$$$$$ RIGHT VOLCANO $$$$$$$$$$$$$$$$4
    glColor3f(0.22f,0.18f,0.18f);
    TriangleDraw_f2(14,9,21,27,29,9);



    // $$$$$$$$$$$$$$$$$$44  LAVA MUKH $$$$$$$$$$$$$$$$$$
    glColor3f(0.12f,0.08f,0.08f);
    CircleDraw_f2(21.0f,26.2f,0,1.0f,3);

    glColor3f(1.0f,0.35f,0.02f);
    CircleDraw_f2(21.0f, 26.2f, 0.05f,0.6f,3);

    // $$$$$$$$$$$$$$$$$ COMING OUT LAVA $$$$$$$$$$$$$$4
    glColor3f(0.90f,0.12f,0.03f);

    QuadDraw_f2(
        21.35f,25.9f,
        22.25f,25.25f,
        28.45f,10.0f,
        27.35f,9.55f
    );

    //$$$$$$$$$$ VITORER LAVA $$$$$$$$$$$$$$
    glColor3f(1.0f,0.52f,0.03f);

    QuadDraw_f2(
        21.55f,25.65f,
        21.95f,25.35f,
        28.0f,10.2f,
        27.55f,10.0f
    );

    glColor3f(0.90f,0.12f,0.03f);
    CircleDraw_f2(28.1f,9.4f,0,0.65f,3);
}



void drawGroundAndRoad_f2(){
    // $$$$$$$ GREEN AREA $$$$$$$$$$
    glColor3f(0.20f,0.48f,0.33f);
    QuadDraw_f2(-30,-30,30,-30,30,9,-30,9);


    // $$$$$$$ DDA $$$$$$$$$$$$
    glColor3f(0.28f,0.58f,0.25f);
    LINE_DDA_f2(-30, -10, 30, -10, 30);

    //$$$$$$$ mid point $$$$$$$$$
    glColor3f(0.28f,0.58f,0.3f);
    glPointSize(25.0f);
    midPointLine_f2(-30, -12.22, 30, -12.22);



    //$$$$$$$$$$ MAIN ROAD $$$$$$$$$$$
    glColor3f(0.23f,0.23f,0.24f);
    glBegin(GL_POLYGON);
    glVertex2f(-30,-17);
    glVertex2f(-20,-14.8f);
    glVertex2f(-10,-17);
    glVertex2f(0,-14.8f);
    glVertex2f(10,-17);
    glVertex2f(20,-14.7f);
    glVertex2f(30,-16.2f);
    glVertex2f(30,-21.0f);
    glVertex2f(20,-19.0f);
    glVertex2f(10,-21.5f);
    glVertex2f(0,-19.2f);
    glVertex2f(-10,-21.5f);
    glVertex2f(-20,-19.0f);
    glVertex2f(-30,-21.5f);
    glEnd();





    glColor3f(0.88f,0.78f,0.34f);
    glLineWidth(3.0f);

    //$$$$$$$$$VITORER DAG$$$$$$$$$$$$$$$
    glBegin(GL_LINES);

    glVertex2f(-30,-19.2f);
    glVertex2f(-20,-17.0f);

    glVertex2f(-20,-17.0f);
    glVertex2f(-10,-19.2f);

    glVertex2f(-10,-19.2f);
    glVertex2f(0,-17.0f);

    glVertex2f(0,-17.0f);
    glVertex2f(10,-19.2f);

    glVertex2f(10,-19.2f);
    glVertex2f(20,-16.8f);

    glVertex2f(20,-16.8f);
    glVertex2f(30,-18.6f);


    glEnd();
}



void drawHouse_f2(float x,float y,float s){

    // $$$$$$$$$$$ HOUSE BODY $$$$$$$$$$$$$$
    glColor3f(0.82f,0.68f,0.43f);

    QuadDraw_f2(
        x-6.0f*s,y,
        x+6.0f*s,y,
        x+6.0f*s,y+7.0f*s,
        x-6.0f*s,y+7.0f*s
    );

    // $$$$$$$$$$$$$$$$$$$ ROOF $$$$$$$$$$$$$$$$$$$$
    glColor3f(0.45f,0.16f,0.10f);

    TriangleDraw_f2(
        x-7.5f*s,y+7.0f*s,
        x,y+13.0f*s,
        x+7.5f*s,y+7.0f*s
    );

    // $$$$$$$$$$$$$$$$$ LEFT WINDOW $$$$$$$$$$$$$$$$
    glColor3f(0.20f,0.60f,0.82f);

    QuadDraw_f2(
        x-4.2f*s,y+2.0f*s,
        x-1.8f*s,y+2.0f*s,
        x-1.8f*s,y+4.4f*s,
        x-4.2f*s,y+4.4f*s
    );

    //$$$ Left window frame $$$
    glColor3f(0.15f,0.15f,0.15f);
    glLineWidth(2.0f);

    glBegin(GL_LINES);
        glVertex2f(x-3.0f*s,y+2.0f*s);
        glVertex2f(x-3.0f*s,y+4.4f*s);
        glVertex2f(x-4.2f*s,y+3.2f*s);
        glVertex2f(x-1.8f*s,y+3.2f*s);
    glEnd();

    // $$$$$$$$$$$$$$$$$ RIGHT WINDOW $$$$$$$$$$$$$$$
    glColor3f(0.20f,0.60f,0.82f);

    QuadDraw_f2(
        x+1.8f*s,y+2.0f*s,
        x+4.2f*s,y+2.0f*s,
        x+4.2f*s,y+4.4f*s,
        x+1.8f*s,y+4.4f*s
    );

    //$$$ Right window frame $$$
    glColor3f(0.15f,0.15f,0.15f);

    glBegin(GL_LINES);
        glVertex2f(x+3.0f*s,y+2.0f*s);
        glVertex2f(x+3.0f*s,y+4.4f*s);
        glVertex2f(x+1.8f*s,y+3.2f*s);
        glVertex2f(x+4.2f*s,y+3.2f*s);
    glEnd();

    // $$$$$$$$$$$$$$ DOOR $$$$$$$$$$$$$$$$$$
    glColor3f(0.25f,0.13f,0.07f);

    QuadDraw_f2(
        x-1.3f*s,y,
        x+1.3f*s,y,
        x+1.3f*s,y+4.8f*s,
        x-1.3f*s,y+4.8f*s
    );

    //$$$ Door knob $$$
    glColor3f(0.95f,0.78f,0.25f);
    CircleDraw_f2(x+0.75f*s,y+2.4f*s,0,0.18f*s,3);

    // $$$$$$$$$$$$$$$ CHIMNEY $$$$$$$$$$$$$
    glColor3f(0.42f,0.20f,0.14f);

    QuadDraw_f2(
        x+2.8f*s,y+10.0f*s,
        x+4.2f*s,y+10.0f*s,
        x+4.2f*s,y+13.0f*s,
        x+2.8f*s,y+13.0f*s
    );
}



void drawTree_f2(float x,float y,float s){
    glColor3f(0.34f,0.18f,0.07f);
    QuadDraw_f2(x-0.55f*s,y,x+0.55f*s,y,x+0.55f*s,y+2.2f*s,x-0.55f*s,y+2.2f*s);

    glColor3f(0.10f,0.42f,0.14f);
    TriangleDraw_f2(x-3.0f*s,y+1.6f*s, x,y+5.6f*s, x+3.0f*s,y+1.6f*s);
    glColor3f(0.09f,0.40f,0.13f);
    TriangleDraw_f2(x-2.3f*s,y+3.3f*s, x,y+7.3f*s, x+2.3f*s,y+3.3f*s);
    glColor3f(0.08f,0.38f,0.12f);
    TriangleDraw_f2(x-1.6f*s,y+5.0f*s, x,y+8.8f*s, x+1.6f*s,y+5.0f*s);
}




void drawPlayer_f2(){

    glTranslatef(playerX_f2, playerY_f2, 0);

    // $$$$$$$$$$$$$$$$$$$$$$$ HEAD $$$$$$$$$$$$$$$$$$$$$$$$
    glColor3f(0.95f, 0.78f, 0.58f);
    CircleDraw_f2(0.0f, 7.2f, 0, 3.2f, 3);


    // $$$$$$$$$$$$$$$$$$ CHUL $$$$$$$$$$$$$$$$$$
    glColor3f(0.06f, 0.07f, 0.09f);
    glBegin(GL_LINES);

    glVertex2f(-3.0f,8.7f);
    glVertex2f(-3.7f,9.7f);

    glVertex2f(-2.5f,9.4f);
    glVertex2f(-3.0f,10.4f);

    glVertex2f(-1.8f,9.9f);
    glVertex2f(-1.9f,11.0f);

    glVertex2f(-0.9f,10.2f);
    glVertex2f(-0.7f,11.2f);

    glVertex2f(0.0f,10.3f);
    glVertex2f(0.6f,11.1f);

    glVertex2f(0.9f,10.2f);
    glVertex2f(1.6f,11.0f);

    glVertex2f(1.8f,9.9f);
    glVertex2f(2.6f,10.5f);

    glVertex2f(2.5f,9.4f);
    glVertex2f(3.4f,9.8f);

    glEnd();

    // $$$$$$$$$$$$$$$$$$$ EYES $$$$$$$$$$$$$$$$$$$
    glColor3f(1.0f,1.0f,1.0f);
    CircleDraw_f2(-1.25f,7.5f,0,0.65f,3);
    CircleDraw_f2(1.25f,7.5f,0,0.65f,3);

    glColor3f(0,0,0);
    CircleDraw_f2(-1.25f,7.5f,0,0.25f,3);
    CircleDraw_f2(1.25f,7.5f,0,0.25f,3);

    // $$$$$$$$$$$$$$$$ NAK $$$$$$$$$$$$$$$$
        glColor3f(0.75f,0.45f,0.30f);
        QuadDraw_f2(-0.25f, 6.4f, 0.25f, 6.4f, 0.25f, 7.5f, -0.25f, 7.5f);

    // $$$$$$$$$$$$$$$ MUKH $$$$$$$$$$$$$$$$
        glColor3f(0.20f,0.05f,0.05f);
        glLineWidth(3.0f);

        glBegin(GL_LINES);

        glVertex2f(-1.0f,5.9f);
        glVertex2f(0.0f,5.5f);

        glVertex2f(0.0f,5.5f);
        glVertex2f(1.0f,5.9f);

        glEnd();

    //$$$$$$$$$$$$$$ BODY $$$$$$$$$$$
        glColor3f(0.08f,0.18f,0.35f);
        QuadDraw_f2(-2.8f,0.0f,2.8f,0.0f,2.8f,5.0f,-2.8f,5.0f);

    // $$$$$$$$$$$$$$ BAM PA $$$$$$$$$$$$$$$
    glColor3f(0.06f,0.10f,0.18f);

    QuadDraw_f2(-2.25f, -4.5f, -0.45f, -4.5f, -0.45f,0.0f, -2.25f,0.0f);
    LineDraw_f2(-2.25f,-4.5f,0.1f,0.3f,-4.5f, 0.1f);

    // $$$$$$$$$$$$$$$ DAN PA $$$$$$$$$$$$$$$$$$$$
    QuadDraw_f2(0.45f,-4.5f, 2.25f,-4.5f,2.25f,0.0f,0.45f,0.0f);
    LineDraw_f2(0.45f,-4.5f,0.1f,3.0f,-4.5f, 0.1f);



    // $$$$$$$$$$$$$$$$ HAT $$$$$$$$$$$$$$$$$$$
    glColor3f(0.95f,0.78f,0.58f);

        //$$$ BAM HAT $$$
        QuadDraw_f2(2.25f,4.15f,  2.25f,3.45f,  5.55f,2.0f,  5.55f,3.1f);






    // $$$$$$$$$$$$$$$$$$$$ GUN $$$$$$$$$$$$$$$$$$$$$$$$$
    glColor3f(0.08f,0.08f,0.09f);
    QuadDraw_f2(3.6f,2.65f, 7.6f,2.65f, 7.6f,3.35f, 3.6f,3.35f);


    //$$$ GUB HANDLE $$$
    QuadDraw_f2(4.05f,1.65f, 5.05f,1.65f, 5.35f,2.75f, 4.35f,2.75f);


        //$$$ DAN HAT $$$
        glColor3f(0.95f,0.78f,0.58f);
        QuadDraw_f2(-2.45f,4.25f, -2.45f,3.55f,  5.0f, 2.0f, 5.0f,3.0f);


    //$$$ GUN DESIGN $$$
    glColor3f(0.30f,0.30f,0.32f);
    QuadDraw_f2(7.4f,2.75f, 9.4f,2.75f, 9.4f,3.25f, 7.4f,3.25f);

    //$$$ GUN MATHA $$$
    glColor3f(0.05f,0.05f,0.05f);
    QuadDraw_f2(9.2f,2.65f, 10.0f,2.65f, 10.0f,3.35f, 9.2f,3.35f);

    glTranslatef(-playerX_f2, -playerY_f2, 0);
}




void drawEnemy_f2(){
    if(!enemyAlive_f2) return;

    float iniPOsitionX= 7.5f;
    float iniPositionY= -16.0f;

    glTranslatef(iniPOsitionX,iniPositionY,0);

    if(enemyFalling_f2)
        glRotatef(enemyFallAngle_f2, 0, 0, 1);


    // $$$$$$$$$$$$$$ ENEMY MATHA $$$$$$$$$$$$$$$$$$$
    glColor3f(0.92f,0.68f,0.50f);
    CircleDraw_f2(0.0f, 7.2f, 0, 3.2f, 3);


    // $$$$$$$$$$$$$$$$$ ENEMY HAIR $$$$$$$$$$$$$$$$$$$$
    glColor3f(0.05f,0.05f,0.06f);

    TriangleDraw_f2(-3.0f,8.5f,-4.0f,9.9f,-2.4f,9.3f);
    TriangleDraw_f2(-2.5f,9.2f,-3.2f,10.7f,-1.9f,9.7f);
    TriangleDraw_f2(-1.8f,9.7f,-2.0f,11.5f,-0.9f,10.0f);
    TriangleDraw_f2(-0.9f,10.0f,-0.7f,11.7f,0.0f,10.1f);

    TriangleDraw_f2(0.0f,10.1f,0.8f,11.6f,0.9f,10.0f);
    TriangleDraw_f2(0.9f,10.0f,1.9f,11.4f,1.8f,9.7f);
    TriangleDraw_f2(1.8f,9.7f,3.0f,10.8f,2.5f,9.2f);
    TriangleDraw_f2(2.5f,9.2f,3.8f,9.9f,3.0f,8.5f);



    // $$$$$$$$$$$$$$$$ EARS $$$$$$$$$$$$$$$
    glColor3f(0.92f,0.68f,0.50f);

    // $$$ Left ear $$$
    TriangleDraw_f2(
        -3.9f,6.9f,
        -3.0f,7.6f,
        -3.0f,6.2f
    );

    //$$$ Right ear  $$$
    TriangleDraw_f2(
        3.9f,6.9f,
        3.0f,7.6f,
        3.0f,6.2f
    );



    // $$$$$$$$$$$$$$$$$$$$$ EYE $$$$$$$$$$$$$$$$$$$$$$
    glColor3f(1.0f,1.0f,1.0f);

    CircleDraw_f2(-1.25f,7.5f,0,0.68f,3);
    CircleDraw_f2(1.25f,7.5f,0,0.68f,3);

    glColor3f(0.08f,0.08f,0.08f);

    CircleDraw_f2(-1.25f,7.5f,0,0.25f,3);
    CircleDraw_f2(1.25f,7.5f,0,0.25f,3);


    // $$$$$$$$$$$$$$$$ NAK $$$$$$$$$$$$$$$$$$
    glColor3f(0.65f,0.35f,0.22f);

    glLineWidth(2.5f);

    glBegin(GL_LINES);
        glVertex2f(0.0f,7.2f);
        glVertex2f(0.0f,6.3f);
    glEnd();




    // $$$$$$$$$$$$$$$$$$$$$ mukh $$$$$$$$$$$$$$$$$$$$$$$
    glColor3f(0.15f,0.02f,0.02f);

    LineDraw_f2(-1.0f,5.95f,0.0f, -0.5f,5.65f,0.0f);
    LineDraw_f2(-0.5f,5.65f,0.0f, 0.0f,5.55f,0.0f);
    LineDraw_f2(0.0f,5.55f,0.0f, 0.5f,5.65f,0.0f);
    LineDraw_f2(0.5f,5.65f,0.0f, 1.0f,5.95f,0.0f);




    // $$$$$$$$$$$$$ BODY $$$$$$$$$$$$$$$
    glColor3f(0.58f,0.10f,0.12f);
    QuadDraw_f2(-2.8f,0.0f, 2.8f,0.0f, 2.8f,5.0f, -2.8f,5.0f);





    // $$$$$$$$$$$$ Bam pa $$$$$$$$$$$$$$$$$$
    glColor3f(0.18f,0.12f,0.12f);
    QuadDraw_f2(-2.25f,-4.5f, -0.45f,-4.5f, -0.45f,0.0f, -2.25f,0.0f);

    // $$$ PAYER PATA $$$
    QuadDraw_f2(-0.45f,-4.5f, -3.0f,-4.5f, -3.0f,-3.8f, -0.45f,-3.8f);



    // $$$$$$$$$$$$$$$$ Dan pa $$$$$$$$$$$$$$$$$$$$$$
    QuadDraw_f2(0.45f,-4.5f, 2.25f,-4.5f, 2.25f,0.0f, 0.45f,0.0f);

    // $$$ PAYER PATA $$$
     QuadDraw_f2(2.25f,-4.5f, 3.0f,-4.5f, 3.0f,-3.8f, 2.25f,-3.8f);





    // $$$$$$$$$$$$$$$ Bam hat $$$$$$$$$$$$$$$$$$
    glColor3f(0.92f,0.68f,0.50f);

    QuadDraw_f2(-2.0f,4.3f, -2.0f,3.5f, -4.0f,3.5f, -4.0f,4.3f );
    TriangleDraw_f2(-4.0f, 3.5f, -3.2f, 3.5f, -4.0f,1.5f);




    // $$$$$$$$$$$$$ dan hat $$$$$$$$$$$$$$
        QuadDraw_f2(2.0f,4.3f, 2.0f,3.5f, 4.0f,3.5f, 4.0f,4.3f);
        TriangleDraw_f2(4.0f,3.5f, 3.2f,3.5f, 4.0f,1.5f);




    // $$$ Rotation undo $$$
    if(enemyFalling_f2)
        glRotatef(-enemyFallAngle_f2,0,0,1);

    glTranslatef(-iniPOsitionX,-iniPositionY,0);
}




void drawGem_f2(){
    glTranslatef(15.0f,10.0f,0);
    glRotatef(gemRotation_f2,0.4f,1.0f,0.3f);
    float sc = 1.0f + 0.15f*sinf(gemRotation_f2*3.14159265f/180.0f);
    glScalef(sc,sc,sc);

    float h=0.8f;

    // $$$ front $$$
    glColor3f(0.85f,0.25f,0.85f);
    glBegin(GL_QUADS);
    glVertex3f(-h,-h, h);
    glVertex3f(h,-h, h);
    glVertex3f(h,h, h);
    glVertex3f(-h,h, h);
    glEnd();

    // $$$ back $$$
    glColor3f(0.55f,0.10f,0.55f);
    glBegin(GL_QUADS);
    glVertex3f(h,-h,-h);
    glVertex3f(-h,-h,-h);
    glVertex3f(-h,h,-h);
    glVertex3f(h,h,-h);
    glEnd();

    // $$$ top $$$
    glColor3f(0.95f,0.55f,0.95f);
    glBegin(GL_QUADS);
    glVertex3f(-h,h, h);
    glVertex3f(h,h, h);
    glVertex3f(h,h,-h);
    glVertex3f(-h,h,-h);
    glEnd();

    //$$$ bottom $$$
    glColor3f(0.45f,0.05f,0.45f);
    glBegin(GL_QUADS);
    glVertex3f(-h,-h,-h);
    glVertex3f(h,-h,-h);
    glVertex3f(h,-h,h);
    glVertex3f(-h,-h,h);
    glEnd();

    //$$$ right $$$
    glColor3f(0.70f,0.18f,0.70f);
    glBegin(GL_QUADS);
    glVertex3f(h,-h, h);
    glVertex3f(h,-h,-h);
    glVertex3f(h,h,-h);
    glVertex3f(h,h, h);
    glEnd();

    //$$$ left $$$
    glColor3f(0.65f,0.15f,0.65f);
    glBegin(GL_QUADS);
    glVertex3f(-h,-h,-h);
    glVertex3f(-h,-h,h);
    glVertex3f(-h,h,h);
    glVertex3f(-h,h,-h);
    glEnd();


    float inv = 1.0f/sc;
    glScalef(inv,inv,inv);
    glRotatef(-gemRotation_f2,0.4f,1.0f,0.3f);
    glTranslatef(-15.0f,-10.0f,0);

}




//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$_DISPLAY FUNCTION_$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void display_f2(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawSky_f2();
    drawMountains_f2();
    drawGroundAndRoad_f2();

    //$$$ BARI-GHOR $$$
    drawHouse_f2(-22,-7.5f,0.9f);
    drawHouse_f2(-8,-6,0.7f);
    drawHouse_f2(3,4, 0.5f);
    drawHouse_f2(24,0, 0.5f);



    //$$$ TREEs $$$
    drawTree_f2(-25.2,1.7f,0.8f);
    drawTree_f2(-2,5.0f,0.4f);
    drawTree_f2(18,-3.5f,0.6f);
    drawTree_f2(-22,-29.0f,0.9f);
    drawTree_f2(12,-27.0f,0.6f);


    drawPlayer_f2();
    drawEnemy_f2();
    drawGem_f2();






    if(bulletActive_f2){

        // $$$$$$$$$$$$$$$$$ bullet $$$$$$$$$$$$$$$$$$$$$
        glColor3f(1.0f,0.85f,0.05f);

        //$$$ bullet body $$$
        QuadDraw_f2(
            bulletX_f2-0.9f, bulletY_f2-0.28f,
            bulletX_f2+0.35f, bulletY_f2-0.28f,
            bulletX_f2+0.35f, bulletY_f2+0.28f,
            bulletX_f2-0.9f, bulletY_f2+0.28f
        );

        //$$$ bulet matha $$$
        glColor3f(1.0f,0.35f,0.02f);

        TriangleDraw_f2(
            bulletX_f2+0.35f, bulletY_f2-0.28f,
            bulletX_f2+0.95f, bulletY_f2,
            bulletX_f2+0.35f, bulletY_f2+0.28f
        );
    }

    glLoadIdentity();
    glutSwapBuffers();
}




//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$_UPDATE FUNCTION_$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void update_f2(int value){
    if(bulletActive_f2){
        bulletX_f2 += 0.75f;


        if(enemyAlive_f2 && !enemyFalling_f2 &&
   bulletX_f2 > 4.0f && bulletX_f2 < 11.5f &&
   bulletY_f2 > -13.5f && bulletY_f2 < -2.0f){
            enemyFalling_f2=true;
            bulletActive_f2=false;
        }

        if(bulletX_f2>31.0f) bulletActive_f2=false;
    }

    if(enemyFalling_f2){
        enemyFallAngle_f2 += 5.0f;
        if(enemyFallAngle_f2 >= 90.0f){
            enemyFallAngle_f2=90.0f;
            enemyAlive_f2=false;
        }
    }

    gemRotation_f2 += 1.2f;
    if(gemRotation_f2 >= 360.0f) gemRotation_f2 -= 360.0f;



    glutPostRedisplay();
    glutTimerFunc(16,update_f2,0);
}




//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$_KEYBOARD FUNCTION_$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void keyboard_f2(unsigned char KIN,int x,int y){
    if(KIN=='w' || KIN=='W') playerY_f2 += 0.8f;
    else if(KIN=='s' || KIN=='S') playerY_f2 -= 0.8f;
    else if(KIN=='a' || KIN=='A') playerX_f2 -= 0.8f;
    else if(KIN=='d' || KIN=='D') playerX_f2 += 0.8f;
    else if(KIN=='f' || KIN=='F'){
        if(!bulletActive_f2 && enemyAlive_f2){
            bulletActive_f2=true;
            bulletX_f2=playerX_f2+10.0f;
            bulletY_f2=playerY_f2+3.0f;
        }
    }
    else if(KIN=='r' || KIN=='R'){
        enemyAlive_f2=true;
        enemyFalling_f2=false;
        enemyFallAngle_f2=0;
        bulletActive_f2=false;
    }
    else if(KIN=='q' || KIN=='Q') exit(0);

    if(playerX_f2<-27) playerX_f2=-27;
    if(playerX_f2>8) playerX_f2=8;
    if(playerY_f2<-13) playerY_f2=-13;
    if(playerY_f2>-3.5) playerY_f2=-3.5;

    glutPostRedisplay();
}




//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$_INSTRUCTION FUNCTION_$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void keyInstruction_f2(){
    cout<<"\n \t FRAME-2 CONTROLS \n\n";
    cout<<"\t W : Move Player Up\n";
    cout<<"\t S : Move Player Down\n";
    cout<<"\t A : Move Player Left\n";
    cout<<"\t D : Move Player Right\n";
    cout<<"\t F : Fire Bullet\n";
    cout<<"\t R : Make Alive Enemy\n";
    cout<<"\t Q : EXIT\n\n\n";
}




//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$_MAIN FUNCTION_$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1920,1080);
    glutCreateWindow("Fancy Gaming Arena");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-30,30,-30,30,-30,30);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glClearColor(0.35f,0.72f,0.92f,1.0f);

    keyInstruction_f2();

    glutDisplayFunc(display_f2);
    glutTimerFunc(16,update_f2,0);
    glutKeyboardFunc(keyboard_f2);

    glutMainLoop();
    return 0;
}
