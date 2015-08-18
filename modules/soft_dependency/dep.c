#include<linux/module.h>
#include<linux/version.h>
static int *ptr;
int myinit(void){
ptr=(int*) __symbol_get("myvalue");
	if(ptr){
	printk("loaded the modulen:dep\n");
	*ptr=100;
	__symbol_put("myvalue");
	printk("after update\n");
	return 0;
	}
	else{
	printk("error in getting symbol\n");
	return -1;
	}	

}
void myexit(void){
	printk("unloaded the module:dep\n");
}
module_init(myinit);
module_exit(myexit);
MODULE_LICENSE("GPL");
