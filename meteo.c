//
//  meteo.c
//  Balade en Foret mai 2012
//
//  Created by Jennifer Guiard on 18/05/12.
//  Copyright (c) 2012 Jennifer Guiard. All rights reserved.

#include "header.h"

//Gestion de la lumiere en fonction du temps
void gestionLum() {
	int tps_actuel, ecart_tps;
	float val;
	static float a =0.0;
    
	//recuperation du temps actuel en ms
	tps_actuel = glutGet(GLUT_ELAPSED_TIME);
	
	ecart_tps = tps_actuel - tps_prec;
	
	val = fabsf(cosf(a))/2;
    
	//Toutes les 25 images seconde
	if(ecart_tps >= 40){
		a += 0.01; //avec a+=0.005 transition plus rapide
		tps_prec = tps_actuel;
	}
	
	//Evolution synchrone de la lumiere ambiante et diffuse
	// pour donner l'illusion du jour et de la nuit
	GLfloat lightAmb[4] = {val, val, val, 1.0f};
	GLfloat lightDif[4] = {val, val, val, 1.0f};
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
    
    //Evolution de la couleur du ciel en fonction de la lumiere
    glClearColor(val+0.03,val+0.25,val+0.42,1.0);
}

// Le brouillard
void activerFog() {
	glFogf(GL_FOG_MODE, GL_LINEAR);
	glFogfv(GL_FOG_COLOR, couleurFog);
	glFogf(GL_FOG_DENSITY, 0.55 );
	glHint(GL_FOG_HINT, GL_DONT_CARE);
	glFogf(GL_FOG_START, 15.0);
	glFogf(GL_FOG_END, 100.0);
	glEnable(GL_FOG);
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
}