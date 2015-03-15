#include <stdio.h>
#include <msxalib.h>

VOID _dmy1_() { }

VOID screen(md)
int md;
{
    struct regs r;

    r.a = (char)md;
    calbio(0x005f, &r);
}

VOID color(fg, bg, bd)
int fg, bg, bd;
{
    struct regs r;

    *((char *)0xf3e9) = (char)fg;
    *((char *)0xf3ea) = (char)bg;
    *((char *)0xf3eb) = (char)bd;
    calbio(0x0062, &r);
}

VOID inispr(sz)
int sz;
{
    struct regs r;

    r.bc = (int)((*((char *)0xf3e0) & 0xfc) | sz) * 256 + 1;
    calbio(0x0047, &r);
    if (*((char *)0xfaf8) != 0){
	r.bc = (int)(*((char *)0xffe7) & 0xfd) * 256 + 8;
	calbio(0x0047, &r);
    }
    calbio(0x0069,&r);
}

VOID sprite(no,dt)
int no;
char *dt;
{
    if (*((char *)0xf3e0) & 2)
	ldirvm(*((int *)0xf926) + no * 8, dt, 32);
    else
	ldirvm(*((int *)0xf926) + no * 8, dt, 8);
}

VOID putspr(pl, x, y, cl, pt)
int pl, x, y, cl, pt;
{
    char dt[4];

    dt[0] = (char)y;
    dt[1] = (char)x;
    dt[2] = (char)pt;
    dt[3] = (char)cl;
    ldirvm(*((int *)0xf928) + pl * 4, dt, 4);
}

VOID colspr(pl, dt)
int pl;
char *dt;
{
    if (*((char *)0xf3e0) & 2)
	ldirvm(*((int *)0xf928) - 512 + pl * 16, dt, 16);
    else
	ldirvm(*((int *)0xf928) - 512 + pl * 16, dt, 8);
}

TINY gtstck(no)
int no;
{
    struct regs r;

    r.a =(char)no;
    calbio(0x00d5, &r);
    return (r.a);
}

TINY gttrig(no)
int no;
{
    struct regs r;

    r.a =(char)no;
    calbio(0x00d8, &r);
    return (r.a != 0);
}

int gtpad(no)
int no;
{
    struct regs r;

    r.a = (char)no;
    calbio(0x00db, &r);
    if (r.a & 0x80)
	return (int)(r.a) - 256;
    else
	return (int)(r.a);
}

TINY snsmat(mt)
int mt;
{
    struct regs r;

    r.a = (char)mt;
    calbio(0x0141, &r);
    return (r.a);
}

VOID kilbuf()
{
    struct regs r;

    calbio(0x0156, &r);
}

VOID gicini()
{
    struct regs r;

    calbio(0x0090, &r);
}

VOID sound(rg, dt)
int rg, dt;
{
    struct regs r;

    r.a = (char)rg;
    r.de = dt;
    calbio(0x0093, &r);
}

int sgn(vl)
int vl;
{
    if (vl < 0)
	return -1;
    if (vl != 0)
	return 1;
    return 0;
}

VOID srnd()
{
    extern int RNDSPD[2];

    RNDSPD[1] = *((int *)0xfca2);
}

VOID _dmy2_() { }
