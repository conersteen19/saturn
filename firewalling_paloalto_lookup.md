# Palo Alto CLI Lookup Guide

[Application Lookup](https://applipedia.paloaltonetworks.com/)

## Look up command
```
# find command keyword <key>
```

## Show current commits and jobs
```
> show jobs
```

## Update anti-virus software
```
> request anti-virus upgrade check
> request anti-virus upgrade download latest
> request anti-virus upgrade install version latest
```

## Restart box
```
> request system restart
```

## Move Rules
```
# move rulebase security rules "<name>" <top/bottom/above/below> "<name>"
```

## Change admins creds
```
# set mgt-config users admin password
```

## Delete user
```
# delete mgt-config users <name>
```

## Set permitted IPs to access Web Box
```
set deviceconfig system permitted-ip <ip addr>/<netmask>
```

## Work with applications
```
set applicaiton <name> ...
```

## Change Mgt Config Access settings
```
set deviceconfig system service <disable-xxxx> <yes/no>
```
