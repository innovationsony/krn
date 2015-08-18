#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/version.h>
static int k;
static int rtc_init(void){
	printk("module inserted\n");
	outb(4,0x70);
	k=inb(0x71);
	printk("k=%d\n",k);
return 0;
}
static void  rtc_exit(void){
printk("module released\n");
}
module_init(rtc_init);
module_exit(rtc_exit);
MODULE_LICENSE("GPL");
