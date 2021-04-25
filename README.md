# RetrogradeOS
A Orbital Reentry Themed OS built from the ground up in a orbital shipyard near you!


# Installation Instructons

before you can build it you'll need to either install the i686 cross toolchain for your distro/OS or build your own (which i recommend) using this guide:
https://wiki.osdev.org/GCC_Cross-Compiler

you'll also need qemu-i686 or bochs (i haven't got it working in it yet though)


then run `make`

to run the OS use `./qemu.sh` or `qemu-debug.sh` to and `gdb --symbol=<pathtofolder>/guidance.sym` if your debugging the default port is `17` the old QOTD port (easy to remember)


# Credits And Thanks

An Extremely Helpful Resource Couldn't Have Done it Without Them:
https://wiki.osdev.org/Main_Page 
