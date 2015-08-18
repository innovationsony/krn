#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/module.h>


void func(void){
	printk(" HELLO_WORLD INSIDE FUNCTION\n");
}

int my_init(void){
	printk("MODULE INSERTED\n");
return 0;
}

void my_exit(void){
	printk("MODULE REMOVED\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");


