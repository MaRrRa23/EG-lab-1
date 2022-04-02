#include <iostream>
#include "C:\SRC\vcpkg\packages\freeglut_x64-windows\include\GL\glut.h"

int main(int argc, char** argv)
{
    void RenderSceneCB();
    void glutInit(int* argcp, char** argv);
    glutInit(&argc, argv);
    glutCreateWindow("Tutorial 01");
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutDisplayFunc(RenderSceneCB);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glutMainLoop();

    return 0;
}

void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}