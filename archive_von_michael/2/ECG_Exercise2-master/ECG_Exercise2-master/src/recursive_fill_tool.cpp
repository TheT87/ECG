//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2015 CGV TU Dresden - All Rights Reserved
//
#include "recursive_fill_tool.h"
#include <iostream>

// Initialize the tool and store a reference of a canvas_store
recursive_fill_tool::recursive_fill_tool(canvas_store& canvas): abstract_tool(canvas)
{
	// This tool has no shape and is not draggable
	shape = TS_NONE;
	is_draggable = false;
}



// Fill the shape that contains the point (x, y)
void recursive_fill_tool::draw(int x, int y)
{
	/************
	Task 3.2.1.    Implement the recursive fill algorithm by checking the
	               state of the neighbouring pixels (via "canvas.get_pixel(x, y)"
				   where "x" and "y" defines the position to check) and recursively
				   call "draw" if the pixel is not set. A pixel can be set with
				   "canvas.set_pixel(x, y)".
				   This method will make the application crash if the area which shall 
				   be filled is too big.
    Aufgabe 3.2.1. Implementieren Sie den rekursiven Füllalgorithmus, indem Sie den
	               Zustand der Nachbarpixel überprüfen (mittels "canvas.get_pixel(x, y)"
				   wobei "x" und "y" die Position des zu überprüfenden Pixels definieren)
				   und rufen Sie rekursiv die "draw"-Methode auf, wenn die Pixel nicht 
				   gesetzt sind. Ein Pixel kann durch "canvas.set_pixel(x, y)" gesetzt
				   werden.
	*************/

	static int rec_depth = -1;
	static int max_rec_depth = 0;

	rec_depth++;

	if (rec_depth > max_rec_depth) max_rec_depth = rec_depth;

	if (x < 0 || y < 0 || x >= canvas.get_width() || y >= canvas.get_height()) return;

	canvas.set_pixel(x, y);

	if (!canvas.get_pixel(x, y + 1)) draw(x, y + 1); //up
	if (!canvas.get_pixel(x + 1, y)) draw(x + 1, y); //right
	if (!canvas.get_pixel(x, y - 1)) draw(x, y - 1); //down
	if (!canvas.get_pixel(x - 1, y)) draw(x - 1, y); //left

	if (rec_depth == 0)
	{
		std::cout << max_rec_depth << std::endl;
		max_rec_depth = 0;
		rec_depth = -1;
	}
	else rec_depth--;
}



// Put debug output into the stream "stream" to be displayed in the
// main window
void recursive_fill_tool::set_text(stringstream& stream)
{
	stream<<"Tool: Recursive Fill (click to fill)";
}