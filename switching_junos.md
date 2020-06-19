# Switching on JunOS (Juniper Devices)
## General
- Initially you boot into a FreeBSD shell.  This isn't what manages the switch but holds the JunOS cli.  The CLI has a carrot and a hashtag mode for show and edit modes, respectively.
- If you attach two Juniper swithes together (with the backlink ports), they automatically stack.  This allows one config to manage 2+ switches.
- Juniper uses inet for ipv4 and inet6 for ipv6.
- Juniper, like other switches and palos, requires a commit to actually bring the config into runtime.
- Interfaces come in units.  The unit number corresponds to the tagged vlan when > 0
- In JunOS, everything starts with 0, including interfaces on the front of the switch.
- Ports have a few modes: access (untagged), trunk, and hybrid (does both)
- With a member-range, after you break it up it will write the range config to each port
- Just setting a port to trunk mode doesn't give it any vlans to trunk on.  You must give it vlan members all
- Updates can be done in the BSD subsystem or the cli.  You can use the usb port, scp, http, etc.

## Command Line
Set Root Password:
```
set system root-authentication plain-text-password
```
Turn off SSH root logon:
```
set system services ssh root-login deny
```
Set hostname:
```
set system host-name juniper1
```
Creating a loopback interface:
```
set interfaces lo0 unit 0 family inet address 192.26.0.110/32
```
Setting an interface IP:
```
set interfaces ge-0/0/1 unit 0 family inet address 192.168.100.1/30
```
Show hardware:
```
> show chassis hardware
```
Show Interfaces (shows if interfaces are up or down)
```
> show interface terse
```
Show specific port config
```
> show interfaces ge-0/0/0
```
Filtering ```show``` commands
```
show interfaces terse | [find, match, etc.]
```
Show spanning-tree info for interfaces
```
> show ethernet-switching interface brief
```
Show fiber connections and optic info
```
> show interface diagnostics optics ?
```
Show entire config
```
> show config
```
Show alarms/warning light errors
```
> show chassis alarms
> show system alarms
```
Enter configure mode
```
> edit
# ...
```
Create user
```
# set login user [name] class [superuser/reader] uid 2001 authentication plaintext-password
# [enter pw]
```
Test commit to see if errors
```
# commit check
```
Configure vlans
```
# edit [vlan-name]
# set void vlan-id [vlan]  # setting vlan id
# set l3-interface [interface]  # assign to interface.  Ex. irb.20 corresponds to unit 20
```
Configure interfaces
```
# set intrefaces [interface] unit [unit] family inet address [address]/[netmask] # give ip addr to interface
```
Run show commands from edit mode (same as ```do``` in Cisco
```
# run [command]
```
Set up portchannel/lacp
```
# set aggregated-devices ethernet device-count 8  # reserves space for devices, number of lag grounps you can create
```
Static routing
```
# set route [src address/netmask] next-hop [dest address/netmask]
```
OSPF Routing
```
# set route routing-id [id]
# set protocols ospf
```
Configure spanning-tree
```
# set protocols spanning-tree ...
```
Configuring dhcp
```
# edit access address-assignment pool [pool] family inet dhcp-attributes ...
```
Set port as untagged data port
```
# set interface [int] unit [unit] family ethernet-switching interface-mode access vlan members data
```
Add untagged vlan to trunk port
```
# set interfaces [int] native-vlan-id [number]
```
Set interface range
```
# set interfaces interface-range [name] member-range [start int] to [end int]  # add group to range
# set interfaces interface-range [name] member [int]  # adds a single port to member range
    # Now configure like normal port
```
Set switch to copy-paste mode to drop commands in
```
# load merge relative terminal
```
Set up QOS/COS
```
# edit class-of-service ...
```
See QOS/COS settings on interface
```
> show interfaces queue
```
Enable POE
```
# set poe interface [all, int, int range]
```
Show ARP Info
```
# run show arp
```
Disable interface
```
# set interface [int] disable  # to disable
# delete interface [int] disable  # reenable
```
"Comment out" a block of config
```
# deactivate [block to deactivate]
# activate [block]
```
Undo a commit/rollback
```
# rollback [number]
```
Edit exclusive- don't let another user configure at the same time
```
> edit exclusive
```
Edit private- don't see other people's changes
```
> edit private
```
Apply a config at a certain time
```
# commit at [time]
```
Software upgrade/update
```
> request system software add [file]
```
