//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2016 CGV TU Dresden - All Rights Reserved
//
#include "dda_line_tool.h"
#include <algorithm>
#include <math.h>



// Initialize the tool and store a reference of a canvas_buffer
dda_line_tool::dda_line_tool(canvas_buffer& canvas): tool_base(canvas)
{
	shape = TS_LINE;
}




// Draw a line from (x0, y0) to (x1, y1)
void dda_line_tool::draw(int x0, int y0, int x1, int y1)
{
	/************
	Aufgabe 3.1.1. Implementieren Sie den DDA-Algorithmus um eine Linie von
	               (x0, y0) nach (x1, y1) zu rastern. Verwenden Sie
				   "canvas.set_pixel(x, y)" um einen Pixel zu setzen, wobei
				   "x" und "y" den gewünschten Pixelpositionen entsprechen.
				   Diese Methode behandelt auch Randverletzungen. Stellen Sie zunaechst
				   den Standardfall her. Falls Sie den Wert zweier Variablen vertauschen
				   muessen koennen Sie dafür die Methode "std::swap(a, b)" verwenden.
   *************/
	int i;
	float q, x, y,dx,dy,step;

	if (x0>x1&&y0>y1)
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}

	x = x0;
	y = y0;
	dy = (y1 - y0);
	dx = (x1 - x0);

	if (abs(dx) >= abs(dy))
	{
		step = abs(dx);
	}
	
	else
	{
		step = abs(dy);
	}
	
	dx = dx / step;
	dy = dy / step;
	i = 0;

	while (i <= step)
	{ 
		canvas.set_pixel(x, y);
		x = x + dx;
		y = y + dy;
		i++;
	}






}




// Put debug output into the stream "stream" to be displayed in the
// main window
void dda_line_tool::set_text(std::stringstream& stream)
{
	stream<<"Tool: DDA-Line (click and drag mouse to draw)";
}