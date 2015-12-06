//
//  main.c
//  Balade en Foret mai 2012
//
//  Created by Jennifer Guiard on 15/05/12.
//  Copyright (c) 2012 Jennifer Guiard. All rights reserved.

#include "header.h"

//Fonction qui calcule la position en X et Z
void calculPos(float deltaMvt) {
	x += deltaMvt * lx * 0.5f;
	z += deltaMvt * lz * 0.5f;
    y += deltaMvt * ly * 0.5f;
}

//Fonction qui calcule la direction en X et Z
void calculDir(float deltaAngle) {
	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
    ly = ly;//qqch d'angle
}

void processNormalKeys(unsigned char key, int xx, int yy) {
	// Quitter avec la touche ESC
	if (key == 27)
		exit(0);
}

void presserTouche(int key, int xx, int yy) {
	
	switch (key) {
		case GLUT_KEY_LEFT : 
			deltaAngle = -0.01f; 
			break;
		case GLUT_KEY_RIGHT : 
			deltaAngle = 0.01f; 
			break;
		case GLUT_KEY_UP : 
			deltaMvt = 0.5f; 
			break;
		case GLUT_KEY_DOWN : 
			deltaMvt = -0.5f; 
			break;
		case GLUT_KEY_F5:
			activerFog(); // Activation du brouillard
			break;
		case GLUT_KEY_F6: // Desactivation du brouillard
			glDisable(GL_FOG);
			glClearColor( 0.53, 0.8, 0.92, 1.0 );
			break;
        case GLUT_KEY_PAGE_UP: // Montee camera sur l'axe Y
            y += 1.5f;
            break;
        case GLUT_KEY_PAGE_DOWN: // Descente camera sur l'axe Y
            y -= 1.5f;
            break;
	}
}

void releverTouche(int key, int xx, int yy) {
	
	switch (key) {
		case GLUT_KEY_LEFT :
		case GLUT_KEY_RIGHT : 
			deltaAngle = 0.0f;
			break;
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : 
			deltaMvt = 0.0;
			break;
        case GLUT_KEY_PAGE_UP:
        case GLUT_KEY_PAGE_DOWN:
            break;
	}
}

void changeSize(int w, int h){
	// Taille minimale de la fenêtre
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	
	glMatrixMode(GL_PROJECTION);
	
	glLoadIdentity();
	
	glViewport(0, 0, w, h);
	
	gluPerspective(45.0f, ratio, 1.0f, 100.0f);
	
	glMatrixMode(GL_MODELVIEW);
}


//Fonction pour le rendu de la scene
void renduScene(void) {
	
	if (deltaMvt)
		calculPos(deltaMvt);
	if (deltaAngle)
		calculDir(deltaAngle);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	// Position camera
	gluLookAt(	x, y, z,
			  x+lx, y+ly, z+lz,
			  0.0f, 1.0f, 0.0f);
	
	gestionLum();
	
	drawForet();
	
	glutSwapBuffers();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("BALADE EN FORET - MAI 2012");
	
	glutDisplayFunc(renduScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renduScene);
	glutSpecialFunc(presserTouche);
	
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releverTouche);
	
	glClearColor(0.53, 0.8, 0.92, 1.0 );
	
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	gestionLum();
	
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL); 
	
	initVBO();

	glutMainLoop();
	
	deleteVBO(Id_vbo); 
	
    return 1;
}
