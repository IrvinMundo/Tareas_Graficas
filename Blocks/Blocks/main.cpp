//
//  main.cpp
//  Blocks
//
//  Created by Irvin Mundo on 19/01/18.
//  Copyright © 2018 MundoSystems. All rights reserved.
//

#ifdef __APPLE__
// See: http://lnx.cx/docs/opengl-in-xcode/
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif
#include <math.h>

#include <stdlib.h>
#include <stdio.h>
#define HEIGHT 5
#define WIDTH 6

float cellWidth = 0.3f;
float cellHeight = 0.1f;

float playerX = 0.0f;
float playerY = 0.0f;

float offsetX = -0.5f * cellWidth * WIDTH;
float offsetY = 1.0f;

float ballX = 0.0f;
float ballY = 0.0f;
float ballRadius = 0.2f;
float ballAngle = 45.0f;

int wall[HEIGHT][WIDTH];
float colorsR[HEIGHT][WIDTH];
float colorsG[HEIGHT][WIDTH];
float colorsB[HEIGHT][WIDTH];


void init(){
    for(int row = 0; row < HEIGHT; row++){
        for(int col = 0; col < WIDTH; col++){
            wall[row][col] = 1;
            colorsR[row][col] = (float)rand() / RAND_MAX;
            colorsG[row][col] = (float)rand() / RAND_MAX;
            colorsB[row][col] = (float)rand() / RAND_MAX;
        }
    }
    
    glEnable(GL_DEPTH_TEST);            // Enable check for close and far objects.
    glClearColor(0.3, 0.3, 0.3, 1.0);    // Clear the color state. Cambiar el color sw fondo
    glMatrixMode(GL_MODELVIEW);            // Go to 3D mode.
    glLoadIdentity();
    
}

void drawSquare(float x, float y, float w, float h, float r, float g, float b){
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    {
        glVertex3f(x, y, 0);
        glVertex3f(x+w, y, 0);
        glVertex3f(x+w, y+h, 0);
        glVertex3f(x, y+h, 0);
    }
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                // Clear color and depth buffers. Borramos todo de los bufers
    for(int row = 0; row < HEIGHT; row++){
        for(int col = 0; col < WIDTH; col++){
            if(wall[row][col] == 1){
                drawSquare(offsetX + col*cellWidth,offsetY + row*cellHeight, cellWidth, cellHeight, colorsR[row][col],colorsG[row][col],colorsB[row][col]);
            }
        }
    }
    drawSquare(playerX,playerY,cellWidth,cellHeight, 0.5f,0.5f,0.5f);
    
    glutSwapBuffers();
}

void idle()                                                            // Called when drawing is finished.
{
    //printf("%.3f -- %.3f\n", offsetX, offsetY);
    glutPostRedisplay();                                            // Display again. Ultima linea de idle
}

void reshape(int x, int y)                                            // Called when the window geometry changes.
{
    glMatrixMode(GL_PROJECTION);                                    // Go to 2D mode.
    glLoadIdentity();                                                // Reset the 2D matrix.
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 50.0);        // Configure the camera lens aperture.
    glMatrixMode(GL_MODELVIEW);                                        // Go to 3D mode.
    glLoadIdentity();                                                // Reset the 3D matrix.
    glViewport(0, 0, x, y);                                            // Configure the camera frame dimensions.
    gluLookAt(0.0, 0.0, 5.0,                                        // Where the camera is. Posicion de la camara
              0.0, 0.0, 0.0,                                                // To where the camera points at.
              0.0, 1.0, 0.0);                                                // "UP" vector.
    display();
}

void arrows(int k, int x, int y){
    switch(k){
        case GLUT_KEY_LEFT:
            if(playerX > offsetX){
                playerX -= 0.1f;
            }
            break;
        case GLUT_KEY_RIGHT:
            if(playerX < -offsetX){
                playerX += 0.1f;
            }
            break;
    }
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);                                            // Init GLUT with command line parameters. Iniciamos el GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);        // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG DEMO");
    
    init();
    glutSpecialFunc(arrows);
    glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
    glutDisplayFunc(display);                                        // Display CALLBACK function.
    glutIdleFunc(idle);                                                // Idle CALLBACK function.
    glutMainLoop();                                                    // Begin graphics program.
    return 0;                                                        // ANSI C requires a return value.
}
