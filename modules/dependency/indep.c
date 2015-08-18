#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/module.h>

int my_number2;
void independ( void){
	printk("ENTERING THE FUNCTION %s\n",__func__);
	my_number2=100;
}
static int my_init(void){
	printk("ENTERING THE FUNCTION %s\n",__func__);
	independ();
	printk("INSERTING THE MODULE \n" );
	return 0;
}
static void my_exit(void){
	printk("IN THE FUNCTION %s\n",__func__);
	printk("UNLOADING THE MODULE \n" );
}

module_init(my_init);
module_exit(my_exit);

EXPORT_SYMBOL_GPL(my_number2);
MODULE_LICENSE("GPL");
