#pragma once
#include "tool_base.h"

class sweep_line_tool :public tool_base
{
public:
	sweep_line_tool(canvas_buffer& canvas);

	void sweep_line();

	void set_text(std::stringstream& stream);
};

