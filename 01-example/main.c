#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "simple"

static int dev_open(struct inode*, struct file*);
static int dev_release(struct inode*, struct file*);
static ssize_t dev_read(struct file*, char*, size_t, loff_t*);
static ssize_t dev_write(struct file*, const char*, size_t, loff_t*);

static struct file_operations fops = {
  .open = dev_open,
  .read = dev_read,
  .write = dev_write,
  .release = dev_release,
};

static int major;

static int __init simple_init(void)
{
  major = register_chrdev(0, DEVICE_NAME, &fops);

  if (!major) {
    printk(KERN_ALERT "[SIMPLE]: Failed to initialize.\n");
    return major;
  }
  printk(KERN_INFO "[SIMPLE]: Module initialized.\n");
  return 0;
}

static void __exit simple_exit(void)
{
  unregister_chrdev(major, DEVICE_NAME);
  printk(KERN_INFO "[SIMPLE]: Module unloaded.\n");
}

static int dev_open(struct inode *inodep, struct file *filep)
{
  printk(KERN_INFO "[SIMPLE]: Dev open.\n");
  
  return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offet)
{
  printk(KERN_INFO "[SIMPLE]: Dev read.\n");

  return -EFAULT;
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset)
{
  printk(KERN_INFO "[SIMPLE]: Dev write.\n");

  return -EFAULT;
}

static int dev_release(struct inode *inodep, struct file *filep)
{
  printk(KERN_INFO "[SIMPLE]: Dev release.\n");

  return 0;
}

module_init(simple_init);
module_exit(simple_exit);