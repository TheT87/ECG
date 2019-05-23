//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2015 CGV TU Dresden - All Rights Reserved
//
/*************************************************************************
Bresenham-Circle tool.
This class is inherited from "abstract_tool" to define a tool for drawing
circles using the bresenham algorithm on a canvas_store. 
Read the information in "abstract_tool.h" for more information.
*************************************************************************/
#pragma once

// provides the declaration of the super class abstract_tool
#include "abstract_tool.h"

class bresenham_circle_tool: public abstract_tool
{
public:
	// Initialize the tool and store a reference of a canvas_store
	bresenham_circle_tool(canvas_store &canvas);

	// Draw a circle with center (x0, y0) and (x1, y1) on the circle
	void draw(int x0, int y0, int x1, int y1);

	// Put debug output into the stream "stream" to be displayed in the
	// main window
	void set_text(stringstream& stream);
};