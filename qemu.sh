#!/bin/sh
set -e
. ./iso.sh

sudo qemu-system-$(./target-triplet-to-arch.sh $HOST) -cdrom retrogradeOS.iso
