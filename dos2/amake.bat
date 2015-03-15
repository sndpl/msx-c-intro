del msxalib.rel
ren *.rel *.rrr
mx -l msxalib > temp.bat
echo del *.rel >> temp.bat
echo ren *.rrr *.rel >> temp.bat
echo ren msxalib.lib msxalib.rel >> temp.bat
temp
