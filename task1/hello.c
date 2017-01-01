#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("7950e1ebd46e");

static int __init hello_init(void){
	printk(KERN_DEBUG "Hello World\n");
	return 0;
}

static void __exit hello_exit(void){
	return;
}

module_init(hello_init);
module_exit(hello_exit);
