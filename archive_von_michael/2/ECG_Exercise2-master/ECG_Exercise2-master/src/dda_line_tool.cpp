//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2015 CGV TU Dresden - All Rights Reserved
//
#include "dda_line_tool.h"
#include <algorithm>


// Initialize the tool and store a reference of a canvas_store
dda_line_tool::dda_line_tool(canvas_store& canvas): abstract_tool(canvas)
{
	shape = TS_LINE;
}




// Draw a line from (x0, y0) to (x1, y1)
void dda_line_tool::draw(int x0, int y0, int x1, int y1)
{
	/************
	Task 3.1.1.    Implement the DDA algorithm to raster a line from (x0, y0)
	               to (x1, y1). To set a pixel use "canvas.set_pixel(x, y)" where
				   "x" and "y" is the desired pixel position. This method 
				   handles border violations. Establish the standard case in the
				   first step. If you need to swap the value of two variables you
				   can use the method "std::swap(a, b)".
	Aufgabe 3.1.1. Implementieren Sie den DDA-Algorithmus um eine Linie von
	               (x0, y0) nach (x1, y1) zu rastern. Verwenden Sie
				   "canvas.set_pixel(x, y)" um einen Pixel zu setzen, wobei
				   "x" und "y" den gewünschten Pixelpositionen entsprechen.
				   Diese Methode behandelt auch Randverletzungen. Stellen Sie zunaechst
				   den Standardfall her. Falls Sie den Wert zweier Variablen vertauschen
				   muessen koennen Sie dafür die Methode "std::swap(a, b)" verwenden.
   *************/
	// Establish the standard case (line moves from left to right)
 	if (x0 > x1)
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}
	// Declare all necessary variables
	float x, y, dx, dy, xincr, yincr;
	int length;
	// The following variables are used to determine the slope of the line
	dx = x1 - x0;
	dy = y1 - y0;
	// Determines whether x or y grows faster (fast direction).
	// This also sets the number of steps needed to complete the line.
	if (std::abs(dx) >= std::abs(dy)) length = std::abs(dx); else length = std::abs(dy);
	/* Sets the values with which x and y are to be incremented. 
	 * Note: one of these will always be 1. If x is the leading direction, y will be incremented with m = dy / dx,
	 * if y is the leading direction x will be incremented with 1 / m. 
	 */
	xincr = (dx / (float) length);
	yincr = (dy / (float) length);
	// Draws the first point of the rasterized line
	x = x0;
	y = y0;
	canvas.set_pixel(x, y);
	/* Main loop of the algorithm:
	 * 1. Increments x with the proper value.
	 * 2. Increments y with the proper value.
	 * 3. Rounds both values (as they are floating point values) and draws the point determined by them.
	 * The loop exits when the length of the line has been reached.
	 */
	for (int i = 1; i <= length; i++)
	{
		x += xincr;
		y += yincr;
		canvas.set_pixel(std::round(x), std::round(y));
	}
}

// Put debug output into the stream "stream" to be displayed in the
// main window
void dda_line_tool::set_text(stringstream& stream)
{
	stream<<"Tool: DDA-Line (click and drag mouse to draw)";
}