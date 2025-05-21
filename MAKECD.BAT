@echo off
echo "Creating disc image..."
@echo on
mkdir CDROM
c:\psyq\bin\OtherTools\buildcd\buildcd -l psx.cti -icdrom\psx.img
del *.toc
c:\psyq\cdemu\bin\stripiso s 2352 cdrom\psx.img cdrom\psx.iso
dd if=c:\psyq\patch\us.patch of=cdrom\psx.iso conv=notrunc
