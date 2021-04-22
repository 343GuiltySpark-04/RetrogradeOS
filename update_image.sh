#!/bin/bash

sudo losetup /dev/loop10 floppy.img
sudo mount /dev/loop10 /mnt
sudo cp src/kernel /mnt/kernel
sudo umount /dev/loop10
sudo losetup -d /dev/loop10
