@echo off
color 0a

:start
echo.
echo press any key to launch qemu...
pause > nul
goto launch

:launch
cls
color 07
qemu-system-i386 -cdrom retrogradeOS.iso