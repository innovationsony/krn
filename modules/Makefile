obj-m = 1_hello_world.o
KDIR= /lib/modules/$(shell uname -r )/build
comp:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
