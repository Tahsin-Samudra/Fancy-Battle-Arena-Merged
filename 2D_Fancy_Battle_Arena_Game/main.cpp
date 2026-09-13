#include <GL/glut.h>
#include <windows.h>
#include <shellapi.h>

// ===================== Button launch paths =====================
// Update these to match where each project's .exe actually gets built
// (check each project's bin\Debug or bin\Release folder).

const char* LEVEL1_EXE_PATH =
    "E:\\Computer Graphics\\Graphics_Project\\Fancy Battle Arena\\bin\\Debug\\Fancy Battle Arena.exe";


const char* LEVEL3_EXE_PATH =
    "E:\\Computer Graphics\\Graphics_Project\\Adin'Frame\\bin\\Debug\\Adin'Frame.exe";


void launchGame(const char* exePath)
{
    ShellExecuteA(NULL, "open", exePath, NULL, NULL, SW_SHOWNORMAL);
    exit(0);
}



void drawButton(float x, float y, float width, float height)
{
    glColor3f(0.0f, 0.0f, 1.0f);

    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
    glEnd();
}


void drawLabel(float x, float y, const char* text)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(x, y);

    for (int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}


void display()
{
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawButton(-5.0f, 5.0f, 10.0f, 3.0f);   // Level 1 button
    drawButton(-5.0f, -5.0f, 10.0f, 3.0f);  // Level 3 button

    drawLabel(-2.0f, 6.0f, "LEVEL 1");
    drawLabel(-2.0f, -4.0f, "LEVEL 3");

    glutSwapBuffers();
}


// ===================== Input =====================
void mouseClick(int button, int state, int x, int y)
{
    if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;

    int winW = glutGet(GLUT_WINDOW_WIDTH);
    int winH = glutGet(GLUT_WINDOW_HEIGHT);

    float fx = ((float)x / (float)winW) * 60.0f - 30.0f;
    float fy = 30.0f - ((float)y / (float)winH) * 60.0f;

    // Level 1 button: x in [-5,5], y in [5,8]
    if (fx >= -5.0f && fx <= 5.0f && fy >= 5.0f && fy <= 8.0f)
    {
        launchGame(LEVEL1_EXE_PATH);
    }

    // Level 3 button: x in [-5,5], y in [-5,-2]
    else if (fx >= -5.0f && fx <= 5.0f && fy >= -5.0f && fy <= -2.0f)
    {
        launchGame(LEVEL3_EXE_PATH);
    }
}


// ===================== Setup =====================
void init()
{
    glClearColor(0, 0, 0, 0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-30, 30, -30, 30, -30, 30);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1980, 1080);
    glutCreateWindow("Main Menu");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouseClick);

    glutMainLoop();

    return 0;
}
