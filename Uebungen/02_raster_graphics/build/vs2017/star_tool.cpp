#include "star_tool.h"
#include "canvas_buffer.h"
#include <iostream>
#include <vector>
#include <math.h>
#include "bresenham_line_tool.h"

using std::vector;

// == init ==
star_tool::star_tool(canvas_buffer& canvas) : tool_base(canvas)
{
	shape = TS_CIRCLE;
}

void star_tool::draw(int x0, int y0, int x1, int y1) {

	bresenham_line_tool line_tool(canvas);

	// sorry lulz. will be in context menu later
	int or = static_cast<int>(sqrt(static_cast<double>((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1))));
	int ir = or/2;
	int spikes = 5;


	int c = 0;
	int cr;	// current radius
	
	vector<int> verts;

	for (int i = 0; i < spikes * 2; i++) {	
		cr = (c % 2 == 0) ? ir : or ;

		int x = x0 + cr * cos(360 * i / (spikes * 2));
		// add to vector here
		verts.push_back(x);
		i++;
		int y = y0 + cr * sin(360 * (i - 1) / (spikes * 2));
		// add to vector here
		verts.push_back(y);
		c++;
	}

	std::cout << verts.at(0);

	while (!verts.empty)
	{
		line_tool.draw(verts.pop_back, verts.pop_back, verts.pop_back, verts.pop_back);
	}


}

void star_tool::set_text(std::stringstream& stream) {
	stream << "Tool: Star Tool";
}
