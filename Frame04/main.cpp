#include <GL/glut.h>
#include <math.h>
float PI = 3.1416;
float playerX = 0.10;
float enemyX = 0.90;
float playerStartX = 0.10;
float enemyStartX = 0.90;
float playerFightX = 0.39;
float enemyFightX = 0.61;
float minFightDistance = 0.22;
bool playerMoving = false;
bool enemyMoving = false;
bool fighting = false;
bool fightStarted = false;
bool flash = false;
bool returningHome = false;
int fightTime = 0;
bool enemyDefeated = false;
float enemyRotation = 0.0f;
int defeatTime = 0;
void circle(float cx, float cy, float r)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 360; i++)
    {
        float angle = i * PI / 180;
        float x = cx + r * cos(angle);
        float y = cy + r * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}
void drawPlayer()
{
    glColor3f(0.96f, 0.78f, 0.62f);
    circle(playerX, 0.445f, 0.035f);
    glColor3f(0.06f, 0.08f, 0.12f);
    circle(playerX, 0.468f, 0.030f);
    glColor3f(0.96f, 0.78f, 0.62f);
    glBegin(GL_QUADS);
        glVertex2f(playerX - 0.010f, 0.405f);
        glVertex2f(playerX + 0.010f, 0.405f);
        glVertex2f(playerX + 0.010f, 0.420f);
        glVertex2f(playerX - 0.010f, 0.420f);
    glEnd();
    glColor3f(0.10f, 0.30f, 0.72f);
    glBegin(GL_QUADS);
        glVertex2f(playerX - 0.032f, 0.300f);
        glVertex2f(playerX + 0.032f, 0.300f);
        glVertex2f(playerX + 0.027f, 0.410f);
        glVertex2f(playerX - 0.027f, 0.410f);
    glEnd();
    glColor3f(0.18f, 0.45f, 0.95f);
    glBegin(GL_QUADS);
        glVertex2f(playerX - 0.021f, 0.325f);
        glVertex2f(playerX + 0.021f, 0.325f);
        glVertex2f(playerX + 0.018f, 0.395f);
        glVertex2f(playerX - 0.018f, 0.395f);
    glEnd();
    glColor3f(0.12f, 0.08f, 0.05f);
    glBegin(GL_QUADS);
        glVertex2f(playerX - 0.033f, 0.300f);
        glVertex2f(playerX + 0.033f, 0.300f);
        glVertex2f(playerX + 0.033f, 0.315f);
        glVertex2f(playerX - 0.033f, 0.315f);
    glEnd();
    glColor3f(0.08f, 0.13f, 0.28f);
    glBegin(GL_QUADS);
        glVertex2f(playerX - 0.028f, 0.305f);
        glVertex2f(playerX - 0.002f, 0.305f);
        glVertex2f(playerX - 0.008f, 0.245f);
        glVertex2f(playerX - 0.036f, 0.245f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(playerX + 0.002f, 0.305f);
        glVertex2f(playerX + 0.028f, 0.305f);
        glVertex2f(playerX + 0.036f, 0.245f);
        glVertex2f(playerX + 0.008f, 0.245f);
    glEnd();
    glColor3f(0.035f, 0.045f, 0.07f);
    glBegin(GL_QUADS);
        glVertex2f(playerX - 0.039f, 0.245f);
        glVertex2f(playerX - 0.006f, 0.245f);
        glVertex2f(playerX - 0.002f, 0.235f);
        glVertex2f(playerX - 0.045f, 0.235f);
        glVertex2f(playerX + 0.006f, 0.245f);
        glVertex2f(playerX + 0.039f, 0.245f);
        glVertex2f(playerX + 0.045f, 0.235f);
        glVertex2f(playerX + 0.002f, 0.235f);
    glEnd();
    glColor3f(0.12f, 0.38f, 0.88f);
    circle(playerX - 0.032f, 0.392f, 0.014f);
    circle(playerX + 0.032f, 0.392f, 0.014f);
    glBegin(GL_QUADS);
        glVertex2f(playerX - 0.040f, 0.390f);
        glVertex2f(playerX - 0.022f, 0.380f);
        glVertex2f(playerX - 0.060f, 0.340f);
        glVertex2f(playerX - 0.075f, 0.350f);
    glEnd();
    if(!fightStarted)
    {
        glBegin(GL_QUADS);
            glVertex2f(playerX + 0.022f, 0.380f);
            glVertex2f(playerX + 0.040f, 0.390f);
            glVertex2f(playerX + 0.075f, 0.420f);
            glVertex2f(playerX + 0.060f, 0.432f);
        glEnd();
    }
    else if(fightTime % 40 < 20)
    {
        glBegin(GL_QUADS);
            glVertex2f(playerX + 0.022f, 0.380f);
            glVertex2f(playerX + 0.040f, 0.390f);
            glVertex2f(playerX + 0.078f, 0.400f);
            glVertex2f(playerX + 0.072f, 0.415f);
        glEnd();
    }
    else
    {
        glBegin(GL_QUADS);
            glVertex2f(playerX + 0.022f, 0.380f);
            glVertex2f(playerX + 0.040f, 0.390f);
            glVertex2f(playerX + 0.066f, 0.475f);
            glVertex2f(playerX + 0.052f, 0.480f);
        glEnd();
    }
    glColor3f(0.96f, 0.78f, 0.62f);
    circle(playerX - 0.067f, 0.345f, 0.010f);
    if(!fightStarted)
        circle(playerX + 0.068f, 0.426f, 0.010f);
    else if(fightTime % 40 < 20)
        circle(playerX + 0.078f, 0.407f, 0.010f);
    else
        circle(playerX + 0.060f, 0.478f, 0.010f);
    if(fighting)
    {
        glColor3f(0.92f, 0.94f, 1.0f);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
            if(!fightStarted)
            {
                glVertex2f(playerX + 0.075f, 0.426f);
                glVertex2f(playerX + 0.175f, 0.505f);
            }
            else if(fightTime % 40 < 20)
            {
                glVertex2f(playerX + 0.080f, 0.407f);
                glVertex2f(playerX + 0.205f, 0.475f);
            }
            else
            {
                glVertex2f(playerX + 0.060f, 0.478f);
                glVertex2f(playerX + 0.170f, 0.400f);
            }
        glEnd();
        glLineWidth(1.0f);
    }
}
void drawEnemy()
{
    glPushMatrix();
    glTranslatef(enemyX, 0.235f, 0.0f);
    glRotatef(enemyRotation, 0.0f, 0.0f, 1.0f);
    glTranslatef(-enemyX, -0.235f, 0.0f);
    glColor3f(0.96f, 0.72f, 0.55f);
    circle(enemyX, 0.445f, 0.035f);
    glColor3f(0.12f, 0.035f, 0.035f);
    circle(enemyX, 0.468f, 0.031f);
    glColor3f(0.96f, 0.72f, 0.55f);
    glBegin(GL_QUADS);
        glVertex2f(enemyX - 0.010f, 0.405f);
        glVertex2f(enemyX + 0.010f, 0.405f);
        glVertex2f(enemyX + 0.010f, 0.420f);
        glVertex2f(enemyX - 0.010f, 0.420f);
    glEnd();
    glColor3f(0.62f, 0.07f, 0.08f);
    glBegin(GL_QUADS);
        glVertex2f(enemyX - 0.032f, 0.300f);
        glVertex2f(enemyX + 0.032f, 0.300f);
        glVertex2f(enemyX + 0.027f, 0.410f);
        glVertex2f(enemyX - 0.027f, 0.410f);
    glEnd();
    glColor3f(0.88f, 0.13f, 0.13f);
    glBegin(GL_QUADS);
        glVertex2f(enemyX - 0.021f, 0.325f);
        glVertex2f(enemyX + 0.021f, 0.325f);
        glVertex2f(enemyX + 0.018f, 0.395f);
        glVertex2f(enemyX - 0.018f, 0.395f);
    glEnd();
    glColor3f(0.14f, 0.06f, 0.04f);
    glBegin(GL_QUADS);
        glVertex2f(enemyX - 0.033f, 0.300f);
        glVertex2f(enemyX + 0.033f, 0.300f);
        glVertex2f(enemyX + 0.033f, 0.315f);
        glVertex2f(enemyX - 0.033f, 0.315f);
    glEnd();
    glColor3f(0.25f, 0.05f, 0.06f);
    glBegin(GL_QUADS);
        glVertex2f(enemyX - 0.028f, 0.305f);
        glVertex2f(enemyX - 0.002f, 0.305f);
        glVertex2f(enemyX - 0.008f, 0.245f);
        glVertex2f(enemyX - 0.036f, 0.245f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(enemyX + 0.002f, 0.305f);
        glVertex2f(enemyX + 0.028f, 0.305f);
        glVertex2f(enemyX + 0.036f, 0.245f);
        glVertex2f(enemyX + 0.008f, 0.245f);
    glEnd();
    glColor3f(0.06f, 0.035f, 0.035f);
    glBegin(GL_QUADS);
        glVertex2f(enemyX - 0.039f, 0.245f);
        glVertex2f(enemyX - 0.006f, 0.245f);
        glVertex2f(enemyX - 0.002f, 0.235f);
        glVertex2f(enemyX - 0.045f, 0.235f);
        glVertex2f(enemyX + 0.006f, 0.245f);
        glVertex2f(enemyX + 0.039f, 0.245f);
        glVertex2f(enemyX + 0.045f, 0.235f);
        glVertex2f(enemyX + 0.002f, 0.235f);
    glEnd();
    glColor3f(0.78f, 0.10f, 0.12f);
    circle(enemyX - 0.032f, 0.392f, 0.014f);
    circle(enemyX + 0.032f, 0.392f, 0.014f);
    glBegin(GL_QUADS);
        glVertex2f(enemyX + 0.022f, 0.380f);
        glVertex2f(enemyX + 0.040f, 0.390f);
        glVertex2f(enemyX + 0.075f, 0.345f);
        glVertex2f(enemyX + 0.060f, 0.338f);
    glEnd();
    if(!fightStarted)
    {
        glBegin(GL_QUADS);
            glVertex2f(enemyX - 0.040f, 0.390f);
            glVertex2f(enemyX - 0.022f, 0.380f);
            glVertex2f(enemyX - 0.075f, 0.420f);
            glVertex2f(enemyX - 0.060f, 0.432f);
        glEnd();
    }
    else if(fightTime % 40 < 20)
    {
        glBegin(GL_QUADS);
            glVertex2f(enemyX - 0.040f, 0.390f);
            glVertex2f(enemyX - 0.022f, 0.380f);
            glVertex2f(enemyX - 0.066f, 0.478f);
            glVertex2f(enemyX - 0.052f, 0.480f);
        glEnd();
    }
    else
    {
        glBegin(GL_QUADS);
            glVertex2f(enemyX - 0.040f, 0.390f);
            glVertex2f(enemyX - 0.022f, 0.380f);
            glVertex2f(enemyX - 0.078f, 0.400f);
            glVertex2f(enemyX - 0.072f, 0.415f);
        glEnd();
    }
    glColor3f(0.96f, 0.72f, 0.55f);
    circle(enemyX + 0.067f, 0.345f, 0.010f);
    if(!fightStarted)
        circle(enemyX - 0.068f, 0.426f, 0.010f);
    else if(fightTime % 40 < 20)
        circle(enemyX - 0.060f, 0.478f, 0.010f);
    else
        circle(enemyX - 0.078f, 0.407f, 0.010f);
    if(fighting && !enemyDefeated)
    {
        glColor3f(0.92f, 0.94f, 1.0f);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
            if(!fightStarted)
            {
                glVertex2f(enemyX - 0.075f, 0.426f);
                glVertex2f(enemyX - 0.175f, 0.505f);
            }
            else if(fightTime % 40 < 20)
            {
                glVertex2f(enemyX - 0.060f, 0.478f);
                glVertex2f(enemyX - 0.170f, 0.400f);
            }
            else
            {
                glVertex2f(enemyX - 0.080f, 0.407f);
                glVertex2f(enemyX - 0.205f, 0.475f);
            }
        glEnd();
        glLineWidth(1.0f);
    }
    glPopMatrix();
}
void drawFlash()
{
    if(!flash)
        return;
    glColor3f(1.0, 0.1, 0.6);
    circle(0.50, 0.47, 0.055);
    glColor3f(1.0, 0.4, 0.8);
    glBegin(GL_LINES);
        glVertex2f(0.50, 0.53);
        glVertex2f(0.50, 0.63);
        glVertex2f(0.50, 0.41);
        glVertex2f(0.50, 0.32);
        glVertex2f(0.44, 0.47);
        glVertex2f(0.34, 0.47);
        glVertex2f(0.56, 0.47);
        glVertex2f(0.66, 0.47);
        glVertex2f(0.46, 0.51);
        glVertex2f(0.39, 0.58);
        glVertex2f(0.54, 0.51);
        glVertex2f(0.61, 0.58);
        glVertex2f(0.46, 0.43);
        glVertex2f(0.39, 0.36);
        glVertex2f(0.54, 0.43);
        glVertex2f(0.61, 0.36);
    glEnd();
}
void drawPoly(const float pts[][2], int count, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        for(int i = 0; i < count; i++)
        {
            glVertex2f(pts[i][0], pts[i][1]);
        }
    glEnd();
}
void drawMountains()
{
    float poly1[][2] = {
        {0.0833f, 0.25f},
        {0.0833f, 0.55f},
        {0.1333f, 0.55f},
        {0.1500f, 0.49f},
        {0.1833f, 0.52f},
        {0.2000f, 0.43f},
        {0.2333f, 0.46f},
        {0.2333f, 0.25f}
    };
    drawPoly(poly1, 8, 0.42f, 0.46f, 0.40f);
    float t1[][2] = { {0.0167f, 0.25f}, {0.0500f, 0.34f}, {0.1000f, 0.25f} };
    float t2[][2] = { {0.2167f, 0.25f}, {0.2500f, 0.31f}, {0.2833f, 0.25f} };
    drawPoly(t1, 3, 0.24f, 0.30f, 0.20f);
    drawPoly(t2, 3, 0.24f, 0.30f, 0.20f);
    float t5[][2] = { {0.1333f, 0.25f}, {0.1500f, 0.34f}, {0.1667f, 0.25f} };
    float t6[][2] = { {0.1667f, 0.25f}, {0.1833f, 0.355f}, {0.2000f, 0.25f} };
    drawPoly(t5, 3, 0.24f, 0.30f, 0.20f);
    drawPoly(t6, 3, 0.24f, 0.30f, 0.20f);
    float t9[][2]  = { {0.3000f, 0.58f}, {0.3167f, 0.61f}, {0.3333f, 0.58f} };
    float t11[][2] = { {0.2500f, 0.49f}, {0.2667f, 0.52f}, {0.2833f, 0.49f} };
    drawPoly(t9,  3, 0.55f, 0.58f, 0.50f);
    drawPoly(t11, 3, 0.55f, 0.58f, 0.50f);
    float poly2[][2] = {
        {0.7667f, 0.25f},
        {0.7667f, 0.46f},
        {0.8000f, 0.43f},
        {0.8167f, 0.52f},
        {0.8500f, 0.49f},
        {0.8667f, 0.55f},
        {0.9167f, 0.55f},
        {0.9167f, 0.25f}
    };
    drawPoly(poly2, 8, 0.42f, 0.46f, 0.40f);
    float t3[][2] = { {0.7167f, 0.25f}, {0.7500f, 0.31f}, {0.7833f, 0.25f} };
    float t4[][2] = { {0.9000f, 0.25f}, {0.9500f, 0.34f}, {0.9833f, 0.25f} };
    drawPoly(t3, 3, 0.24f, 0.30f, 0.20f);
    drawPoly(t4, 3, 0.24f, 0.30f, 0.20f);
    float t7[][2] = { {0.8000f, 0.25f}, {0.8167f, 0.355f}, {0.8333f, 0.25f} };
    float t8[][2] = { {0.8333f, 0.25f}, {0.8500f, 0.34f}, {0.8667f, 0.25f} };
    drawPoly(t7, 3, 0.24f, 0.30f, 0.20f);
    drawPoly(t8, 3, 0.24f, 0.30f, 0.20f);
    float t10[][2] = { {0.7000f, 0.61f}, {0.7167f, 0.64f}, {0.7333f, 0.61f} };
    float t12[][2] = { {0.7333f, 0.52f}, {0.7500f, 0.55f}, {0.7667f, 0.52f} };
    drawPoly(t10, 3, 0.55f, 0.58f, 0.50f);
    drawPoly(t12, 3, 0.55f, 0.58f, 0.50f);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.53, 0.81, 0.92);
    glBegin(GL_QUADS);
        glVertex2f(0.0, 0.0);
        glVertex2f(1.0, 0.0);
        glVertex2f(1.0, 1.0);
        glVertex2f(0.0, 1.0);
    glEnd();
    glColor3f(1.0, 0.8, 0.0);
    circle(0.50, 0.82, 0.07);
    glColor3f(1.0, 0.9, 0.2);
    glBegin(GL_LINES);
        glVertex2f(0.50, 0.90);
        glVertex2f(0.50, 1.00);
        glVertex2f(0.55, 0.88);
        glVertex2f(0.62, 0.96);
        glVertex2f(0.45, 0.88);
        glVertex2f(0.38, 0.96);
        glVertex2f(0.58, 0.82);
        glVertex2f(0.70, 0.82);
        glVertex2f(0.42, 0.82);
        glVertex2f(0.30, 0.82);
        glVertex2f(0.55, 0.76);
        glVertex2f(0.63, 0.68);
        glVertex2f(0.45, 0.76);
        glVertex2f(0.37, 0.68);
    glEnd();
    glColor3f(0.60, 0.30, 0.16);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.47, 0.78);
        glVertex2f(0.53, 0.78);
        glVertex2f(0.65, 0.25);
        glVertex2f(0.47, 0.78);
        glVertex2f(0.65, 0.25);
        glVertex2f(0.35, 0.25);
    glEnd();
    glColor3f(0.20f, 0.30f, 0.14f);
    glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(1.0f, 0.25f);
        glVertex2f(0.0f, 0.25f);
    glEnd();
    glColor3f(0.28f, 0.42f, 0.18f);
    glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.235f);
        glVertex2f(1.0f, 0.235f);
        glVertex2f(1.0f, 0.25f);
        glVertex2f(0.0f, 0.25f);
    glEnd();
    glColor3f(0.14f, 0.20f, 0.09f);
    glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(1.0f, 0.018f);
        glVertex2f(0.0f, 0.018f);
    glEnd();
    drawMountains();
    glColor3f(0.50, 0.50, 0.52);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.02, 0.25);
        glVertex2f(0.08, 0.35);
        glVertex2f(0.14, 0.25);
        glVertex2f(0.20, 0.25);
        glVertex2f(0.25, 0.33);
        glVertex2f(0.30, 0.25);
        glVertex2f(0.70, 0.25);
        glVertex2f(0.75, 0.34);
        glVertex2f(0.80, 0.25);
        glVertex2f(0.86, 0.25);
        glVertex2f(0.92, 0.35);
        glVertex2f(0.98, 0.25);
    glEnd();
    drawPlayer();
    drawEnemy();
    drawFlash();
    glFlush();
}
void resetGame()
{
    playerX = playerStartX;
    enemyX = enemyStartX;
    playerMoving = false;
    enemyMoving = false;
    fighting = false;
    fightStarted = false;
    fightTime = 0;
    defeatTime = 0;
    flash = false;
    returningHome = false;
    enemyDefeated = false;
    enemyRotation = 0.0f;
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
    if(key == 'q' || key == 'Q')
    {
        resetGame();
        return;
    }
    if(key == 'r' || key == 'R')
    {
        if(!fightStarted &&
           !returningHome &&
           !enemyDefeated &&
           !playerMoving)
        {
            fighting = true;
            playerMoving = true;
        }
    }
    if(key == 't' || key == 'T')
    {
        if(!fightStarted &&
           !returningHome &&
           !enemyDefeated &&
           !enemyMoving)
        {
            fighting = true;
            enemyMoving = true;
        }
    }
    if(key == 'f' || key == 'F')
    {
        if(!fightStarted)
        {
            float distance = enemyX - playerX;
            if(fighting &&
               !playerMoving &&
               !enemyMoving &&
               !enemyDefeated &&
               distance >= minFightDistance &&
               distance <= 0.25f)
            {
                fightStarted = true;
                fightTime = 0;
                flash = false;
            }
        }
        else
        {
            fightStarted = false;
            fighting = false;
            enemyDefeated = true;
            enemyRotation = 0.0f;
            defeatTime = 0;
            flash = true;
            returningHome = true;
        }
    }
    glutPostRedisplay();
}
void timer(int value)
{
    if(playerMoving &&
       !fightStarted &&
       !returningHome &&
       !enemyDefeated)
    {
        if(playerX < playerFightX)
        {
            playerX += 0.01f;
        }
        if(playerX >= playerFightX)
        {
            playerX = playerFightX;
            playerMoving = false;
        }
    }
    if(enemyMoving &&
       !fightStarted &&
       !returningHome &&
       !enemyDefeated)
    {
        if(enemyX > enemyFightX)
        {
            enemyX -= 0.01f;
        }
        if(enemyX <= enemyFightX)
        {
            enemyX = enemyFightX;
            enemyMoving = false;
        }
    }
    if(fightStarted)
    {
        fightTime++;
        if(fightTime % 40 < 20)
        {
            if(fightTime % 40 == 5 ||
               fightTime % 40 == 6 ||
               fightTime % 40 == 7)
            {
                flash = true;
            }
            else
            {
                flash = false;
            }
        }
        else
        {
            if(fightTime % 40 == 25 ||
               fightTime % 40 == 26 ||
               fightTime % 40 == 27)
            {
                flash = true;
            }
            else
            {
                flash = false;
            }
        }
    }
    if(enemyDefeated)
    {
        defeatTime++;
        if(enemyRotation > -90.0f)
        {
            enemyRotation -= 4.0f;
            if(enemyRotation < -90.0f)
            {
                enemyRotation = -90.0f;
            }
        }
        if(defeatTime > 10)
        {
            flash = false;
        }
    }
    if(returningHome)
    {
        if(playerX > playerStartX)
        {
            playerX -= 0.01f;
        }
        if(playerX <= playerStartX)
        {
            playerX = playerStartX;
            returningHome = false;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}
void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(150, 100);
    glutCreateWindow("Fantasy Battle Arena - Fight");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(30, timer, 0);
    glutMainLoop();
    return 0;
}
