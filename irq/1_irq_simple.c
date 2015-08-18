#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/module.h>
#include<linux/interrupt.h>

#define SHARED_IRQ 1
static int irq=SHARED_IRQ;
static int intr =0;
static int my_dev_id;
static irqreturn_t function_handler(int irq ,void* my_dev_id){
	intr++;
	printk("intr=%d\n",intr);	
return IRQ_NONE;
}

static int my_init(void){
//request_irq(unsigned int irq, irq_handler_t handler, unsigned long flags,const char *name, void *dev)
	if(request_irq(irq,function_handler,IRQF_SHARED,"my_handler",&my_dev_id)){
		return -1;
	}
	 printk("ISR handler is successfully loaded\n");
return 0;
}

static void my_exit(void){
	synchronize_irq(irq);	
	free_irq(irq, &my_dev_id);
	printk("SUCCEFULLY UNLOADING\n");
}
module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");

