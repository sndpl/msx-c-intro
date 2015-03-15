#include <stdio.h>
#include <msxalib.h>
#include <msxclib.h>

#define T32CGP *((int *)0xf3c1)

VOID main()
{
	char data[8];
	int i, j;

	ginit();
	screen(1);
	ldirmv(data, T32CGP + 'A' * 8, 8);

	for (i = 0; i < 8; ++i) {
		for (j = 0; j < 8; ++j) {
			if ((data[i] & 0x80) == 0)
				putchar(' ');
			else 
				putchar('A');
			data[i] <<= 1;
		}
		putchar('\n');
	}
	getch();
	screen(0);
}