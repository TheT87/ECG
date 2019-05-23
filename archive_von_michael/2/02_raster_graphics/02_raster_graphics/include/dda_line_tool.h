//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2015 CGV TU Dresden - All Rights Reserved
//
/*************************************************************************
DDA-Line tool.
This class is inherited from "abstract_tool" to define a tool for drawing
lines using the DDA algorithm on a canvas_store. 
Read the information in "abstract_tool.h" for more information.
*************************************************************************/
#pragma once

// provides the declaration of the super class abstract_tool
#include "abstract_tool.h"

class dda_line_tool: public abstract_tool
{
public:
	// Initialize the tool and store a reference of a canvas_store
	dda_line_tool(canvas_store &canvas);

	// Draw a line from (x0, y0) to (x1, y1)
	void draw(int from_x, int from_y, int to_x, int to_y);

	// Put debug output into the stream "stream" to be displayed in the
	// main window
	void set_text(stringstream& stream);
};