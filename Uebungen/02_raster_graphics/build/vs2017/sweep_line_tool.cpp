#include "sweep_line_tool.h"
#include "bresenham_line_tool.h"
#include <algorithm>
#include <iostream>

sweep_line_tool::sweep_line_tool(canvas_buffer& canvas) : tool_base(canvas)
{
	shape = TS_NONE;
}

struct vertex {
	int x, y;
};

void sweep_line_tool::draw(int x0, int y0, int x1, int y1)
{
	int p1_1 = 20, p1_2 = 10;
	int p2_1 = 70, p2_2 = 40;
	int p3_1 = 50, p3_2 = 50;

	bresenham_line_tool lines(canvas);

	if (p1_2 > p2_2)
	{
		std::swap(p1_1, p2_1);
		std::swap(p1_2, p2_2);
	}

	if (p2_2 > p3_2)
	{
		std::swap(p2_1, p3_1);
		std::swap(p2_2, p3_2);
	}
	if (p1_2 > p3_2)
	{
		std::swap(p1_1, p3_1);
		std::swap(p1_2, p3_2);
	}

	if (p2_2 == p3_2)
	{
		float invslope_2to1 = (p2_1 - p1_1) / (p2_2 - p1_1);
		float invslope_3to1 = (p3_1 - p1_1) / (p3_2 - p1_1);

		float curx1 = p1_1;
		float curx2 = p1_1;

		for (int scanlineY = p1_2; scanlineY <= p2_2; scanlineY++)
		{
			lines.draw((int)curx1, scanlineY, (int)curx2, scanlineY);
			curx1 += invslope_2to1;
			curx2 += invslope_3to1;
		}
	}
	else
	{
		if (p1_2 == p2_2)
		{
			float invslope_3to1 = (p3_1 - p1_1) / (p3_2 - p1_2);
			float invslope_3to2 = (p3_1 - p2_1) / (p3_2 - p2_2);

			float curx1 = p3_1;
			float curx2 = p3_1;

			for (int scanlineY = p3_2; scanlineY > p1_2; scanlineY--)
			{
				lines.draw((int)curx1, scanlineY, (int)curx2, scanlineY);
				curx1 -= invslope_3to1;
				curx2 -= invslope_3to2;
			}
		}
		else
		{
			int p4_1 = (p1_1 + ((float)(p2_2 - p1_2) / (float)(p3_2 - p1_2)) * (p3_1 - p1_1));
			int p4_2 = p2_2;

			// vt1, vt2, v4

			float invslope_2to1 = (p2_1 - p1_1) / (p2_2 - p1_1);
			float invslope_4to2 = (p4_1 - p1_1) / (p4_2 - p1_1);

			float curx1 = p1_1;
			float curx2 = p1_1;

			for (int scanlineY = p1_2; scanlineY <= p2_2; scanlineY++)
			{
				lines.draw((int)curx1, scanlineY, (int)curx2, scanlineY);
				curx1 += invslope_2to1;
				curx2 += invslope_4to2;
			}

			//vt2, v4, vt3
			//v1 - v2  v2 - v4 

			
			float invslope_3to2 = (p3_1 - p2_1) / (p3_2 - p2_2);
			float invslope_3to4 = (p3_1 - p4_1) / (p3_2 - p4_2);

			float curx1_2 = p3_1;
			float curx2_2 = p3_1;

			for (int scanlineY = p3_2; scanlineY > p2_2; scanlineY--)
			{
				lines.draw((int)curx1_2, scanlineY, (int)curx2_2, scanlineY);
				curx1_2 -= invslope_3to2;
				curx2_2 -= invslope_3to4;
			}

			
		}


	}


}



void sweep_line_tool::set_text(std::stringstream& stream)
{
	stream << "Tool: Sweepline Triangle";
}
