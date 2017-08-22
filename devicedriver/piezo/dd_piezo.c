#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <linux/platform_data/edk9s5422_gpio.h>

#define DEVICE_NAME "piezo"

int piezo_gpios;
int piezo_major;
int udelay_Mecro=900;
static int dd_piezo_open(struct inode * inode, struct file* file)
{
	int err;
	edk9s5422_pie_gpio(&piezo_gpios);
	err = gpio_request(piezo_gpios, "piezo");
	if(err){
		printk(KERN_INFO "dd_piezo_open(), gpio_request err!\n");
		return -1;
	}
	return 0;
}
static int dd_piezo_release(struct inode* inode, struct file* file)
{
	gpio_free(piezo_gpios);
	return 0;
}
static ssize_t dd_piezo_write(struct file* file, const char* buf, size_t length, loff_t * ofs)
{
	int ret, value = 0, i;
	ret = copy_from_user(&value, buf, length);
	if(value == 1){
		for(i=0; i<100; i++)
		{
			gpio_direction_output(piezo_gpios, 1);
			mdelay(1);
			udelay(udelay_Mecro);

			gpio_direction_output(piezo_gpios, 0);
			mdelay(1);
			udelay(udelay_Mecro);
		}
	}

	else if(value == 2){

		udelay_Mecro -= 100;
		for(i=0; i<100; i++)
		{
			gpio_direction_output(piezo_gpios, 1);
			mdelay(1);
			udelay(udelay_Mecro);

			gpio_direction_output(piezo_gpios, 0);
			mdelay(1);
			udelay(udelay_Mecro);
		}
	}

	else if(value == 3){

		udelay_Mecro += 100;
		for(i=0; i<100; i++)
		{
			gpio_direction_output(piezo_gpios, 1);
			mdelay(1);
			udelay(udelay_Mecro);

			gpio_direction_output(piezo_gpios, 0);
			mdelay(1);
			udelay(udelay_Mecro);
		}
	} 

	gpio_direction_output(piezo_gpios, 0);

	return 0;
}
static struct file_operations dd_piezo_fops = {
	.owner = THIS_MODULE,
	.open = dd_piezo_open,
	.release = dd_piezo_release,
	.write = dd_piezo_write,
};
static int dd_piezo_init(void){
	piezo_major = register_chrdev(0, DEVICE_NAME, &dd_piezo_fops);
	printk("dd_piezo_int, major number is %d\n", piezo_major);
	return 0;
}
static void dd_piezo_exit(void){
	printk("dd_piezo_exit, \n");
	unregister_chrdev(piezo_major, DEVICE_NAME);
}
module_init(dd_piezo_init);
module_exit(dd_piezo_exit);
MODULE_LICENSE("Dual BSD/GPL");
