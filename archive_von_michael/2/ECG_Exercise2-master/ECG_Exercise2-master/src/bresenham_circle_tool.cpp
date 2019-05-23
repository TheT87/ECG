//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2015 CGV TU Dresden - All Rights Reserved
//
#include "bresenham_circle_tool.h"
#include <algorithm>
#include <math.h>

// Initialize the tool and store a reference of a canvas_store
bresenham_circle_tool::bresenham_circle_tool(canvas_store& canvas): abstract_tool(canvas)
{
	// This tool draws circles!
	shape = TS_CIRCLE;
}



// Draw a circle with center (x0, y0) and (x1, y1) on the circle
void bresenham_circle_tool::draw(int x0, int y0, int x1, int y1)
{
	// Calculate the radius
	int r = (int)sqrt((double)(x0-x1)*(x0-x1) + (y0-y1)*(y0-y1));

	/************
	Additional task: Implement circle rasterization using the bresenham algorithm.
	                 The circle shall have its center at (x0, y0) with a
					 radius of "r".
    Zusatzaufgabe:   Implementieren Sie die Rasterisierung eines Kreises mit dem
	                 Bresenham-Algorithmus. Der Kreis soll seinen Mittelpunkt bei
					 (x0, y0) und einen Radius von "r" haben.
	*************/
	int x = r;
	int y = 0;
	int error = 1 - x;

	while (x >= y)
	{
		canvas.set_pixel(x + x0, y + y0);
		canvas.set_pixel(y + x0, x + y0);
		canvas.set_pixel(-x + x0, y + y0);
		canvas.set_pixel(-y + x0, x + y0);
		canvas.set_pixel(-x + x0, -y + y0);
		canvas.set_pixel(-y + x0, -x + y0);
		canvas.set_pixel(x + x0, -y + y0);
		canvas.set_pixel(y + x0, -x + y0);
		y++;
		if (error <= 0)
		{
			error += 2 * y + 1;   
		}
		else
		{
			x--;
			error += 2 * (y - x) + 1;
		}
	}
}



// Put debug output into the stream "stream" to be displayed in the
// main window
void bresenham_circle_tool::set_text(stringstream& stream)
{
	stream<<"Tool: Bresenham-Circle (click and drag mouse to draw)";
}