//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2016 CGV TU Dresden - All Rights Reserved
//
#include "cube_system.h"

// Initialize variables
cube_system::cube_system()
{
	angle = 0;
}



// Setup the scene and render cube system
void cube_system::render()
{
	// Enable depth testing
	glEnable(GL_DEPTH_TEST);
	// Disable lighting
	glDisable(GL_LIGHTING);

	// Clear the screen and depth buffer
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set the projection and view
	setup_projection();

	// Render the system
	render_system();
}




// Advance one frame by increasing the rotation angle
void cube_system::advance_frame()
{
	// Increase angle and perform a modulo 360
	angle = (angle+1)%360;
}





// Render the cube system
void cube_system::render_system()
{
	//--"geliehen"--------------------------------------------
	// Save initial state
	glPushMatrix();

	// First branch of the transformation tree
	glRotated(angle, 0, 1, 0);
	render_cube();
	
	// Load initial state
	glPopMatrix();
	
	// Second branch
	glRotated(-angle, 0, 1, 0);
	glTranslated(5, 0, 0);
	glScaled(0.6, 0.6, 0.6);
	

	glPushMatrix();
	
	// First part
	glRotated((2 * angle), 0, 0, 1);
	glTranslated(3, 0, 0);
	glScaled(0.5, 0.5, 0.5);
	render_cube();
	
	// Load & save intermediate state
	glPopMatrix();
	glPushMatrix();
	
	// Second part
	render_cube();
	
	// Load intermediate state
	glPopMatrix();
	
	// Third part
	glRotated((2 * angle + 180), 0, 0, 1);
	glTranslated(3, 0, 0);
	glScaled(0.5, 0.5, 0.5);
	render_cube();
	
	//--"geliehen" ende----------------------------------------

	// Remove the following statement (if wanted) as it just serves 2.1.1.
	// Entfernen Sie die folgende Anweisung gegebenenfalls, da sie lediglich dem Testen
	// von Aufgabe 2.1.1 dient.
	//render_cube();
}





// Render one single cube
void cube_system::render_cube()
{
	/********
	Task 2.1.1.    Tesellate a cube by specifying vertices and colors via the commands 
	               glVertex3d and glColor3d. Choose appropriate primitives (parameter to 
				   glBegin) and provide vertices and colors for all 6 sides. The cube shall 
				   range from (-1, -1, -1) to (1, 1, 1).
	Aufgabe 2.1.1. Tesellieren Sie einen Wuerfel, indem Sie Vertices und Farben mittels
	               der Kommandos glVertex3d und glColor3d spezifizieren. Waehlen Sie
				   zunaechst das passende Zeichenprimitiv (Parameter von glBegin) und
                   erstellen Sie Vertices und Farben für alle 6 Seiten. Der Wuerfel soll
				   von (-1, -1, -1) bis (1, 1, 1) reichen.
	*********/	

	
	

	// Left
	glColor3d(0.14, 0.0, 1.0f);

	glBegin(GL_QUADS);
	glVertex3d(-1.0, -1.0, -1.0);
	glVertex3d(-1.0, -1.0, 1.0);
	glVertex3d(-1.0, 1.0, 1.0);
	glVertex3d(-1.0, 1.0, -1.0);
	glEnd();

	// Back
	glColor3d(0.95f, 0.15f, 0.0f);

	glBegin(GL_QUADS);
	glVertex3d(1.0, 1.0, 1.0);
	glVertex3d(1.0, -1.0, 1.0);
	glVertex3d(-1.0, -1.0, 1.0);
	glVertex3d(-1.0, 1.0, 1.0);

	glEnd();

	// Right
	glColor3d(0.0f, 0.95, 0.10);

	glBegin(GL_QUADS);
	glVertex3d(1.0, -1.0, -1.0);
	glVertex3d(1.0, 1.0, -1.0);
	glVertex3d(1.0, 1.0, 1.0);
	glVertex3d(1.0, -1.0, 1.0);
	glEnd();

	// Top
	glColor3d(0.75, 0.75, 0.75);

	glBegin(GL_QUADS);
	glVertex3d(1.0, 1.0, 1.0); 
	glVertex3d(-1.0, 1.0, 1.0);
	glVertex3d(-1.0, 1.0, -1.0);
	glVertex3d(1.0, 1.0, -1.0);
	glEnd();

	// Front // orange
	glColor3d(1.0, 0.15, 0.45);

	glBegin(GL_QUADS);
	glVertex3d(1.0, 1.0, -1.0);
	glVertex3d(-1.0, 1.0, -1.0);
	glVertex3d(-1.0, -1.0, -1.0);
	glVertex3d(1.0, -1.0, -1.0);
	glEnd();

	// Bottom
	glColor3d(0.85, 0.85, 0.0);

	glBegin(GL_QUADS);
	glVertex3d(1.0, -1.0, 1.0);
	glVertex3d(1.0, -1.0, -1.0);
	glVertex3d(-1.0, -1.0, -1.0);
	glVertex3d(-1.0, -1.0, 1.0);
	glEnd();


}




// Set the projection and the view
void cube_system::setup_projection()
{
	// For projection choose a perspective matrix with an aperture angle of
	// 45deg, an aspect ratio that corresponds to the width and height of the
	// window, z_near at 0.01 and z_far at 100.0
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, glutGet(GLUT_WINDOW_WIDTH) / static_cast<double>(glutGet(GLUT_WINDOW_HEIGHT)), 0.01, 100.0);

	// For the modelview matrix choose a view from the position (10.0, 6.0, -10.0) to
	// the position (0, 0, 0) where the up-direction is (0, 1, 0).
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(10.0,6.0,-10.0,  0,0,0,  0,1,0);
}



// Set debug text
void cube_system::set_text(std::stringstream &stream)
{
	stream<<"Showing cube system (with rotation parameter at "<<angle<<"°)";
}