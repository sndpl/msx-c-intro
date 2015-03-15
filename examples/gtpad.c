#include <stdio.h>
#include <msxalib.h>
#include <msxclib.h>

char Spr[8] = {
	0xfc, 0xf0, 0xf8, 0xfc, 0xbe, 0x9f, 0x0e, 0x04 
};

char Col[8] = {
	40, 40, 40, 40, 40, 40, 40, 40
};

int Cx = 128;
int Cy = 106;

VOID mouse()
{
	gtpad(12);
	Cx += gtpad(13);
	Cy += gtpad(14);
	if (Cx < 8) Cx = 8;
	if (Cx > 240) Cx = 240;
	if (Cy < 8) Cy = 8;
	if (Cy > 200) Cy = 200;
	putspr(0, Cx + 1, Cy, 0, 0);
}

VOID draw()
{
	int x, y;

	do {
		x = Cx;
		y = Cy;
		mouse();
		if (gttrig(1))
			line(Cx, Cy, x, y, 15, 0);
		if (gttrig(3))
			filvrm(0, 0x6a00, 0);
	} while ((snsmat(7) & 0x80) != 0);
}

VOID main()
{
	ginit();
	color(15, 1, 1);
	screen(5);
	inispr(0);
	sprite(0, Spr);
	colspr(0, Col);
	draw();
	screen(0);
	kilbuf();
}