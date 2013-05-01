/*
 * mac80211_hwsim_e - Extended software simulator of 802.11 radio(s) for
 * mac80211, based on idea of mac80211_hwsim
 *
 * Copyright (c) 2012, Zhou Ming
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include "hwsim_e_device.h"

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/if_ether.h>

MODULE_AUTHOR("Zhou Ming");
MODULE_DESCRIPTION("Extended software simulator of 802.11 radio(s) for \
	mac80211");
MODULE_LICENSE("GPL");

static struct hwsim_e_device *__device;

static int __init mac80211_hwsim_e_init(void)
{
	int ret = -ENOMEM;
	struct class *class;
	u8 addr[ETH_ALEN];

	struct hwsim_e_device *device = kzalloc(sizeof(*device), GFP_KERNEL);
	if (!device)
		goto fail_nomem;
	class = class_create(THIS_MODULE, "mac80211_hwsim_e");
	if (IS_ERR(class)) {
		ret = PTR_ERR(class);
		goto fail_class_create;
	}

	memset(addr, 0, ETH_ALEN);
	addr[0] = 0x02;
	__device = device;
	ret = 0;
	goto out;

fail_class_create:
	kfree(device);
fail_nomem:
out:
	return ret;
}
module_init(mac80211_hwsim_e_init);

static void __exit mac80211_hwsim_e_exit(void)
{
	struct hwsim_e_device *device = __device;
	class_destroy(device->class);
	kfree(device);
}
module_exit(mac80211_hwsim_e_exit);

