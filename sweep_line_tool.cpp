#include "sweep_line_tool.h"
#include <algorithm>

sweep_line_tool	::sweep_line_tool(canvas_buffer & canvas) : tool_base(canvas)
	{
		shape = TS_NONE;
	}

void sweep_line_tool::draw(int x0, int y0, int x1, int y1)
{

}



void sweep_line_tool::set_text(std::stringstream& stream) 
{
	stream << "Tool: Sweepline Triangle";
}