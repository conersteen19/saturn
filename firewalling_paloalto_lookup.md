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
>/# commit
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
Change management config Access settings
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

## Networking
Configure interface/ethernet port
```
# set network interface ethernet ethernet1/x <type, ususally layer3 or virtual wire> ...
```
Set interface/ethernet port ip address
```
# set network interface ethernet ethernet1/x layer3 ip <ip addr/netmask>
```
Add interface/ethernet port to zone
```
# set zone <name> network layer3 [ ethernet1/x ... ]
```

## Profiles
Work with applications
```
# set applicaiton <name> ...
```

## Rulebase
Move Rules
```
# move rulebase security rules "<name>" <top/bottom/above/below> "<name>"
```

## Logging
