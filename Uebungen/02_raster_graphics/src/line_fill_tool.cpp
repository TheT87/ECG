//
// This source code is property of the Computer Graphics and Visualization 
// chair of the TU Dresden. Do not distribute in modified or unmodified form! 
// Copyright (C) 2016 CGV TU Dresden - All Rights Reserved
//
#include "line_fill_tool.h"
#include <deque>
#include <iostream>
#include <deque>

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

		if (canvas.get_pixel(cur_x - 1, cur_y) && canvas.get_pixel(cur_x, cur_y - 1) && canvas.get_pixel(cur_x + 1, cur_y) && canvas.get_pixel(cur_x, cur_y + 1))
		{
			stack.pop_front();
			continue;
		}

		if (!canvas.get_pixel(cur_x + 1, cur_y) && cur_x + 1 <= canvas.get_width())
		{
			canvas.set_pixel(cur_x + 1, cur_y);
			p.x = cur_x + 1;	// go to x direction
			stack.push_back(p);	// each visited pixel goes to stack
		}

		if (!canvas.get_pixel(cur_x - 1, cur_y) && cur_x - 1 >= 0)
		{
			canvas.set_pixel(cur_x - 1, cur_y);
			p.x = cur_x - 1;
			stack.push_back(p);
		}

		/*

		for (int i = 0; i < stack.size(); i++) {
			waiting_pixel wp = stack.at(i);
			if (canvas.get_pixel(wp.x, wp.y - 1))
			{
				cur_y--;
				while (canvas.get_pixel(cur_x, cur_y))
				{
					canvas.set_pixel(cur_x, cur_y);
					cur_x++;
					wp.x = cur_x;
					wp.y = cur_y;
					stack.push_back(wp);
				}
			}
		}

		*/


		stack.pop_front();

	}

	//////////////////////////////////////////////////////////////////////////////////////

	int xL, xR;
	if (y < 0 || y > canvas.get_height());
		return;
	for (xL = x; xL >= 0; --xL) { // scan left
		if (canvas.get_pixel(xL, y))
			break;
		canvas.set_pixel(xL, y);
	}

	if (xL < x) {
		draw(xL, y - 1); // fill child
		draw(xL, y + 1);
		++x;
	}

	for (xR = x; xR <= canvas.get_width(); ++xR) { // scan right
		if (canvas.get_pixel(xR, y))
			break;
		canvas.set_pixel(xR, y);
	}

	if (xR > x) {
		draw(xR, y - 1); // fill child
		draw(xR, y + 1);
		--x;
	}











	///////////////////////////////////////////////////////////////////////////////////////

	/*
	canvas.set_pixel(x, y);
	if (!canvas.get_pixel(x - 1, y) && (x - 1 >= 0))
	{
		draw(x - 1, y);
	}
	else
	{
		if (!canvas.get_pixel(x, y + 1) && (y + 1 < canvas.get_height()))
		{
			draw(x, y + 1);
		}
		//Possibility 1
		if (!canvas.get_pixel(x, y - 1) && (y - 1 >= 0))
		{
			draw(x, y - 1);
		}
	}

	if (!canvas.get_pixel(x + 1, y) && (x + 1 < canvas.get_width()))
	{
		draw(x + 1, y);
	} 
	else 
	{
		if (!canvas.get_pixel(x, y + 1) && (y + 1 < canvas.get_height()))
		{
			draw(x, y + 1);
		}
		//Possibility 1
		if (!canvas.get_pixel(x, y - 1) && (y - 1 >= 0))
		{
			draw(x, y - 1);
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
