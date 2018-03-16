// Shanan, Mario, Brianna
// COP 4600 - Program 2

#include <linux/module.h>
#include <linux/kernal.h>

static int s_open(struct inode*, struct file*);
static int s_close(struct inode*, struct file*);
static ssize_t s_read(struct file*, char*, size_t, loff_t*);
static ssize_t s_write(struct file*, const char*, size_t, loff_t*);

static struct file_operations fops = 
{
	.open = s_open,
	.close = s_close,
	.read = s_read,
	.write = s_write
};

int init_module(void)
{
	//todo
	printk(KERN_INFO "Installing module.\n");

	return 0;
}

void cleanup_module(void)
{
	//to do
	printk(KERN_INFO "Removing module.\n");
}

static int s_open(struct inode*, struct file*)
{

}

static int s_close(struct inode*, struct file*)
{

}

static ssize_t s_read(struct file*, char*, size_t, loff_t*)
{

}

static ssize_t s_write(struct file*, const char*, size_t, loff_t*)
{

}




