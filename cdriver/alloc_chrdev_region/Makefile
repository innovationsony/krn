#obj-m := 1_alloc_chrdev_region.o
obj-m := 2_alloc_chrdev_virtual.o
	
KDIR=/lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean 	
