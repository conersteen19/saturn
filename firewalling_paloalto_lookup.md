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

## Deviceconfig
Set permitted IPs to access Web Box
```
set deviceconfig system permitted-ip <ip addr>/<netmask>
```
Change Mgt Config Access settings
```
set deviceconfig system service <disable-xxxx> <yes/no>
```

## Mgt-config
Change admins creds
```
# set mgt-config users admin password
```
Delete user
```
# delete mgt-config users <name>
```

## Profiles
Work with applications
```
set applicaiton <name> ...
```

## Rulebase
Move Rules
```
# move rulebase security rules "<name>" <top/bottom/above/below> "<name>"
```

## Logging
