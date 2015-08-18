#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/version.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/miscdevice.h>
#define DEV_NAME "dev_naresh"

static int inuse=0;
	ssize_t misc_write   (struct file *file, const char __user * ubuf, size_t sz, loff_t *loff){
		printk(" received data ubuf=%s\n ",ubuf);	
		return sz;	
	}
        int     misc_open    (struct inode *inode, struct file *file){
		if(inuse){
			printk("error in device open\n");
			return -1;
		}	
		inuse=1;
		printk("operation invoked\n");
	return 0;
	}
	
        int     misc_release (struct inode *inode, struct file *file){
		inuse=0;
	return 0;
	}


static struct file_operations misc_fops={
	.owner=THIS_MODULE,
	.write=misc_write,
	.open=misc_open,
	.release=misc_release
};

static struct miscdevice naresh_misc_char={
        .minor=MISC_DYNAMIC_MINOR,
        .name=DEV_NAME,
        .fops=&misc_fops
};

static int chrmisc_init(void){
	if((misc_register(&naresh_misc_char))<0){
		printk("error in registering\n");
		return -1;
	}
	printk("driver =%d\n",naresh_misc_char.minor);
	return 0;
}


static void chrmisc_exit(void){
	misc_deregister(&naresh_misc_char);
	printk("MODULE_RELEASED\n");
}

module_init(chrmisc_init);
module_exit(chrmisc_exit);
MODULE_LICENSE("GPL");

