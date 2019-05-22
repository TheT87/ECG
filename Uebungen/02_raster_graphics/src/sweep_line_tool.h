#pragma once
#include "tool_base.h"

class sweep_line_tool :public tool_base
{
public:
	sweep_line_tool(canvas_buffer& canvas);

//	void draw(Point p1, Point p2, Point p3);

	void sweep_line();

	void set_text(std::stringstream& stream);
};

