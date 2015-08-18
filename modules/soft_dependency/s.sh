dmesg -C
insmod indep.ko
insmod dep.ko
echo "DMESG after loading"
rmmod dep
rmmod indep
echo "DMESG after  UNLOADING"
