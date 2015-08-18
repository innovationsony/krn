#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/module.h>


	void indep( void){
	//printk("in indep my number is %d\n",my_number2);
	printk("ENTERING THE FUNCTION %s\n",__func__);
}

static int my_init(void){
	printk("ENTERING THE FUNCTION %s\n",__func__);
extern int  my_number2;
	printk("my number is %d\n",my_number2);
	my_number2=999;
	printk("my number is %d\n",my_number2);
	printk("INSERTING THE MODULE \n" );
	return 0;
}
static void my_exit(void){
	printk("IN THE FUNCTION %s\n",__func__);
	printk("UNLOADING THE MODULE \n" );
}

module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");
