#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>
#define DEVICE "chr_reg"

static dev_t mydev_reg;
//static struct cdev* cdev_reg;
static int inuse=0;
static int count=1;
struct class* class_reg;
static int major =0;

        //ssize_t read    (struct file *file, char __user *ubuf, size_t sz, loff_t * loff){
	//		
	//return 0;
	//}
        ssize_t regchrdev_write   (struct file *file, const char __user *ubuf, size_t sz, loff_t * loff){
		printk("received %s\n",ubuf);	
	
	return 0;
	}
        int 	regchrdev_open	  (struct inode *inode, struct file *file){
		if (inuse){
			printk("ERROR  IN USE\n");
			return -1;
		}
		inuse=1;
			printk("DRIVER OPENED\n");
	return 0;
	}
        int 	regchrdev_release (struct inode *inode, struct file *file){
	
	
		inuse=0;		
	return 0;
	}



struct file_operations fops_regchrdev={
	.owner=THIS_MODULE,
	//.read=regchrdev_read,
	.write=regchrdev_write,
	.open=regchrdev_open,
	.release=regchrdev_release
};

static int chrdevreg_init(void){
	//it will give major no as output if success otherwise <0	
	if((major=register_chrdev(major,DEVICE,&fops_regchrdev))<0){
		printk("REGISTER CHRDEV ERROR\n");
		return -1;
	}
	printk("created a device of %s , major==%d\n",DEVICE,major);
	mydev_reg=MKDEV(major,0);
	class_reg=class_create(THIS_MODULE,"DYNAMICALLY_MKNOD_CONFIG");
	device_create(class_reg,NULL,mydev_reg,NULL,"%s","chr_reg");
return 0;
}

static void chrdevreg_exit(void){
	unregister_chrdev(major,DEVICE);
	device_destroy(class_reg,mydev_reg);
	class_destroy(class_reg);
	printk("THE DRIVER IS RELEASED\n");

}

module_init(chrdevreg_init);
module_exit(chrdevreg_exit);
MODULE_LICENSE("GPL");
