# Switching on JunOS (Juniper Devices)
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
