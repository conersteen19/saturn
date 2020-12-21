# Logical Volume Manager (LVM)
LVM is used to manage a disk in software on a linux system, commonly used for SANs or disks that will need to be split among vms.  This allows for splitting and managing disks without having to reinstall an OS or anything crazy.

## Setting up LVM
Given an available disk (found w/ ```fdisk -l```), which in this ex will be /dev/sdb.

#### Delete existing partitions
```
fdisk /dev/sdb
 (to see how many partitions exist)
n
  (to delete partitions)
d
<part #>
  (create new partition)
n
p
1
default
default
  (rename to lvm partition)
8
t
8e
  (repeat above commands to make as many partitions as necessary)
w
```
Check your commands with ```fdisk -l```.

#### Create Physical Volumes (PVs)
```
pvcreate /dev/sdb<number>
  (check pvs)
pvdisplay
```

#### Create Volume Groups (VGs)
```
vgcreate <name> <devices>
```

#### Create Logical Volumes (LVs)
```
lvcreate -n <name> -L <size, such as 10GiB>
  (check lvs)
lvdisplay
```

You can then make your file system and begin to use the partition.
