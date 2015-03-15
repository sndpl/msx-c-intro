struct regs {
    char     f;
    char     a;
    unsigned bc;
    unsigned de;
    unsigned hl;
};

VOID ginit();
VOID calbio();
VOID vpoke();
VOID vpeek();
VOID ldirvm();
VOID ldirmv();
VOID filvrm();
VOID boxfil();
VOID line();
VOID cpym2v();
VOID cpyv2v();
VOID palett();
unsigned rnd();
