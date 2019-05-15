//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2016 CGV TU Dresden - All Rights Reserved
//
#include "line_fill_tool.h"
#include <deque>


// Initialize the tool and store a reference of a canvas_buffer
line_fill_tool::line_fill_tool(canvas_buffer& canvas): tool_base(canvas)
{
	// This tool has no shape and is not draggable
	shape = TS_NONE;
	is_draggable = false;
}



// Fill the shape that contains the point (x, y)
void line_fill_tool::draw(int x, int y)
{
	/************
	Additional task: Implement the line fill algorithm. You can declare
	                 helper methods and properties in the header file if needed and
					 implement them here.
    Zusatzaufgabe:   Implementieren Sie den Line-Fill-Algorithmus. Falls benoetigt
	                 koennen Sie sich Helfermethoden in der dazugehoerigen Header-Datei
					 deklarieren und in dieser Datei definieren.
	*************/
}





// Put debug output into the stream "stream" to be displayed in the
// main window
void line_fill_tool::set_text(stringstream& stream)
{
	stream<<"Tool: Line Fill (click to fill)";
}