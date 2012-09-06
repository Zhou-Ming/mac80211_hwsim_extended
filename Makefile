#!/usr/bin/env make -f

KERNELDIR ?= /lib/modules/`uname -r`/build

CURDIR := `pwd`

CMD := $(MAKE) -C $(KERNELDIR) M=$(CURDIR)

ifneq ($(ARCH),)
CMD += ARCH=$(ARCH)
endif

ifneq ($(CROSS_COMPILE),)
CMD += CROSS_COMPILE=$(CROSS_COMPILE)
endif

ifneq ($(CC),)
CMD += CC='$(CC)'
endif

obj-m += mac80211-hwsim-e.o

mac80211-hwsim-e-objs := hwsim_e_device.o

all: modules

install: modules_install

clean:
	@$(CMD) $@

modules:
	@$(CMD) $@

modules_install:
	@$(CMD) $@
