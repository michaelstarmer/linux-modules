# Linux drivers
Template and basic examples for Linux device drivers.

Resources:
- [LDD3 Book](https://lwn.net/Kernel/LDD3/)
- [LDD3 GitHub examples](https://github.com/martinezjavier/ldd3)

# Build & Load modules
```sh
// Open syslog
tail -f /var/log/syslog

// Activate
sudo insmod main.ko

// Deactivate
sudo rmmod main.ko
```

# Create virtual device/node
```sh
sudo mknod <name> c <major> <minor>
sudo mknod simple c 508 0
```

# Boilerplate

### Module

```c
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENCE("Dual BSD/GPL");

static int __init hello_init(void)
{
    printk(KERN_ALERT "[HELLO MODULE] Loaded\n");
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_ALERT "[HELLO MODULE] Unloaded\n");
}

module_init(hello_init);
module_exit(hello_exit);
```

### Makefile

```Makefile
obj-m += main.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```