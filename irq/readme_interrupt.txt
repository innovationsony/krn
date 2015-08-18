REFERENCE: KERNEL HEADERS:see linux/interrupt.h 
pwd==/src/linux-3.13.5/include/linux# 



request_irq(unsigned int irq, irq_handler_t handler, unsigned long flags,const char *name, void *dev)

RETURN_VALUE
	success:0
	fail:value
------------------------
IRQ LINE NUMBERS
0:


-------------------------------
IRQ_HANDLER
typedef irqreturn_t (*irq_handler_t)(int, void *);
**
 * enum irqreturn
 * IRQ_NONE            interrupt was not from this device
 * IRQ_HANDLED         interrupt was handled by this device
 * IRQ_WAKE_THREAD     handler requests to wake the handler thread
 */

------------------------
IRQF_DISABLED - keep irqs disabled when calling the action handler.
 *                 DEPRECATED. This flag is a NOOP and scheduled to be removed
 * IRQF_SHARED - allow sharing the irq among several devices
 * IRQF_PROBE_SHARED - set by callers when they expect sharing mismatches to occur
 * IRQF_TIMER - Flag to mark this interrupt as timer interrupt
 * IRQF_PERCPU - Interrupt is per cpu
 * IRQF_NOBALANCING - Flag to exclude this interrupt from irq balancing
 * IRQF_IRQPOLL - Interrupt is used for polling (only the interrupt that is
 *                registered first in an shared interrupt is considered for
 *                performance reasons)
 * IRQF_ONESHOT - Interrupt is not reenabled after the hardirq handler finished.
 *                Used by threaded interrupts which need to keep the
 *                irq line disabled until the threaded handler has been run.
 * IRQF_NO_SUSPEND - Do not disable this IRQ during suspend
 * IRQF_FORCE_RESUME - Force enable it on resume even if IRQF_NO_SUSPEND is set
 * IRQF_NO_THREAD - Interrupt cannot be threaded
 * IRQF_EARLY_RESUME - Resume IRQ early during syscore instead of at device
 *                resume time.

----------------------------------------------
name in string format


-----------------------------------------------
dev_id
	


------------------------------------------------
extern void free_irq(unsigned int, void *);
extern void free_irq(unsigned int IRQLINENO, void * device_id);



-------------------------------------------------
example:  request_irq(irq,myinterrupt,IRQF_SHARED,myinterrupt,);
