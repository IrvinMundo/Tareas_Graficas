//
//  main.cpp
//  Clase 16 de enero
//
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
float verdejamaica*;

void init() // FOR GLUT LOOP
{
    shape=0;
    glEnable(GL_DEPTH_TEST);            // Enable check for close and far objects.
    glClearColor(0.3, 0.3, 0.3, 1.0);    // Clear the color state. Cambiar el color sw fondo
    glMatrixMode(GL_MODELVIEW);            // Go to 3D mode.
    glLoadIdentity();                    // Reset 3D view matrix.
}

void keys(unsigned char k, int x, int y){
    switch (k) {
        case '0':
            shape=0;
            break;
        case '1':
            shape=1;
            break;
        default:
            break;
    }
    glutPostRedisplay();
    
}

void display()                            // Called for each frame (about 60 times per second).
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                // Clear color and depth buffers. Borramos todo de los bufers
    
    glColor3f(1.0f, 1.0f, 0.0f);                                    // Yellow Definimos el color
    //glutWireTeapot(1); //definimos la forma glutWireSphere(1,20,20);
    
    glPointSize(5);
    glLineWidth(5);
    //glBegin(GL_POINTS); //Aqui tenemos que poner nuestros diseños. Le decimos que primitiva vamos a dibujar
    glBegin(GL_LINES); //PARA LAS LINEAS OBLIGATORIO NECESITAMOS MINIMO DOS PUNTOS
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    
    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
    
    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
    
    glEnd();
    /*
    glBegin(GL_TRIANGLES);
    glVertex3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
    
    glColor3f(1, 0, 0);
    glVertex3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,0,1);
    
    glColor3f(0, 1, 0);
    glVertex3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    */
    if(shape == 0){
        glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        glVertex3f(0,1,0);
        
        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        glVertex3f(0,0,1);
        
        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
        glVertex3f(0,0,1);
        glEnd();
    }
    if(shape == 1){
        glBegin(GL_TRIANGLES);
        glColor3f(1,1,0);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        glVertex3f(0,1,0);
        
        glColor3f(1,0,1);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        glVertex3f(0,0,1);
        
        glColor3f(0,1,1);
        glVertex3f(0,0,0);
        glVertex3f(0,1,0);
        glVertex3f(0,0,1);
        glEnd();
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
    gluLookAt(5.0, 5.0, 5.0,                                        // Where the camera is. Posicion de la camara
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

