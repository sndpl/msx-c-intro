mx msxalib %1
m80 =%1/z
lib80 /e temp=msxalib<..%1-1>,%1,msxalib<%1+1..>
copy temp.rel msxalib.rel
del temp.rel
del %1.mac
del %1.rel
