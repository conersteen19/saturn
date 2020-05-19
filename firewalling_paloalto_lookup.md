# Palo Alto CLI Lookup Guide

[Application Lookup](https://applipedia.paloaltonetworks.com/)

## General
Restart machine
```
> request system restart
```
Look up command
```
>/# find command keyword <key>
```
Note this only shows commands accessable in either general or configure mode, not all possible options.

## Committing and Monitoring
Commit
```
# commit
```
Show changes pending commit
```
> show config diff
```
Show current commits and jobs
```
>/# show jobs
>/# show jobs id <number>
```
Show config differences
```
>/# show config diff
```
Validate a config
```
>/# validate full
> show jobs id <id>
```
Revert to old config
```
# revert config
```
Show/end active sessions
```
> show admins
> delete admin-sessions username <user>
```

## Updates
Update anti-virus software
```
> request anti-virus upgrade check
> request anti-virus upgrade download latest
> request anti-virus upgrade install version latest
```
Show possible firmwares
```
> request system software info
```
Download and install a new firmware
```
> request system software download version x.x.x
> request system software install version x.x.xconf 
```

## Deviceconfig
Deviceconfig is commonly used for setting management config settings
 
Set permitted IPs to management interface
```
# set deviceconfig system permitted-ip <ip addr>
```
Change management config subnet/netmask
```
# set deviceconfig system netmask <netmask>
```
Change management config gateway
```
# set deviceconfig system default-gateway <gateway>
```
Change dns servers
```
# set deviceconfig system dns-settting servers primary <server>
# set deviceconfig system dns-settting servers secondary <server>
```
Change management config access settings
```
# set deviceconfig system service <disable-xxxx> <yes/no>
```
Change hostname
```
# set deviceconfig system hostname <name>
```
Change update server settings
```
# set deviceconfig system update-server ...
```
Add login banner/motd (message of the day)
```
# set deviceconfig system login-banner <banner>
# set deviceconfig system motd-and-banner <banner>
```
Change admin lockout settings
```
# set deviceconfig setting management admin-lockout
```
Change timeout logout settings for management access
```
# set deviceconfig setting session ...
```
Change management config ssh settings
```
# set deviceconfig system ssh ...
```

## Mgt-config
Used to change user settings and permissions

Change user password
```
# set mgt-config users <user> password
```
Delete user
```
# delete mgt-config users <user>
```
Ser user permissions
```
# set mgt-config users <user> permissions
```
Set password requirements/complexity
```
# set mgt-config password-profile <name> password-change ...
# set mgt-config users <user> password-profile <name>
# set mgt-config password-complexity ...
```

## Networking (Interfaces and Zones)
Configure interface/ethernet port
```
# set network interface ethernet ethernet1/x <type, ususally layer3 or virtual wire> ...
```
Set interface/ethernet port ip address
```
# set network interface ethernet ethernet1/x layer3 ip <ip addr/netmask>
```
Set interface/ethernet port as virtual wire
```
# set network interface ethernet ethernet1/x virtual-wire 
```
Add interface/ethernet port to zone
```
# set zone <name> network layer3 [ ethernet1/x ... ]
```

## Profiles
Make application by protocol/port
```
# set application <name> default port <tcp/udp>/<ports, xxxx-xxxx> 
```
Define custom application by groups
```
# set application <name> category <cat>
# set application <name> subcategory <subcat>
# set application <name> technology <tech>
<set capabilities as pertinent>
```
Make application group
```
# set application-group <name> members [ <apps> ]
```
Create service
```
# set service <name> protocol <tcp/udp> port <port> source-port <src-port>
```
Create service-group
```
# set service-group <name> members [ <services> ]
```
Create anti-malware profile
```
# set profiles virus <name> packet-capture yes decoder ftp action drop
# set profiles virus <name> packet-capture yes decoder http action drop
# set profiles virus <name> packet-capture yes decoder http2 action drop
# set profiles virus <name> packet-capture yes decoder imap action drop
# set profiles virus <name> packet-capture yes decoder pop3 action drop
# set profiles virus <name> packet-capture yes decoder smb action drop
# set profiles virus <name> packet-capture yes decoder smtp action drop
```
Create anti-spyware profile
```
# set profiles spyware <name> rules all category any packet-capture extended-capture severity any action drop
```
Create vulnerability protection profile
```
# set profiles vulnerability <name> rules all category any host any packet-capture extended-capture threat-name any severity any cve any vendor-id any action drop
```
Create DOS protection profile
```
# set profiles dos-protection <name> flood icmp enable yes
# set profiles dos-protection <name> flood icmpv6 enable yes
# set profiles dos-protection <name> flood other-ip enable yes
# set profiles dos-protection <name> flood tcp-syn enable yes
# set profiles dos-protection <name> flood udp enable yes
# set profiles dos-protection <name> resource sessions enabled yes
```
Create profile-group
```
# set profile-group <name> virus <name> spyware <name> vulnerability <name> dos-protection <name> wildfire-analysis default file-blocking strict
```

## Rulebase
Add FW Rule
```
# set rulebase security rules <name> from <zone> source <source_address> to <zone> destination <dest_zone> service <services> application <apps> action <allow/drop/etc> profile-setting group <profile-group>
```
Add NAT Rule
```
# set rulebase nat rules from <zone> source <ip> to <zone> destination <ip> service <service> destination-translation translated-address <trans-addr> translated-port <trans-port>
```
Move Rule
```
# move rulebase security rules "<name>" <top/bottom/above/below> "<name>"
```
Delete Rule
```
# delete rulebase security rules <name>
```
Move and delete are universal for all types of rulebases, such as NAT.

## Logging
Show all traffic logs
```
> show log traffic
```
Filter log traffic by source/destination
```
> show log traffic <src/dest> <ip>
```
Filter log traffic by port
```
> show log traffic <sport/dport> <port>
```
Filter log traffic by zone
```
> show log traffic <from/to> <zone>
```
Filter log traffic by action
```
> show log traffic action equal <action>
```
Filter log traffic by rule
```
> show log traffic rule <rule>
```
Filter log traffic by application
```
> show log traffic app <app>
```
Show threat logs
```
> show log threat
```
Filtering works the same on all log types with different categories.
