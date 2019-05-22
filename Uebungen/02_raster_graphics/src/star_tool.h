#pragma once

#include "tool_base.h"

class star_tool : public tool_base
{
public:
		star_tool(canvas_buffer& canvas);

		void draw(int x0, int y0, int x1, int y1);

		void set_text(std::stringstream& stream);
};