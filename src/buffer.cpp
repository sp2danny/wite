
#include "buffer.h"

void Buffer::performAdorn()
{
	for (auto&& ln : buffer)
	{
		std::size_t i, n = ln.plain_line.size();
		ln.line.resize(n);
		for (i=0; i<n; ++i)
		{
			line[i] = { plain_line[i], false, false, ccBlack };
		}
	}
	if (!has_mark) return;
	
	if (!block_mark)
	{
		std::size_t x, y, xm, ym;
		y = mark_in.y;
		x = mark_in.x;
		ym = buffer.size();
		while (true)
		{
			if (y >= ym) break;
			xm = buffer[y].size();
			bool onll = y = mark_out.y;
			while (true)
			{
				if (x >= xm) break;
				if (onll && (x>mark_out.x)) break;
				buffer[y].line[x].mark = true;
				++x;
			}
			++y; x=0;
		}
	} else {
	}
}
