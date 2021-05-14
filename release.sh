#!/bin/bash

mkdir -v ./release

cp -v retrogradeOS.iso ./release
cp -v LICENSE ./release
cp -v README.md ./release
cp -v changelog.md ./release
tar -vcf ./RetrogradeOS.tar ./release/*
mv -v ./RetrogradeOS.tar ./RetrogradeOS-$VERSION.tar
gzip -v -5 ./RetrogradeOS-$VERSION.tar
