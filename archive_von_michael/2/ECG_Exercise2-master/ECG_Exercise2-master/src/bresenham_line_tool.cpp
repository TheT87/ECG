//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2015 CGV TU Dresden - All Rights Reserved
//
#include "bresenham_line_tool.h"
#include <algorithm>
#include <math.h>

// Initialize the tool and store a reference of a canvas_store
bresenham_line_tool::bresenham_line_tool(canvas_store& canvas): abstract_tool(canvas)
{
	// This tool draws lines!
	shape = TS_LINE;
}




// Draw a line from (x0, y0) to (x1, y1)
void bresenham_line_tool::draw(int x0, int y0, int x1, int y1)
{
	/************
	Task 3.1.2.    Implement the Bresenham algorithm to raster a line from (x0, y0)
	               to (x1, y1). To set a pixel use "canvas.set_pixel(x, y)" where
				   "x" and "y" is the desired pixel position. This method 
				   handles border violations. Establish the standard case in the
				   first step. If you need to swap the value of two variables you
				   can use the method "std::swap(a, b)".
	Aufgabe 3.1.2. Implementieren Sie den Bresenham-Algorithmus um eine Linie von
	               (x0, y0) nach (x1, y1) zu rastern. Verwenden Sie
				   "canvas.set_pixel(x, y)" um einen Pixel zu setzen, wobei
				   "x" und "y" den gewünschten Pixelpositionen entsprechen.
				   Diese Methode behandelt auch Randverletzungen. Stellen Sie zunaechst
				   den Standardfall her. Falls Sie den Wert zweier Variablen vertauschen
				   muessen koennen Sie dafür die Methode "std::swap(a, b)" verwenden.
   *************/
	// Line goes from left to right (reduce to standard case)
	if (x0 > x1)
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}
	// Variables needed to establish the slope and error
	int dx = x1 - x0; 
	int dy = y1 - y0;
	// Y-value falls or grows? This will determine whether the y coordinate should be incremented or decremented. 
	// 1 - positive slope, -1 - negative slope
	int sign = (dy >= 0) ? 1 : -1;
	// Declare additional variables
	int x = x0, y = y0, error;
	/* The following if-else statement determines the "fast" direction.
	 * The algorithm's main loop is nested inside of it.
	 */
	if (std::abs(dx) >= std::abs(dy))
	{
		// First case - x axis is fast, initialize error
		error = 2*sign*dy - dx;
		// Begin loop. The error variable is used to make a decision in each iteration
		while (x <= x1)
		{
			canvas.set_pixel(x, y);
			if (error < 0) // error is small enough, do not increment y
			{
				error += 2*sign*dy;
			}
			else // increment y
			{
				y += sign;
				error += 2*(sign*dy - dx);
			}
			x++; // increment x in each iteration as it is the "fast" direction
		}
	}
	else
	{
		error = 2*sign*dx - dy; // analogically for y axis
		while (y != y1)
		{
			canvas.set_pixel(x, y);
			if (dy >= 0) // line moves from bottom to top
			{
				if (error <= 0) // error is small enough, do not increment x
				{
					error += 2*sign*dx;
				}
				else // increment x
				{
					x++;
					error += 2*(sign*dx - dy);
				}
			}
			else // line moves from top to bottom, following 2 cases are the same as above but with "mirrored" signs
			{
				if (error <= 0) // increment x
				{
					x++;
					error += 2*(sign*dx - dy);
				}
				else // no correction should be made
				{
					error += 2*sign*dx;
				}
			}
			y += sign; // y is the "fast" direction: add 1 or -1 depending on slope
		}
	}
	canvas.set_pixel(x1, y1);
}

// Put debug output into the stream "stream" to be displayed in the
// main window
void bresenham_line_tool::set_text(stringstream& stream)
{
	stream<<"Tool: Bresenham-Line (click and drag mouse to draw)";
}
