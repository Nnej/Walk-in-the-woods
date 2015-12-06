//
//  drawVgtx.c
//  Balade en Foret mai 2012
//
//  Created by Jennifer Guiard on 18/05/12.
//  Copyright (c) 2012 Jennifer Guiard. All rights reserved.

#include "header.h"

// Fonction qui modelise un buisson
void drawArbuste() {
	glColor3f(0.41f, 0.55f, 0.14f);
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(1.0f,30,30);
}

// Fonction qui modelise une mousse
void drawMousse() {
	glColor3f(0.33f, 0.41f, 0.18f);
	glTranslatef(0.0f ,0.05f, 0.0f);
	glutSolidSphere(0.25f,15,15);	
}

// Fonction qui modelise un arbre 
void drawArbre() {
	//initialisation pour le cylindre
	GLUquadricObj *quadratic2;
	quadratic2 = gluNewQuadric();
	
	// Cime
	glPushMatrix();
	glColor3f(0.0f, 0.5f, 0.0f);
	glTranslatef(0.0f ,6.75f, 0.0f);
	glutSolidSphere(3.0f,30,30);
	glPopMatrix();
	
	// Tronc
	glColor3f(0.62f, 0.32f, 0.17f);
	glRotatef(-90.0f,1.0f, 0.0f, 0.0f);
	gluCylinder(quadratic2,0.50f,0.50f,4.0f,11,11);
	
	gluDeleteQuadric(quadratic2);
	
}

//Fonction qui modelise un sapin
void drawSapin() {
	//initialisation pour le cylindre
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric(); 
	
	// Cime
	glPushMatrix();
	glColor3f(0.0f, 0.39f, 0.0f);
	glTranslatef(0.0f ,3.0f, 0.0f);
	glRotatef(-90.0f,1.0f, 0.0f, 0.0f);
	glutSolidCone(3.8f,12.5f,20,20);
	glPopMatrix();
	
	// Tronc
	glColor3f(0.54f, 0.27f, 0.07f);
	glRotatef(-90.0f,1.0f, 0.0f, 0.0f);
	gluCylinder(quadratic,1.0f,1.0f,4.0f,12,12);
	
	gluDeleteQuadric(quadratic);
	
}

//Dessiner la foret
void drawForet() {
	float i, j, k, l, m, n, p, q;
	
	drawSol();
	
	//Dessiner Arbustes
	for(k= -10; k < 10; k++) 
		for(l=-10; l< 5; l++) {
			
			if (l==0)
				l+=1;
			
			glPushMatrix();
			glTranslatef(k* -22.0, 0.0, l * 15.7);
			drawArbuste();
			glPopMatrix();
		}
	
	//Dessiner Sapins
	for(i=-15; i < 15; i++)
		for(j=-15; j < 10; j++) {
			
			glPushMatrix();
			glTranslatef(i*15.0, 0.0, j * -21.0);
			drawSapin();
			glPopMatrix();
		}
	
	//Dessiner Arbres
	for(m= -10; m < 10; m++) 
		for(n=-10; n< 1;n++) {
			
			if (n==0) 
				n += 1;
			
			glPushMatrix();
			glTranslatef(m *-28.0, 0.0, n * 37.7);
			drawArbre();
			glPopMatrix();
		}
	
	//Dessiner Mousses
	for(p= -6; p < 6; p++) 
		for(q=-6; q< 6; q++) {
			
			if (q==0)
				q += 1;
			
			glPushMatrix();
			glTranslatef(p * 4.0, 0.0, q *-7.7);
			drawMousse();
			glPopMatrix();
		}
    
}
