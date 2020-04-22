#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init simple_init(void)
{
  printk(KERN_INFO "[SIMPLE]: Module initialized.\n");
  return 0;
}

static void __exit simple_exit(void)
{
  printk(KERN_INFO "[SIMPLE]: Module unloaded.\n");
}

module_init(simple_init);
module_exit(simple_exit);