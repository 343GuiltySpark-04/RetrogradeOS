#!/bin/sh
set -e
. ./iso.sh

sudo qemu-system-$(./target-triplet-to-arch.sh $HOST) -gdb tcp::17 -S -cdrom retrogradeOS.iso

