obj-m += testmod.o
obj-m += testmod2.o
obj-m += testmod3.o
obj-m += test_mod_params.o

PWD := $(CURDIR)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	
