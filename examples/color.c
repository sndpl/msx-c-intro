#include <stdio.h>
#include <msxclib.h>

VOID main()
{
	int i, j, k;

	screen(1);

	for (i = 1; i <= 15; ++i) {
		for (j = 1; j <= 15; ++j) {
			color(15, j, i);
			for (k = 0; k < 18000; ++k);
		}
	}
	color (15, 1, 1);
	screen(0);
}