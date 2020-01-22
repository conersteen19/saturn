# KVM in Linux
## Terms
Virtualization is essentially “running a computer on a computer”.  It involves using a hypervisor to simulate and distribute resources to Virtual Machines (VMs).

VM configs for KVM are stored in XML files/format.  You can access these files with a raw xml file or with virsh if the the vm is defined and shut down.

## Packages
libvirt-daemon-system libvirt-dev libvirt-clients

## Commands
Create VM
```
virsh define <xmlconfig>
```
Start VM
```
virsh start <vmname>
```
Console VM
```
virsh console <vmname>
```
Clean Shutdown VM
```
virsh shutdown <vmname>
```
Instant Shutdown VM (may corrupt)
```
virsh destroy <vmname>
```
Edit VM config
```
virsh edit <vmname>
```
Remove VM from KVM
```
virsh undefine <vmname>
```
Autostart VM on host machine start
```
virsh autostart <vmname>
```
## XML File
There are a few important lines that need to be changed for each vm.  They are bolded below.
```
<domain type='kvm'>
  <name>guest</name>
  <memory unit='KiB'>262144</memory>
  <currentMemory unit='KiB'>262144</currentMemory>
  <vcpu placement='static'>1</vcpu>
  <os>
    <type arch='x86_64' machine='pc-i440fx-2.1'>hvm</type>
    <boot dev='hd'/>
  </os>
  <features>
    <acpi/>
    <apic/>
    <pae/>
  </features>
  <cpu mode='custom' match='exact'>
    <model fallback='allow'>core2duo</model>
  </cpu>
  <clock offset='utc'>
    <timer name='rtc' tickpolicy='catchup'/>
    <timer name='pit' tickpolicy='delay'/>
    <timer name='hpet' present='no'/>
  </clock>
  <on_poweroff>destroy</on_poweroff>
  <on_reboot>restart</on_reboot>
  <on_crash>restart</on_crash>
  <devices>
    <emulator>/usr/bin/kvm</emulator>
    <disk type='file' device='disk'>
      <driver name='qemu' type='raw'/>
      <source file='/data/drive2/guest.img'/>
      <target dev='hda' bus='ide'/>
      <address type='drive' controller='0' bus='0' target='0' unit='0'/>
    </disk>
    <controller type='usb' index='0' model='ich9-ehci1'>
      <address type='pci' domain='0x0000' bus='0x00' slot='0x03' function='0x7'/>
    </controller>
    <controller type='usb' index='0' model='ich9-uhci1'>
      <master startport='0'/>
      <address type='pci' domain='0x0000' bus='0x00' slot='0x03' function='0x0' multifunction='on'/>
    </controller>
    <controller type='usb' index='0' model='ich9-uhci2'>
      <master startport='2'/>
      <address type='pci' domain='0x0000' bus='0x00' slot='0x03' function='0x1'/>
    </controller>
    <controller type='usb' index='0' model='ich9-uhci3'>
      <master startport='4'/>
      <address type='pci' domain='0x0000' bus='0x00' slot='0x03' function='0x2'/>
    </controller>
    <controller type='pci' index='0' model='pci-root'/>
    <controller type='ide' index='0'>
      <address type='pci' domain='0x0000' bus='0x00' slot='0x01' function='0x1'/>
    </controller>
    <interface type='bridge'>
      <source bridge='vmbr60'/>
      <model type='virtio'/>
      <address type='pci' domain='0x0000' bus='0x00' slot='0x02' function='0x0'/>
    </interface>
    <serial type='pty'>
      <target port='0'/>
    </serial>
    <console type='pty'>
      <target type='serial' port='0'/>
    </console>
    <memballoon model='virtio'>
      <address type='pci' domain='0x0000' bus='0x00' slot='0x04' function='0x0'/>
    </memballoon>
  </devices>
</domain>
```
Note that all network interfaces need to be added.  This should be a bridge.  Multiple bridges can be set up and configured in /etc/network/interfaces to represent ethernet ports or vlans.

## Using Virt-Install
One way to create new VMs is with virt-install.  This uses a disk file made by the user and the iso file can be either downloaded from the internet via a link or downloaded before using wget and specified using a file path.

1.	Create image file
qemu-img create -f qcow2 ./name.qcow2 8G
fallocate -l 8G name.img
i.	change ‘name’ to whatever you want to name your vm
ii.	any size can be used. Ex uses 8GB.
2.	Create network bridge
a.	open /etc/network/interfaces
b.	turn current internet source from iface ___ inet dhcp to iface ___ inet manual
c.	add bridge:
auto br1
iface br1 inet static
address xxx.xxx.xxx.xxx
netmask xxx.xxx.xxx.xxx
gateway xxx.xxx.xxx.xxx
bridge_ports ____
3.	Run virt-install
 virt-install \
--name seshat \
--ram 4096 \
--disk path=/data/seshat.qcow2 \
--vcpus 2 \
--os-type linux \
--os-variant generic \
--network bridge=br1 \
--graphics none \
--console pty,target_type=serial \
--location 'http://archive.ubuntu.com/ubuntu/dists/trusty/main/installer-amd64/' \
--extra-args 'console=ttyS0,115200n8 serial'
b) specifies machine name
c) ram in mb.  Ex uses 4gb
d) disk path and size.  This one uses first image file ex.
e) number of cores to use
h) define network bridge name
k) location of iso file.  Can be URL or file path.  This is for Ubuntu 14.04
4.	Go through standard install
5.	After the install, vm will reboot.  You shouldn’t be able to access the login for the machine.  Reboot and console in immediately.  Enter the boot script (normally ‘e’), find line that starts with ‘linux’ and add ‘console=ttyS0’ to the end.  Then boot the machine (normally ctrl+x)
6.	Once in the machine, type use the following to always boot w/ ttyS0
systemctl enable getty@ttyS0
