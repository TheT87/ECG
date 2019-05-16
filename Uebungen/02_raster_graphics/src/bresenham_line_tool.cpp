//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2016 CGV TU Dresden - All Rights Reserved
//
#include "bresenham_line_tool.h"
#include <algorithm>
#include <math.h>

// Initialize the tool and store a reference of a canvas_buffer
bresenham_line_tool::bresenham_line_tool(canvas_buffer& canvas): tool_base(canvas)
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

	int dx = std::abs(x1 - x0);	// absolute, otherwise there was infinite counting in wrong direction
	int dy = (std::abs(y1 - y0)); // negative for e.g an angle between 180° and 360°
	int error = dx + dy;
	int current_error;

	int step_x = (x0 < x1 ? 1 : -1);
	int step_y = (y0 < y1 ? 1 : -1);

	canvas.set_pixel(x0, y0);
	while (!(x0 == x1 && y0 == y1)) {	// we need to check all of these since there are more cases than standard
		current_error = 2 * error;
		if (current_error > dy) {
			error += dy;
			x0 += step_x;
		}
		if (current_error < dx) {
			error += dx;
			y0 += step_y;
		}
		canvas.set_pixel(x0, y0);
	}
}




// Put debug output into the stream "stream" to be displayed in the
// main window
void bresenham_line_tool::set_text(std::stringstream& stream)
{
	stream<<"Tool: Bresenham-Line (click and drag mouse to draw)";
}
