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


static int __init hello_2_init(void)
{
    pr_info("TestModule2: Initilization\n");
    return 0;
}
 
static void __exit hello_2_exit(void)
{
    pr_info("TestModule2: Exit\n");
}
 
module_init(hello_2_init);
module_exit(hello_2_exit);
 
MODULE_LICENSE("GPL");