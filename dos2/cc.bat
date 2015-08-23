CF %2 %1
CG -k %3 %1
M80 =%1/z
L80 B:\LIB\CK,%1,B:\lib\mlib/s,B:\LIB\CLIB/S,B:\LIB\CRUN/S,B:\LIB\CEND,%1/N/Y/E:xmain
DEL %1.mac
DEL %1.rel
DEL %1.tco
