//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2016 CGV TU Dresden - All Rights Reserved
//
#include "line_fill_tool.h"
#include <deque>
#include <iostream>

// Initialize the tool and store a reference of a canvas_buffer
line_fill_tool::line_fill_tool(canvas_buffer& canvas) : tool_base(canvas)
{
	// This tool has no shape and is not draggable
	shape = TS_NONE;
	is_draggable = false;
}

struct waiting_pixel {
	int x, y;
};



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

	waiting_pixel p;
	std::deque<waiting_pixel> stack;

	// init pixel
	if (!canvas.get_pixel(x, y)) {
		p.x = x;
		p.y = y;
		canvas.set_pixel(p.x, p.y);
		stack.push_back(p);
	}


	// while stack has pixels
	while (!stack.empty())
	{
		int cur_x = stack.front().x;
		int cur_y = stack.front().y;

		if (!canvas.get_pixel(cur_x + 1, cur_y))
		{
			canvas.set_pixel(cur_x + 1, cur_y);
			p.x = cur_x + 1;
			stack.push_back(p);
		}

		stack.pop_front();

	}

	/*


	if (!canvas.get_pixel(x - 1, y) && (x > 0 && x < canvas.get_width() - 1))
	{
		canvas.set_pixel(x - 1, y);

		if ((0 < y < canvas.get_height() - 1) && !canvas.get_pixel(x - 1, y - 1))
		{
			draw(x, y - 1);

			canvas.set_pixel(x, y);
			if (!canvas.get_pixel(x - 1, y) && (x > 0 && x < canvas.get_width() - 1))
			{
				draw(x - 1, y);
			}
			else
			{
				if (!canvas.get_pixel(x, y + 1))
				{
					draw(x, y + 1);
				}
				if (!canvas.get_pixel(x, y - 1))
				{
					draw(x, y - 1);
				}
				else
				{
					if (!canvas.get_pixel(x, y - 1))
					{
						draw(x, y - 1);
					}
				}
			}

			if (!canvas.get_pixel(x + 1, y) && (x > 0 && x < canvas.get_width() - 1))
			{
				draw(x + 1, y);
			}
			else
			{
				if (!canvas.get_pixel(x, y + 1))
				{
					draw(x, y + 1);
				}
				if (!canvas.get_pixel(x, y - 1))
				{
					draw(x, y - 1);
				}
				else
				{
					if (!canvas.get_pixel(x, y - 1))
					{
						draw(x, y - 1);
					}
				}
			}
			draw(x + 1, y);
		}
	}

	*/
}
// Put debug output into the stream "stream" to be displayed in the
// main window
void line_fill_tool::set_text(stringstream & stream)
{
	stream << "Tool: Line Fill (click to fill)";
}