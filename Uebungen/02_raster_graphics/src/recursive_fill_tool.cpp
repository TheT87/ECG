//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2016 CGV TU Dresden - All Rights Reserved
//
#include "recursive_fill_tool.h"

// Initialize the tool and store a reference of a canvas_buffer
recursive_fill_tool::recursive_fill_tool(canvas_buffer& canvas): tool_base(canvas)
{
	// This tool has no shape and is not draggable
	shape = TS_NONE;
	is_draggable = false;
}



// Fill the shape that contains the point (x, y)
void recursive_fill_tool::draw(int x, int y)
{
	/************
    Aufgabe 3.2.1. Implementieren Sie den rekursiven F�llalgorithmus, indem Sie den
	               Zustand der Nachbarpixel �berpr�fen (mittels "canvas.get_pixel(x, y)"
				   wobei "x" und "y" die Position des zu �berpr�fenden Pixels definieren)
				   und rufen Sie rekursiv die "draw"-Methode auf, wenn die Pixel nicht 
				   gesetzt sind. Ein Pixel kann durch "canvas.set_pixel(x, y)" gesetzt
				   werden.
	*************/
	
	if (canvas.get_pixel(x, y) == false)
	{
		canvas.set_pixel(x, y);
	}
	
	//oben
	if (canvas.get_pixel(x, y - 1) == false && (y>0))
	{
		canvas.set_pixel(x, y - 1);
		draw(x, y - 1);
	}

	//unten
	if (canvas.get_pixel(x, y + 1) == false && (y<99))
	{
		canvas.set_pixel(x, y + 1);
		draw(x, y + 1);
	}

	//links
	if (canvas.get_pixel(x - 1, y) == false && (x>0))
	{
		canvas.set_pixel(x - 1, y);
		draw(x - 1, y);
	}
	
	//rechts
	if (canvas.get_pixel(x + 1, y) == false && (x<99))
	{
		canvas.set_pixel(x + 1, y);
		draw(x + 1, y);
	}

}



// Put debug output into the stream "stream" to be displayed in the
// main window
void recursive_fill_tool::set_text(std::stringstream& stream)
{
	
	stream<<"Tool: Recursive Fill (click to fill)";
}