#include <stdio.h>
#include <msxalib.h>
#include <msxclib.h>

VOID erase()
{
	int i, j;

	for (i = 0; i <= 7; ++i) {
		for (j = i; j <= 211; j += 8)
			filvrm(j * 128, 128, (char)0);
		for (j = 0; j < 7000; ++j);
	}
}

VOID main()
{
	int i;

	ginit();
	srnd();
	color(15, 1, 1);
	screen(5);
	for (i = 0; i <= 40; ++i)
		boxfil(rnd(256),rnd(212),rnd(256),rnd(212),rnd(15),0);

	for(i = 0; i < 30000; ++i);
	erase();
	for(i = 0; i < 30000; ++i);
    screen(0);
}