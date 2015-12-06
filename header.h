//
//  header.h
//  Balade en Foret mai 2012
//
//  Created by Jennifer Guiard on 15/05/12.
//  Copyright (c) 2012 Jennifer Guiard. All rights reserved.

#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "time.h"

//    v2----- v1
//   /        /
//  v3------v0

//Tableau des sommets
GLfloat sommets[12] = {
	-1500, 0, -1500,  //v0
	-1500, 0, 1500,  //v1
    1500, 0, 1500,  //v2
    1500, 0, -1500  //v3
};

//Tableau des normales
GLfloat normales[12] = {
	0, 1, 0,  //v0
	0, 1, 0,  //v1
	0, 1, 0,  //v2
	0, 1, 0   //v3
};

//Tableau des couleurs
GLfloat couleurs[12] = {
	0.13, 0.54, 0.13,   //v0
	0.13, 0.54, 0.13,   //v1
	0.13, 0.54, 0.13,   //v2
	0.13, 0.54, 0.13    //v3
};

// Identifiant de VBO pour le tableau des sommets
GLuint Id_vbo = 0;

// Angle de rotation de la camera
float angle = 0.10f;
// Vecteur actuel correspondant à la direction de la camera 
float lx= 0.0f, ly=0.0f, lz= -1.0f;

// Position de la camera en X , Y et Z
float x= 2.0f, z= 5.0f, y= 1.5f; 

// Etats des touches. A zero quand aucune touche presser
float deltaAngle = 0.0f;
float deltaMvt = 0;

// Variable temps précédent pour la gestion de la lumière
int tps_prec = 0;

// Tableau qui defini la couleur du brouillard
GLfloat couleurFog[4] = {0.5f,0.5f,0.5f,1.0f};

// Tableau qui defini pour la position de la lumière
GLfloat lightPos[4] = {0.0f, 0.0f, 2.0f, 1.0f}; 

//main.c
void calculPos(float deltaMvt);
void calculDir(float deltaAngle);
void processNormalKeys(unsigned char key, int xx, int yy);
void presserTouche(int key, int xx, int yy); 
void releverTouche(int key, int xx, int yy);
void changeSize(int w, int h);
void renduScene(void);
int main(int argc, char *argv[]);

//drawSol.c
void initVBO(void);
void drawSol(void);
void deleteVBO(const GLuint Id_vbo);

//meteo.c
void gestionLum(void);
void activerFog(void);

//drawVgtx.c
void drawArbuste(void);
void drawMousse(void);
void drawArbre(void);
void drawSapin(void);
void drawForet(void);
