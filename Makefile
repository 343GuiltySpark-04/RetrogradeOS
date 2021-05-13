

all: clean build headers iso
release: clean build-release headers iso


build:
	./build.sh




headers:
	./headers.sh




iso:
	./iso.sh


clean:
	./clean.sh

build-release:
	./build.sh
	strip -v ./kernel/guidance.kernel
