#include<linux/module.h>
#include<linux/kernel.h>
int myvalue;
int myinit(void){
	printk("loaded the module:indep\n");
	myvalue=1000;	
	printk("the value is %d \n",myvalue);
	return 0;
}
void myexit(void){
        printk (KERN_INFO "value of counter %d \n", myvalue);
	printk("unloaded the modulen:indep\n");
}
EXPORT_SYMBOL_GPL (myvalue);
module_init(myinit);
module_exit(myexit);
MODULE_LICENSE("GPL");
