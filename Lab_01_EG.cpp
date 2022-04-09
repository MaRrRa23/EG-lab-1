#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>
#include "math_3d.h"

GLuint VBO;

void RenderSceneTriangleCB()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_LINES, 0, 3);
    glDisableVertexAttribArray(0);

    glutSwapBuffers();
}

void RenderScenePointCB()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_POINTS, 0, 1);
    glDisableVertexAttribArray(0);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Tutorial 01");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1024, 768);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    GLenum res = glewInit();
    if (res != GLEW_OK)
    {
        std::cout << "Error during GLEW initialization";
        return 1;
    }

    glm::vec3 Vertices[3] = { 
        { 1.0f, 1.0f, 0.0f },
        { -1.0f, 1.0f, 0.0f },
        { 0.0f, -1.0f, 0.0f }
    };

    // Прямой треугольник
    //Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
    //Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
    //Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

    glutDisplayFunc(RenderSceneTriangleCB);

    glutMainLoop();

    return 0;
}
