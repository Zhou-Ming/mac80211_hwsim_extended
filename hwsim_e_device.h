#ifndef __HWSIM_E_DEVICE_H__
#define __HWSIM_E_DEVICE_H__

struct hlist_head;
struct spinlock;

typedef struct hwsim_e_table hwsim_e_table_t;
typedef struct hwsim_e_device hwsim_e_device_t;

struct hwsim_e_table {
  struct hlist_head *buckets;
  struct spinlock *hlistwlock;
};

struct hwsim_e_device {
  hwsim_e_table_t interface_table;
};

#endif /* __HWSIM_E_DEVICE_H__ */
