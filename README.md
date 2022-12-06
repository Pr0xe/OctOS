## OctOS
OctOS is a custom Bootloader with custom Kernel 

- Run steps
1. First run make to create the .bin file
```sh
$ make
```
2. Then we run it in qemu emulator
```sh
$ qemu-system-x86_64 -hda ./boot.bin
```
