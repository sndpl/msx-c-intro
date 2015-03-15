cf msxclib
mx msxclib %1
cg %1
m80 =%1/z
lib80 /e temp=msxclib<..%1-1>,%1,msxclib<%1+1..>
copy temp.rel msxclib.rel
del temp.rel
del msxclib.tco
del %1.tco
del %1.mac
del %1.rel
