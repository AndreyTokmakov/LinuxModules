#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

 
void cleanup_module(void)
{
    pr_info("TestModule: cleanup_module()\n");
}