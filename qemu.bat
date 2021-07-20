@echo off
color 0a

:start
echo.
echo press any key to launch qemu...
pause > nil
goto launch

:launch
del nil
cls
color 07
qemu-system-i386 -cdrom retrogradeOS.iso