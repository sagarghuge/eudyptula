#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/hid.h>

static struct usb_device_id hello_table[] = {
	{ USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
		USB_INTERFACE_SUBCLASS_BOOT,
		USB_INTERFACE_PROTOCOL_MOUSE) },
	{ }
};

MODULE_DEVICE_TABLE(usb, hello_table);

static int hello_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
	pr_alert("USB keyboard connected \n");
	return 0;
}

static void hello_disconnect(struct usb_interface *intf)
{
	pr_alert("usb disconnected\n");
}

static struct usb_driver my_driver = {
	.name = "hellodriver",
	.id_table = hello_table,
	.probe = hello_probe,
	.disconnect = hello_disconnect,
};

static int hello_init(void)
{
	int result;
	pr_debug("Hello World\n");

	result = usb_register(&my_driver);

	if (result)
		pr_err("usb_register failed. Error number %d\n", result);

	return result;
}

static void hello_exit(void)
{
	pr_debug("See you\n");
	usb_deregister(&my_driver);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("7950e1ebd46e");
MODULE_LICENSE("GPL");
