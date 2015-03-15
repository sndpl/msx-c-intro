#include <stdio.h>
#include <msxclib.h>

VOID main()
{
	static int datapsg[14] = {
		55, 0, 0, 0, 0, 0, 29, 54,
		16, 0, 0, 116, 1, 12 };
	
	int i;

	gicini();

	for (i = 0; i < 14; ++i) {
		sound(i, datapsg[i]);
	}

	getch();
	gicini();
}