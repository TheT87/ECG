//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2016 CGV TU Dresden - All Rights Reserved
//
#include "bresenham_circle_tool.h"
#include "bresenham_line_tool.h"
#include <algorithm>
#include <math.h>


// Initialize the tool and store a reference of a canvas_buffer
bresenham_circle_tool::bresenham_circle_tool(canvas_buffer& canvas): tool_base(canvas)
{
	// This tool draws circles!
	shape = TS_CIRCLE;
}



// Draw a circle with center (x0, y0) and (x1, y1) on the circle
void bresenham_circle_tool::draw(int x0, int y0, int x1, int y1)
{
	// Calculate the radius
	int r = static_cast<int>(sqrt(static_cast<double>((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1))));
	int d = 3 - 2 * r;
	int x = 0;
	int y = r;

	//Stellen an denen Kreisgleichung nicht definiert ist 
	canvas.set_pixel(x0, y0 + r);
	canvas.set_pixel(x0, y0 - r);
	canvas.set_pixel(x0 + r, y0);
	canvas.set_pixel(x0 - r, y0);


	while (x < y)
	{
		x++;

		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else 
		{
			d = d + 4 * x + 6;
		}
		
		
		// unten -> links unten
		canvas.set_pixel(x0 - x, y0 + y);
		// links unten -> links
		canvas.set_pixel(x0 - y, y0 + x);
		//links -> links oben
		canvas.set_pixel(x0 - y, y0 - x);
		// links oben -> oben
		canvas.set_pixel(x0 - x, y0 - y);
		// oben -> rechts oben
		canvas.set_pixel(x0 + x, y0 - y);
		// rechts oben -> rechts
		canvas.set_pixel(x0 + y, y0 - x);
		// rechts -> rechts unten
		canvas.set_pixel(x0 + y, y0 + x);
		// rechts unten -> unten
		canvas.set_pixel(x0 + x, y0 + y);
	}
	
}




// Put debug output into the stream "stream" to be displayed in the
// main window
void bresenham_circle_tool::set_text(std::stringstream& stream)
{
	stream<<"Tool: Bresenham-Circle (click and drag mouse to draw)";
}