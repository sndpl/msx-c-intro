#include <stdio.h>
#include <msxclib.h>

VOID main()
{
	puts("Type some words!\n");
	puts(" and hit [RETURN] key to exit.\n");
	while ((snsmat(7) & 0x80) != 0);
    kilbuf();
}