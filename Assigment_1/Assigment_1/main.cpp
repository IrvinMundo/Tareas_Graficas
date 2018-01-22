//
//  main.cpp
//  Assigment_1
//  A01332573 Alfredo Puente Vasconcelos, A01333820 Irvin Uriel Mundo Rivera
//  Created by Irvin Mundo on 16/01/18.
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
#include <stdio.h>
#include <math.h>

int shape;


void init() // FOR GLUT LOOP
{
    shape=1;
    glEnable(GL_DEPTH_TEST);            // Enable check for close and far objects.
    glClearColor(0.3, 0.3, 0.3, 1.0);    // Clear the color state. Cambiar el color sw fondo
    glMatrixMode(GL_MODELVIEW);            // Go to 3D mode.
    glLoadIdentity();                    // Reset 3D view matrix.
}

void keys(unsigned char k, int x, int y){
    switch (k) {
        case '1':
            shape=1;
            break;
        case '2':
            shape=2;
            break;
        case '3':
            shape=3;
            break;
        case '4':
            shape=4;
            break;
        case '5':
            shape=5;
            break;
        case '6':
            shape=6;
            break;
        case '7':
            shape=7;
            break;
        default:
            shape=0;
            break;
    }
    glutPostRedisplay();
    
}
  void  japon(){
    //Fondo
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(-3,-2);
    glVertex2f(3,-2);
    glVertex2f(3,2);
    glVertex2f(-3,2);
    glEnd();
    //Círculo
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    for(int i=0; i<360;i++){
        float radians = i*3.1415f / 180.0f;
        float x = cos(radians);
        float y = sin(radians);
        glVertex3f(x,y,0.75);
    }
    glEnd();
}
void alemania(){
    //fondo
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-3,-2);
    glVertex2f(3,-2);
    glVertex2f(3,2);
    glVertex2f(-3,2);
    glEnd();
    //cuadro rojo
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(-3,-0.66,0.0001);
    glVertex3f(3,-0.66,0.0001);
    glVertex3f(3,0.66,0.0001);
    glVertex3f(-3,0.66,0.0001);
    glEnd();
    //cuadro amarillo
    glColor3f(1, 1, 0);
    glBegin(GL_QUADS);
    glVertex3f(-3,-2,0.0002);
    glVertex3f(3,-2,0.0002);
    glVertex3f(3,-0.66,0.0002);
    glVertex3f(-3,-0.66,0.0002);
    glEnd();
}
void jamaica(){
    //fondo
    glColor3f(1, 1, 0);
    glBegin(GL_QUADS);
    glVertex2f(-3,-2);
    glVertex2f(3,-2);
    glVertex2f(3,2);
    glVertex2f(-3,2);
    glEnd();
    //Triangulos negros
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-3,-1.8,0.0001);
    glVertex3f(-3,1.8,0.0001);
    glVertex3f(-0.5,0,0.0001);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f(3,-1.8,0.0001);
    glVertex3f(3,1.8,0.0001);
    glVertex3f(0.5,0,0.0001);
    glEnd();
    //Triangulos verdes
    glColor3f(0.13, 0.6, 0.25);
    glBegin(GL_TRIANGLES);
    glVertex3f(-2.5,-2,0.0002);
    glVertex3f(2.5, -2,0.0002);
    glVertex3f(0,-0.25,0.0002);
    glEnd();
    glColor3f(0.13, 0.6, 0.25);
    glBegin(GL_TRIANGLES);
    glVertex3f(-2.5,2,0.0002);
    glVertex3f(2.5, 2,0.0002);
    glVertex3f(0,0.25,0.0002);
    glEnd();
}
void finlandia(){
    //fondo
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(-3,-2);
    glVertex2f(3,-2);
    glVertex2f(3,2);
    glVertex2f(-3,2);
    glEnd();
    //vertical
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    glVertex3f(-1,2,0.0001);
    glVertex3f(0,2,0.0001);
    glVertex3f(0,-2,0.0001);
    glVertex3f(-1,-2,0.0001);
    glEnd();
    //horizontal
    glBegin(GL_QUADS);
    glVertex3f(-3,0.5,0.0002);
    glVertex3f(3,0.5,0.0002);
    glVertex3f(3,-0.5,0.0002);
    glVertex3f(-3,-0.5,0.0002);
    glEnd();
}
void bahamas(){
    glColor3f(0,171,201);
    glBegin(GL_QUADS);
    glVertex2f(-3,-2);
    glVertex2f(3,-2);
    glVertex2f(3,2);
    glVertex2f(-3,2);
    glEnd();
    
    glColor3f(1, 1, 0);
    glBegin(GL_QUADS);
    glVertex3f(-3,-0.66,0.0001);
    glVertex3f(3,-0.66,0.0001);
    glVertex3f(3,0.66,0.0001);
    glVertex3f(-3,0.66,0.0001);
    glEnd();
    
    glColor3f(0,17,20);
    glBegin(GL_QUADS);
    glVertex3f(-3,-2,0.0002);
    glVertex3f(3,-2,0.0002);
    glVertex3f(3,-0.66,0.0002);
    glVertex3f(-3,-0.66,0.0002);
    glEnd();
    
    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-3,2,0.0003);
    glVertex3f(-3,-2,0.0003);
    glVertex3f(-0.3,0,0.0003);
    glEnd();
}
void somalia(){
    glColor3f(0.118, 0.565, 1.000);
    glBegin(GL_QUADS);
    glVertex2f(-3,-2);
    glVertex2f(3,-2);
    glVertex2f(3,2);
    glVertex2f(-3,2);
    glEnd();
    
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for(int i=54; i<360;i+=72){
        int j;
        j = i + 36;
        float radians = i*atan(1)*4 / 180.0f;
        float x = cos(radians);
        float y = sin(radians);
        float radians2 = j*atan(1)*4 / 180.0f;
        float x2 = cos(radians2);
        float y2 = sin(radians2);
        glVertex3f(x/5.5,y/5.5,0.0001);
        glVertex3f(x2/2,y2/2,0.0001);
    }
    glEnd();
}

void grecia(){
    glColor3f(0.255, 0.412, 0.882);
    glBegin(GL_QUADS);
    glVertex2f(-3,-2);
    glVertex2f(3,-2);
    glVertex2f(3,2);
    glVertex2f(-3,2);
    glEnd();
    
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-3.,1.55,0.001);
    glVertex3f(3,1.55,0.001);
    glVertex3f(3,1.11,0.001);
    glVertex3f(-3,1.11,0.001);
    glEnd();
    
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-3.,0.66,0.001);
    glVertex3f(3,0.66,0.001);
    glVertex3f(3,0.22,0.001);
    glVertex3f(-3,0.22,0.001);
    glEnd();
    
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(3,-0.22,0.001);
    glVertex3f(-3,-0.22,0.001);
    glVertex3f(-3.,-0.66,0.001);
    glVertex3f(3,-0.66,0.001);
    glEnd();
    
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(3,-1.11,0.001);
    glVertex3f(-3,-1.11,0.001);
    glVertex3f(-3.,-1.55,0.001);
    glVertex3f(3,-1.55,0.001);
    glEnd();
    
    glColor3f(0.255, 0.412, 0.882);
    glBegin(GL_QUADS);
    glVertex3f(-3,2,0.002);
    glVertex3f(-3,-0.22,0.002);
    glVertex3f(-1,-0.22,0.002);
    glVertex3f(-1,2,0.002);
    glEnd();
    
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-1,1.11,0.003);
    glVertex3f(-3,1.11,0.003);
    glVertex3f(-3,0.66,0.003);
    glVertex3f(-1,0.66,0.003);
    glEnd();
    
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-2.225,2,0.003);
    glVertex3f(-1.775,2,0.003);
    glVertex3f(-1.775,-0.22,0.003);
    glVertex3f(-2.225,-0.22,0.003);
    glEnd();
}
void display()                            // Called for each frame (about 60 times per second).
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                // Clear color and depth buffers. Borramos todo de los bufers
    
    switch(shape){
        case 1:
            japon();
            break;
        case 2:
            alemania();
            break;
        case 3:
            jamaica();
            break;
        case 4:
            finlandia();
            break;
        case 5:
            bahamas();
            break;
        case 6:
            somalia();
            break;
        case 7:
            grecia();
            break;
        default:
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            break;
    }
    
    glutSwapBuffers();                                                // Swap the hidden and visible buffers. Ultima linea de display
}

void idle()                                                            // Called when drawing is finished.
{
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
    gluLookAt(0.0, 0.0, 10.0,                                        // Where the camera is. Posicion de la camara
              0.0, 0.0, 0.0,                                                // To where the camera points at.
              0.0, 1.0, 0.0);                                                // "UP" vector.
    display();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);                                            // Init GLUT with command line parameters.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);        // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG DEMO");
    
    init();
    glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
    glutDisplayFunc(display);                                        // Display CALLBACK function.
    glutKeyboardFunc(keys);
    glutIdleFunc(idle);                                                // Idle CALLBACK function.
    glutMainLoop();                                                    // Begin graphics program.
    return 0;                                                        // ANSI C requires a return value.
}


