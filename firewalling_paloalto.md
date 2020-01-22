# Firewalling on Palo Alto Firewalls
## Terms
*PAN-OS*: Palo Alto Networks’ own operating system for their virtual and physical firewalls.  Based on CentOS, the operating system allows for users to enter a configure mode to change firewall settings with a limited set of commands and possible actions.

*Virtual Wire*: An ability of PAs that allows them to appear invisible on the network but still scan and apply rules to traffic as it passes through the firewall.

*Wildfire*: PAs ability to capture unknown files/EXEs to test what they do in a virtual environment and block them in the future.  Requires communication with the Palo Alto Cloud- tests are not done locally.

## Actions
Note no actions are applied without a __COMMIT__!!!
### Configuration

Set a static IP

Pull Licensing/Get updates from PA

//Note on ARP spoofing

Set static ARP/DNS entries (for licensing)

Pull Licensing/Get updates from PA

### Manage accounts
Create Accounts

Delete User

### Rules

### Misc

Configure wildfire

VOIP in PA

Configure ‘anti-’ blocking
