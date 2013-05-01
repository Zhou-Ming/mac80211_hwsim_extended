#ifndef __HWSIM_E_DEVICE_H__
#define __HWSIM_E_DEVICE_H__

struct hlist_head;
struct spinlock;
struct class;

struct hwsim_e_table {
  struct hlist_head *buckets;
  struct spinlock *hlistwlock;
};

struct hwsim_e_device {
  struct hwsim_e_table interface_table;
  struct class *class;
};

#endif /* __HWSIM_E_DEVICE_H__ */
