#include <stdio.h>
#include <msxclib.h>

char ptspr0[32] = {
	0x00, 0x03, 0x03, 0x13, 0x13, 0x16, 0x14, 0x3d,
	0x3c, 0x35, 0x75, 0x75, 0x7c, 0x7e, 0x77, 0x33,
	0x80, 0xc0, 0xc0, 0xc8, 0xc8, 0x68, 0x28, 0x3c,
	0x3c, 0x2c, 0x2e, 0x2e, 0x3e, 0x7e, 0xee, 0xcc
};

int Ytrns[9] = { 0, -64, -45,  0, 45, 64,  45,   0, -45};
int Xtrns[9] = { 0,   0,  45, 64, 45,  0, -45, -64, -45};

VOID move()
{
	static int x = 120 * 64;
	static int y = 120 * 64;
    int i;

    i  = gtstck(0) | gtstck(1);
    x += Xtrns[i];
    if (x >= 225 * 64)
    	x = 224 * 64;
    else if (x < 16 *64)
    	x = 16 * 64;

    y += Ytrns[i];
    if (y >= 165 * 64)
    	y = 164 * 64;
    else if (y < 28 * 64)
    	y = 28 * 64;

    putspr(0, x/64, y/64, 15, 0);
}

VOID main()
{
	int i;

	color(15, 1, 1);
	screen(1);
	inispr(2);
	sprite(0, ptspr0);
    while((snsmat(7) & 0x80) != 0) {
    	move();
    	for (i = 0; i < 500; ++i);
    }
    color(15, 0, 0);
    screen(0);
    kilbuf();
}
