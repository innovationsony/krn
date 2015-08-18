#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>

#define DEVICE "alloc_naresh"

static dev_t dev_alloc;
static struct cdev* cdev_naresh;
static int major=0;
static int count=1;
static int inuse=0;

//	ssize_t read    (struct file * file, char __user * user_buf, size_t len, loff_t * loff){
//		
//		
//	return 0;
//	}
        ssize_t chr_write (struct file * file, const char __user * user_buf, size_t len, loff_t * loff){
		printk("received bytes is %s\n",user_buf);			
	return 0;
	}
        int chr_open(struct inode * inode, struct file * file){
		if(inuse){
			printk("ERROR IN OPENING\n");
			return -1;
		}
		inuse=1;
	return 0;
	}
        int chr_release (struct inode * inode, struct file * file){
		inuse=0;
			printk("RELEASED SUCCESSFULLY\n");		
	return 0;
	}


struct file_operations fops_alloc={
	.owner=THIS_MODULE,
	.open=chr_open,
	.release= chr_release,
	.write  = chr_write
};
static int chr_init(void){
	if(alloc_chrdev_region(&dev_alloc,0,count,DEVICE)<0){
		printk("ERROR IN ALLOCATION OF CHRDEV\n");
		return -1;
	}
	if((cdev_naresh=cdev_alloc())==NULL){
		printk("ERROR IN DEVICE ALLOCATION\n");
		unregister_chrdev_region(dev_alloc,count);
		return -1;
	}
	cdev_init(cdev_naresh,&fops_alloc);
	if(cdev_add(cdev_naresh,dev_alloc,count)<0){
		printk("ERROR IN DEVICE CHAR DEVICE ADDTION\n");
		cdev_del(cdev_naresh);
		unregister_chrdev_region(dev_alloc,count);
		return -1;
	}
	printk("SUCCESSFULLY CREATED ALLOC_CHRDEVICE of major=%d  DEVICE NAME=%s \n",MAJOR(dev_alloc),DEVICE);
return 0;
}

static void chr_exit(void){
		cdev_del(cdev_naresh);
		unregister_chrdev_region(dev_alloc,count);
		printk("MODULE RELEASED \n");
}

module_init(chr_init);
module_exit(chr_exit);
MODULE_LICENSE("GPL");

