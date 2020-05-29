# Networking Tools/Techniques for Linux
## /etc/network/interfaces
### Types
ens/eth: Stanadard ethernet or network ports.  Can assign with DHCP or a static ip.  Can also be configured as manual to be dealt with later in the config.
bond: Used for bonding ports together as a single unit.  Goes above ens/eth definitions and those ports should be added as slaves to the bond.
vlan: Used to specify a vlan tag to be used by a future port or vmbr.
vmbr: Virtual bridge.  Used to connect two different interfaces within a machine

### Examples
Standard DHCP format
```
auto lo
iface lo inet loopback

auto ens2
iface ens2 inet dhcp
```
Standard Static IP format
```
auto lo
iface lo inet loopback

auto ens2
iface ens2 inet static
	address <address>
	subnet <subnet>
	gateway <gateway>
```
Bridge Format: (bridge-utils must be installed)
```
auto lo
iface lo inet loopback

auto ens2
iface ens2 inet manual

auto vmbr10
iface vmbr10 inet dhcp
	bridge_ports ens2
	bridge_hello 2
	bridge_maxage 12
	bridge_stp off
   	bridge_fd 9
```

Vlan w/out virtualization format
```
auto lo
iface lo inet loopback

auto ens2
iface ens2 inet manual

auto vlan10
iface vlan10 inet dhcp
	vlan-raw-device ens2
```

Bond Example
```
auto bond0
iface bond0 inet manual
        down ip link set $IFACE down
        pre-up modprobe bonding mode=4
        up ip link set $IFACE up
        bond-mode 4
        bond-lacp-rate 1
        bond-miimon 100
        bond-downdelay 200
        bond-updelay 200
        bond-slaves eth0 eth1

auto eth0
iface eth0 inet manual
        bond-master bond0
        up /sbin/ifconfig $IFACE up

auto eth1
iface eth1 inet manual
        bond-master bond0
        up /sbin/ifconfig $IFACE up
```
