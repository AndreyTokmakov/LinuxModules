#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

// Module metadata
MODULE_AUTHOR("Andrei Tokmakov");
MODULE_DESCRIPTION("TestModule");
MODULE_LICENSE("GPL");

int init_module(void)
{
    pr_info("TestModule: init_module()\n");
    return 0;
}
 