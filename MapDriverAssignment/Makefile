
CC=gcc
DEBUG=-g -D_DEBUG
DEFINE=-DMODULE -D__KERNEL__ -DLINUX
WARNINGS=-Wall -Wmissing-prototypes -Wmissing-declarations
#ISO=-ansi -pedantic
CC_OPTIONS=-O1 $(WARNINGS) $(ISO) $(DEBUG) $(DEFINE)
SHELL=/bin/bash

# Where to look for header files
INC=-I. -I/usr/include -I/usr/src/kernels/`uname -r`/include

DRIVER=asciimap.o
MODULE=asciimap.ko

obj-m += $(DRIVER)

all: 
	DIR=$(PWD)
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	cd $(DIR)
	@echo "Woo! You compiled a driver!!"

build:
	make all
	make register
	eval `dmesg | grep mknod | tail -1`

clean:
	rm -f $(DRIVER)
	DIR=$(PWD)
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	cd $(DIR)

rebuild:
	make clean
#RESULT=$(shell lsmod | grep asciimap | tail -1 | wc -l)
#ifeq(1, ${RESULT})
	sudo rmmod asciimap
#if [`lsmod | grep asciimap | tail -1 | wc -l` -eq "1"]
#then
#fi
#ifeq (,$(wildcard /dev/asciimap))
	sudo rm /dev/asciimap
	make all
	make register
	eval `dmesg | grep mknod | tail -1`
	
retest:
	make rebuild
	gcc test.c -o test
	./test

register: $(DRIVER)
	insmod ./$(MODULE)
	modinfo $(MODULE)
	lsmod | grep asciimap

clean-all:
	make clean
	rmmod asciimap
	lsmod
