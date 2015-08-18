/*
FOR THIS METHOD 
1.SEARCH WHIC DEVICES NODES OF MAJOR NO ARE FREE
2.DO MKNOD IN ANOTHER TAB
3.REGISTER WITH MAJOR NUMBER VIA (MKDEV)
	register_chrdev_region() - register a range of device numbers
	  @from: the first in the desired range of device numbers; must include 
	         the major number.
	  @count: the number of consecutive device numbers required
	  @name: the name of the device or driver.
	 
	  Return value is zero on success, a negative error code on failure.
	 /
	int register_chrdev_region(dev_t from, unsigned count, const char *name)
*
 cdev_alloc() - allocate a cdev structure

 Allocates and returns a cdev structure, or NULL on failure.
/
struct cdev *cdev_alloc(void)
*
 cdev_init() - initialize a cdev structure
 @cdev: the structure to initialize
 @fops: the file_operations for this device

 Initializes @cdev, remembering @fops, making it ready to add to the
 system with cdev_add().
/
void cdev_init(struct cdev *cdev, const struct file_operations *fops)

*/
#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#define MJR 100 
#define MNR 0
#define MYDEVICE "aug12"

static struct cdev* cdev_aug12;
static dev_t dev_major;
static	unsigned int  count=1;
static int inuse=0;
        int chr_open(struct inode * inode, struct file * file){
        	if(inuse){
			printk("ERROR IN OPENING A FILE\n");
		}
		inuse=1;
		printk("opened the device\n");
		return 0;
	}
	int chr_release (struct inode * inode, struct file * file){
		inuse=0; 					
		 printk("closed the device\n");
		return 0;
	}
	//ssize_t chr_read    (struct file * file, char __user * user_buff, size_t size, loff_t * offset){
	//}
	ssize_t chr_write   (struct file * file, const char __user* user_buff, size_t size, loff_t * offset){
              printk("the data transferred is=%s, size=%ld\n", user_buff, size);
		return size;
	}
struct file_operations my_fops={
  	.owner=THIS_MODULE,
	//.read=chr_read,
	.write=chr_write,
	.open=chr_open,
	.release=chr_release
};
static int char_init(void){
	dev_major=MKDEV(MJR,MNR);
	if(register_chrdev_region(dev_major,count,MYDEVICE)<0){
		printk("driver registration failed\n");
		return -1;
	}
	if((cdev_aug12=cdev_alloc())==NULL){
		printk("cdev allocation failed\n");
		return -1;
	}
	cdev_init(cdev_aug12,&my_fops);
	
	if(cdev_add(cdev_aug12,dev_major,count)<0){
		printk("container add is failed\n");
		return -1;
	}
	printk("DRIVER REGISTERED %s\n",MYDEVICE);
	return 0;
}
static void char_exit(void){
	cdev_del(cdev_aug12);
	unregister_chrdev_region(dev_major,count);
	printk("aug12 driver released\n");
}
module_init(char_init);
module_exit(char_exit);
MODULE_LICENSE("GPL");
