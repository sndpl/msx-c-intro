#include <stdio.h>
#include <msxalib.h>
#include <msxclib.h>
#include "hipman.h"
#pragma nonrec
#define T32NAM  *((int *)0xf3bd)
#define T32COL  *((int *)0xf3bf)
#define T32CGP  *((int *)0xf3c1)

extern TINY Maze[23][25];
extern int  Dot;

static char Font[48] = {
    0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x50, 0xe0, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x00 };

static char Spr[32] = {
    0x00, 0x00, 0x03, 0x0f, 0x1f, 0x33, 0x27, 0x7f,
    0x4f, 0x4f, 0x4f, 0x4f, 0x27, 0x3f, 0x1e, 0x00,
    0x00, 0x00, 0xe0, 0xf8, 0xfc, 0xfe, 0xfe, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x7e, 0x7e, 0x3c, 0x00 };

static char Ptnmaze[23][26] = {
    "deeeeefdeeeeeeeeefdeeeeef",
    "fhhhhiffhhhhhhhhhffihhhhf",
    "fhdefhffhdeeeeefhffhdefhf",
    "fheeghegheef deghegheeghf",
    "fhhhhhhhhhhf fhhhhhhhhhhf",
    "eefhdeeeefhf fhdeeeefhdeg",
    "degheeeeegheegheeeeegheef",
    "fhhhhhhhhhhhhhhhhhhhhhhhf",
    "fhdfhdfhdeefhdeefhdfhdfhf",
    "fhffhffhfdegheeffhffhffhf",
    "fhffhffhffhhhhhffhffhffhf",
    "fhffhegheghdefhegheghffhf",
    "fhffhhhhhhhf fhhhhhhhffhf",
    "fhfeefhdfhdg efhdfhdegfhf",
    "fheeeghegheeeeghegheeeghf",
    "fhhhhhhhhhhh hhhhhhhhhhhf",
    "eeefhdeeefhdefhdeeefhdeeg",
    "deeghfdeeghf fheeeffheeef",
    "fhhhhffihhhf fhhhiffhhhhf",
    "fhdfhffhdeeg eeefhffhdfhf",
    "fheghegheeeeeeeeghegheghf",
    "fhhhhhhhhhhhhhhhhhhhhhhhf",
    "eeeeeeeeeeeeeeeeeeeeeeeeg" };

VOID drawmaze()
{
    int i, j;
    TINY m;

    for (j = 0; j < 23; ++j)
	ldirvm(T32NAM + (j + 1) * 32 + 1, Ptnmaze[j], 25);

    Dot = 0;
    for (j = 0; j < 23; ++j) {
	for (i = 0; i < 25; ++i) {
	    switch (Ptnmaze[j][i]) {
	     case ' ': m = SPACE; break;
	     case 'd':
	     case 'e':
	     case 'f':
	     case 'g': m = WALL; break;
	     case 'h': m = DOT;  ++Dot; break;
	     case 'i': m = CHIP; ++Dot; break;
	    }
	    Maze[j][i] = m;
	}
    }
}

VOID init()
{
    color(15, 1, 1);
    screen(1);
    ldirvm(T32CGP + 100 * 8, Font, 48);
    vpoke(T32COL + 12, 0x41);
    vpoke(T32COL + 13, 0xb1);
    ldirvm(T32NAM + 26 +  1 * 32, "+---+", 5);
    ldirvm(T32NAM + 26 +  2 * 32, "+HIP+", 5);
    ldirvm(T32NAM + 26 +  3 * 32, "+MAN+", 5);
    ldirvm(T32NAM + 26 +  4 * 32, "+---+", 5);
    ldirvm(T32NAM + 26 +  7 * 32, "SCORE", 5);
    ldirvm(T32NAM + 26 + 13 * 32, "REST", 4);
    ldirvm(T32NAM + 26 + 19 * 32, "STAGE", 5);
    drawmaze();
    inispr(2);
    sprite(0, Spr);
}


