# RetrogradeOS
A Orbital Reentry Themed OS built from the ground up in a orbital shipyard near you!

**Note: The CMake branch is not working as i'm still implimenting CMake as the build system!**

![2021-05-13_20-33](https://user-images.githubusercontent.com/69496138/118203937-1727a680-b42b-11eb-86e4-f74a9bd838b7.png)


# Installation Instructons

before you can build it you'll need to either install the i686 cross toolchain for your distro/OS or build your own (which i recommend) using this guide:
https://wiki.osdev.org/GCC_Cross-Compiler

you'll also need qemu-i686 or bochs (i haven't got it working in it yet though)


then run `make`

to run the OS use `./qemu.sh` or `qemu-debug.sh` to and `gdb --symbol=<pathtofolder>/guidance.sym` if your debugging the default port is `localhost:17` the old QOTD port (easy to remember)


# Credits And Thanks

An Extremely Helpful Resource Couldn't Have Done it Without Them:
https://wiki.osdev.org/Main_Page 
And to https://github.com/stephengrice For letting me use his kernel as a base!

