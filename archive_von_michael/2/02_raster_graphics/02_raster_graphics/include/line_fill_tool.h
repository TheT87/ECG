//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2015 CGV TU Dresden - All Rights Reserved
//
/*************************************************************************
Line-fill tool.
This class is inherited from "abstract_tool" to define a tool for filling
shapes using the scan line algorithm on a canvas_store. 
Read the information in "abstract_tool.h" for more information.
*************************************************************************/
#pragma once

// provides the declaration of the super class abstract_tool
#include "abstract_tool.h"
// needed for a double ended queue
#include <deque>


using namespace std;

// A line to be filled
struct waiting_line {
	int x, y; 
};



class line_fill_tool: public abstract_tool
{
public:
	// Initialize the tool and store a reference of a canvas_store
	line_fill_tool(canvas_store &canvas);

	// Fill the shape that contains the point (x, y)
	void draw(int x, int y);

	// Put debug output into the stream "stream" to be displayed in the
	// main window
	void set_text(stringstream& stream);
};