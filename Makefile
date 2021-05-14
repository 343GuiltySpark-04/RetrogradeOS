

all: clean build headers iso
all-release: clean build-release headers iso tar-release


build:
	./build.sh




headers:
	./headers.sh


config:
	./config.sh


iso:
	./iso.sh


clean:
	./clean.sh

build-release:
	./build.sh
	strip -v ./kernel/guidance.kernel

tar-release:
	./release.sh
