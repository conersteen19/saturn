# Switching on CiscoIOS
## Commands
*Enable*: Enable is keyword allowing the user to exit read-only mode and enable editing of configuration files.

*Configure Terminal (Conf T)*: Conf t enters the configuration terminal for CiscoIOS devices.  This allows access to port, vlan, and network configuraitons.

*Write Memory (Write Mem)*: Write mem writes the current written configuration to the memory of the device.  CHANGES WILL GO UNSAVED ON RELOAD UNLESS THE MEMORY IS MANUALLY WRITTEN!!!

*Reload*: Reboot the device

## Initial Configuration Commands
```
Crypto key generate rsa
ip ssh logging events
ip ssh authentication-retries 2
ip ssh time-out 30
ip ssh version 2
service password-encryption
aaa new model
aaa authentication login default local
aaa authorization exec default local if-authenticated
aaa session-id common
line con 0
session-timeout 60
exec-timeout 60 0
privilege level 15
transport preferred none
line vty 0 15
session-timeout 60
exec-timeout 60 0
privilege level 15
transport preferred none
transport input ssh
```

## Conf T Commands
*Interface*: Used to modify the config of a specific network interface.  For instance, Int f 0/1 would access fastEthernet port 1

*Int range*: Used to modify a range of network interfaces

*Vlan XXXX*: define a new vlan.  To modify the vlan, use int vlan xxxx.  No-shutdown is important

*User user privilege 15 secret password password*: Create new user

## Ethernet Config
*switchport acc vlan xxxx*: assign port to vlan

*spanning-tree portfast trunk*: makes ethernet connections skip listening step and connect instantly

*switchport mode access/trunk*: changes mode of port.  Access is unrestricted access, trunk is used for multiple vlans on one port (tags packets)
