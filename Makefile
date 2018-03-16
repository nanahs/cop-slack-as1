obj-m += as1.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
load:
	insmod ./as1.ko
unload:
	rmmod ./as1.ko
view:
	cat /proc/modules
