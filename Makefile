NUMBER_OF_PROCESSORS ?= 1
NPROCS:=$(NUMBER_OF_PROCESSORS)
OS:=$(shell uname -s)

ifeq ($(OS),Linux)
	NPROCS := $(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(OS),Darwin)
	NPROCS := $(shell sysctl hw.ncpu | awk '{print $$2}')
endif

.PHONY: all
all:
	mkdir -p .build ; mkdir -p install
	cd .build ; cmake .. -DCMAKE_INSTALL_PREFIX=../install -DCMAKE_BUILD_TYPE=Profile && make -j$(NPROCS)

.PHONY: clean
clean:
	find . -iname *~ -exec rm {} \;
	find . -iname .DS_Store -exec rm {} \;
	rm -rf doc/scan-build
	rm -rf install
	rm -rf .build
	rm -rf build

.PHONY: install
install:
	cd .build && make install

