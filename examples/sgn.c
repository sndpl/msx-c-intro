#include <stdio.h>
#include <msxalib.h>
#include <msxclib.h>

VOID plot(x, y, ch)
int x, y, ch;
{
	printf("\33Y%c%c%c\n", y+32, x+32, ch);
}

VOID main()
{
	int x, y, c;

	srnd();
	puts("\33x5\f");

	for (c = 'A'; c <= 'Z'; ++c) {
		x = rnd(40);
		y = rnd(22);
		do {
			plot(x, y, ' ');
			x += sgn(20 - x);
			y += sgn(10 - y);
			plot(x, y, c);
		} while (x != 20 || y != 10);
	}
}