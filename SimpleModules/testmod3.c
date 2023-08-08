#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>

// Module metadata
MODULE_AUTHOR("Andrei Tokmakov");
MODULE_DESCRIPTION("TestModule2");
MODULE_LICENSE("GPL");

// __initdata  --> MACRO to initilyze variables
static int hello3_data __initdata = 3;
 
static int __init hello_3_init(void)
{
    pr_info("Hello, world %d\n", hello3_data);
    return 0;
}
 
static void __exit hello_3_exit(void)
{
    pr_info("Goodbye, world 3\n");
}
 
module_init(hello_3_init);
module_exit(hello_3_exit);
 
MODULE_LICENSE("GPL");