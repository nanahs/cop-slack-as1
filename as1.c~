// Shanan, Mario, Brianna
// COP 4600 - Program 2

#include <linux/module.h>
#include <linux/kernal.h>
#include <linux/string.h>
#include <linux/init.h>

static int s_open(struct inode *, struct file *);
static int s_close(struct inode *, struct file *);
static ssize_t s_read(struct file *, char *, size_t, loff_t *);
static ssize_t s_write(struct file *, const char*, size_t, loff_t *);

//Setting the file operations structure to call our created functions
static struct file_operations fops = 
{
	.open = s_open,
	.close = s_close,
	.read = s_read,
	.write = s_write
};

static int majorNum;
static int readLoc = 0;

int init_module(void)
{

	//Register device with major device number
	int regVal = register_chrdev(111, "as1", &fops);

	if(regVal < 0){
		//Device registration has failed
		printk(KERN_ALERT "Device registration attempt has failed.\n");
		return -1;
	}
	else
	{
		//Device registration was successful

		majorNum = regVal;

		printk(KERN_ALERT "Device has been registered. Major number: %d.\n", &majorNum);
		return 0;
	}
}

void cleanup_module(void)
{
	//Unregister the module
	printk(KERN_ALERT "Unregistered device %d.\n", &majorNum);
	unregister_chrdev(majorNum, "as1");
}

static int s_open(struct inode *node, struct file *f)
{
	printk(KERN_ALERT "Device opened.\n");
	return 0;
}

static int s_close(struct inode *node, struct file *f)
{
	printk(KERN_ALERT "Device closed.\n");
	return 0;
}

static ssize_t s_read(struct file *f, char *arr, size_t length, loff_t *off)
{
	printk(KERN_ALERT "Device read.\n");

	int count = 0;

	while(length && (msg[readLoc] != 0))
	{
		//Copies the byte to the user space
		put_user(msg[readLoc], arr++);

		count++;
		length--;
		readLoc++;
	}

	return count;
}

static ssize_t s_write(struct file *f, const char *arr, size_t length, loff_t *off)
{
	printk(KERN_ALERT "Device write.\n");

	int index = length-1;
	int count = 0;
	memset(msg, 0, 100);
	readLoc = 0;
	
	while(length > 0)
	{
		//Writes the characters given in reverse
		msg[count++] = arr[index--];
		length--;
	}

	return count;
	
}




