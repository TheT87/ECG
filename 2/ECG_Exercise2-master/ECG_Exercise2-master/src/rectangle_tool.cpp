//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2015 CGV TU Dresden - All Rights Reserved
//
#include "rectangle_tool.h"
#include <algorithm>


// Initialize the tool and store a reference of a canvas_store
rectangle_tool::rectangle_tool(canvas_store& canvas): abstract_tool(canvas)
{
	shape = TS_BOX;
}



// Draw a box from (x0, y0) to (x1, y1)
void rectangle_tool::draw(int x0, int y0, int x1, int y1)
{
	/************
	Additional task: Implement the rasterization of a rectangle that
	                 ranges from (x0, y0) to (x1, y1).
    Zusatzaufgabe:   Implementieren Sie die Rasterisierung eines
	                 Rechtecks, das von (x0, y0) nach (x1, y1) geht.
	*************/
	if (x0 > x1)
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}
	int yincr = (y0 < y1) ? 1 : -1;
	for (int x_curr = x0; x_curr <= x1; x_curr++){
		canvas.set_pixel(x_curr, y0);
		canvas.set_pixel(x_curr, y1);
	}
	for (int y_curr = y0; y_curr != y1; y_curr += yincr)
	{
		canvas.set_pixel(x0, y_curr);
		canvas.set_pixel(x1, y_curr);
	}
}



// Put debug output into the stream "stream" to be displayed in the
// main window
void rectangle_tool::set_text(stringstream& stream)
{
	stream<<"Tool: Rectangle (click and drag mouse to draw)";
}