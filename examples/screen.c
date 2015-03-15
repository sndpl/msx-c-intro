#include <stdio.h>
#include <msxclib.h>

VOID main()
{
	screen(1);
	puts("SCREEN 1");
	getch();
	screen(0);
	puts("SCREEN 0");
}