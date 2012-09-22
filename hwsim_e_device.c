/*
 * mac80211_hwsim_e - Extended software simulator of 802.11 radio(s) for
 * mac80211
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

MODULE_AUTHOR("Zhou Ming");
MODULE_DESCRIPTION("Extended software simulator of 802.11 radio(s) for\
 mac80211");
MODULE_LICENSE("GPL");

static hwsim_e_device_t *__device;

static int __init mac80211_hwsim_e_init(void)
{
  int ret = -ENOMEM;

  hwsim_e_device_t *device = kzalloc(sizeof(*device), GFP_KERNEL);
  if (!device)
    goto e_nomem;
  __device = device;
  ret = 0;

 e_nomem:
  return ret;
}
module_init(mac80211_hwsim_e_init);

static void __exit mac80211_hwsim_e_exit(void)
{
  hwsim_e_device_t *device = __device;
  kfree(device);
}
module_exit(mac80211_hwsim_e_exit);
