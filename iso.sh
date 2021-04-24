#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/guidance.kernel isodir/boot/guidance.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "RetrogradeOS" {
	multiboot /boot/guidance.kernel
}
EOF
grub-mkrescue -o retrogradeOS.iso isodir
