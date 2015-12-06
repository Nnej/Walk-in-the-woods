//
//  drawSol.c
//  Balade en Foret mai 2012
//
//  Created by Jennifer Guiard on 18/05/12.
//  Copyright (c) 2012 Jennifer Guiard. All rights reserved.
//


#include "header.h"

//Initialisation VBO
void initVBO(void) {
	glShadeModel(GL_SMOOTH); 
	
	glGenBuffersARB(1, &Id_vbo);
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, Id_vbo);
	glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(sommets)+sizeof(normales)+sizeof(couleurs), 0, GL_STATIC_DRAW_ARB);
	// copie des tableaux (sommets,normales et couleurs)
	glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0, sizeof(sommets), sommets);
	glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, sizeof(sommets), sizeof(normales), normales);
	glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, sizeof(sommets)+sizeof(normales), sizeof(couleurs), couleurs);
}

//Dessiner le sol avec VBO
void drawSol(void) {
    
    glPushMatrix();
    
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, Id_vbo);
	
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	
	glNormalPointer(GL_FLOAT, 0, (void*)sizeof(sommets));
	glColorPointer(3, GL_FLOAT, 0, (void*)(sizeof(sommets)+sizeof(normales)));
	glVertexPointer(3, GL_FLOAT, 0, 0);
    
	glDrawArrays(GL_QUADS, 0, 4); // 4 == nb sommet d'une face
	
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
    
	glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
	
	glPopMatrix();
}

// Fonction pour effacer VBO apres utilisation
void deleteVBO(const GLuint Id_vbo) {
    glDeleteBuffersARB(1, &Id_vbo);
}