# Networking Tools/Techniques for Linux
## /etc/network/interfaces
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
