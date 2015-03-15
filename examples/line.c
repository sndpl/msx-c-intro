#include <stdio.h>
#include <msxalib.h>
#include <msxclib.h>

VOID main()
{
	unsigned x1, y1, x2, y2, c, i, j;

	ginit();
	screen(5);
	color(15, 1, 1);
	x1 = 128;
	y1 = 106;
	c = 0;
	i = j = 1;

	while(!kbhit()) {
		x2 = 256 - x1;
		y2 = 212 - y1;
		line(x1, y1, x2, y1, c, 3);
		line(x1, y2, x2, y2, c, 3);
		line(x1, y1, x1, y2, c, 3);
		line(x2, y1, x2, y2, c, 3);
		if ((x1 += i) == 6 || x1 == 250) i = -i;
		if ((y1 += j) == 2 || y1 == 210) j = -j;
		if (++c == 16) c = 0;
	}

	screen(0);
}