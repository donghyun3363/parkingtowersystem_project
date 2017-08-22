ADB := /usr/bin/adb

obj-m := dd_touch.o

KDIR := /home/hoyoung/edk9/linux

all:
	$(MAKE) -C $(KDIR) M=$(shell pwd) modules

install: $(obj-m)
	$(ADB) push $(^:.o=.ko) /
	$(ADB) shell chmod 644 /$(^:.o=.ko)
	$(ADB) shell toolbox rmmod $(^:.o=) > /dev/null
	$(ADB) shell insmod /$(^:.o=.ko)
	$(ADB) shell lsmod | grep $(^:.o=)
clean:
	rm -f *.symvers
	rm -f *.ko
	rm -f *.o
	rm -f *.mod.c
	rm -f *.order
	rm -f .*.cmd
	rm -rf .tmp_versions

