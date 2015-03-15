del msxclib.rel
ren *.rel *.rrr
del msxclib.tco
cf msxclib
mx -l msxclib > temp.bat
echo del msxclib.tco >> temp.bat
echo del *.rel >> temp.bat
echo ren *.rrr *.rel >> temp.bat
echo ren msxclib.lib msxclib.rel >> temp.bat
temp
