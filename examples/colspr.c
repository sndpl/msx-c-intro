#include <stdio.h>
#include <msxalib.h>
#include <msxclib.h>

char Ptspr0[32] = {
	0x04, 0x72, 0xfa, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe,
	0x72, 0x1a, 0x36, 0x76, 0x7e, 0x7c, 0xd8, 0x80,
	0x40, 0x9c, 0xbe, 0x7e, 0xfe, 0xfe, 0xfe, 0xfe,
	0x9c, 0xb0, 0xd8, 0xdc, 0xfc, 0x7c, 0x36, 0x02
};

char Ptspr1[32] = {
	0x00, 0x00, 0x20, 0x01, 0x43, 0x01, 0x01, 0x41,
	0x0d, 0x05, 0x09, 0x28, 0x00, 0x10, 0x00, 0x00,
	0x00, 0x00, 0x08, 0x00, 0x84, 0x00, 0x00, 0x04,
	0x60, 0x40, 0x20, 0x28, 0x00, 0x10, 0x00, 0x00
};

char Clspr0[16] = {
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 8
};

char Clspr1[16] = {
	12+64,12+64,12+64,12+64,12+64, 6+64, 6+64,12+64,
	12+64,12+64,12+64,12+64,12+64,12+64,12+64,12+64
};

int Xpos[12], Ypos[12];

VOID move()
{
	int i, x, y;

	for (i = 0; i < 12; ++i) {
		x = Xpos[i] + rnd(3) - 1;
		y = Ypos[i] + rnd(3) - 1;
		if (x < 0) x = 0;
		if (x > 240) x = 240;
		if (y < -1) y = -1;
		if (y > 195) y = 195;
		putspr(i * 2, x, y, 0, 0);
		putspr(i * 2 + 1, x, y, 0, 4);
		Xpos[i] = x;
		Ypos[i] = y;
	}
}

VOID main()
{
	int i;

	srnd();
	ginit();
	color(15, 10, 10);
	palett(13, 4, 7, 5);
	screen(5);
	inispr(2);
	sprite(0, Ptspr0);
	sprite(4, Ptspr1);

	for (i = 0; i < 12; ++i) {
		Xpos[i] = rnd(120) + 60;
		Ypos[i] = rnd(120) + 38;
		colspr(i * 2, Clspr0);
		colspr(i * 2 + 1, Clspr1);
	}

	while (!kbhit()) {
		move()
		for (i = 0; i < 400; ++i);
	}

    color(15, 1, 1);
    palett(13, 6, 2, 5);
    screen(0);
}
