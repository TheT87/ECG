//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2016 CGV TU Dresden - All Rights Reserved
//
#include "cube_system_split.h"


// Render the scene
void cube_system_split::render()
{
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);

	// Calculate the aspect ratio for use in glOrtho
	double aspect = width/static_cast<double>(height);

	// Enable depth testing
	glEnable(GL_DEPTH_TEST);

	// Save the current view port
	glPushAttrib(GL_VIEWPORT_BIT);

	// Clear the screen
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	/********
	Additional Task: Render the cube system in 4 small screens. Three of them
	                 shall be orthographic projections of the main layers while
					 the fourth is a perspective projection. Take care that
					 no content from one window renders above its area. The
					 width and height of the window is stored in the variables
					 "width" and "height". Do not remove any code from this method.
	Zusatzaufgabe:   Rendern Sie das Wuerfelsystem in 4 kleinen Bildschirmen.
	                 Drei von ihnen sollen orthographische Projektionen der Haupt-
					 eben und eine soll eine perspektivische Projektion sein. 
					 Achten Sie darauf, dass der Inhalt der Fenster nicht ueber seinen
					 Bereich hinausrendert. Die Hoehe und Breite des Gesamtfensters
					 ist in den Variablen "width" und "height" gespeichert. Entfernen
					 Sie keinen Code aus dieser Methode.
     ***********/


	
	glColor3f(1.0f, 0.0f, 0.0f);

	// GL_PROJECTION
	// GL_MODELVIEW

	// top left		<- XY
	glColor3f(1.0f, 0.0f, 0.0f);


	GLfloat dist = 15.0f;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, aspect, 0.01f, 100.0f);
	// the three lines that cost qarter a day
	// why should anybody take a 1 minute look into script if 
	// you can "not-find" it in the internet for hours?!?!? 


	glMatrixMode(GL_MODELVIEW);
	glViewport(0, height / 2, width / 2, height / 2);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, dist,
			  0.0f, 0.0f, 0.0f,
			  0.0f, 1.0f, 0.0f);

	// glutWireTeapot(0.3f);
	cube_system::render_system();


	// top right	<- YZ
	glColor3f(1.0f, 0.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	glViewport(width / 2, height / 2, width / 2, height / 2);
	glLoadIdentity();
	gluLookAt(dist, 0.0f, 0.0f, 
			  0.0f, 0.0f, 0.0f, 
		      1.0f, 1.0f, 0.0f);
	//glutWireTeapot(0.3f);
	cube_system::render_system();

	// bottom left	<- XZ top view								<<<<< use gluOrthoAt
	glViewport(0, 0, width / 2, height / 2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	/*
	gluLookAt(1.0f, 0.0f, 1.0f, 
			  0.0f, 0.0f, 0.0f, 
			  0.0f, 1.0f, 0.0f);
	*/
	glOrtho(-dist, dist, -dist, dist, -10.0f, 100.0f);
	//glutWireTeapot(0.3f);
	cube_system::render_system();

	// bottom right
	glColor3f(1.0f, 0.0f, 0.0f);
	glMatrixMode(GL_MODELVIEW);
	glViewport(width / 2, 0, width / 2, height / 2);
	glLoadIdentity();
	gluLookAt(dist, dist, 0.0f, 
			  0.0f, 0.0f, 0.0f, 
			  0.0f, 1.0f, 0.0f);

	//glutWireTeapot(0.3f);
	cube_system::render_system();






	// Restore the old view port
	glPopAttrib();

	// Render split screen lines to span the whole window.
	// For this the projection matrix and modelview matrix is
	// set to the identity matrix. This ensures that the window
	// area always ranges from -1 to 1 in X and Y. The Z-direction
	// is omitted.
	// After that a cross is rendered
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	// Do not perform depth testing
	glDisable(GL_DEPTH_TEST);

	// Render a cross in gray
	glColor3d(0.5, 0.5, 0.5);
	glLineWidth(1.0);
	glBegin(GL_LINES);
	glVertex2d(0, -1);
	glVertex2d(0, 1);
	glVertex2d(-1, 0);
	glVertex2d(1, 0);
	glEnd();



}



// Set debug text
void cube_system_split::set_text(std::stringstream &stream)
{
	stream<<"Cube system (top left: XY, top right: YZ, bottom left: XZ, bottom right: perspective)";
}