# Firewalling on Palo Alto Firewalls
## Terms
*PAN-OS*: Palo Alto Networks’ own operating system for their virtual and physical firewalls.  Based on CentOS, the operating system allows for users to enter a configure mode to change firewall settings with a limited set of commands and possible actions.

*Virtual Wire*: An ability of PAs that allows them to appear invisible on the network but still scan and apply rules to traffic as it passes through the firewall.

*Layer3*: A generic configuration of a port that allows it to gain an IP address.  Generally used for normal firewall operations such as traffic management and DHCP.

*Wildfire*: PAs ability to capture unknown files/EXEs to test what they do in a virtual environment and block them in the future.  Requires communication with the Palo Alto Cloud- tests are not done locally.

## Configuration Notes
When setting up a Palo, the first work that needs to be done is securing/configuring the management interface.  This is usually done via command line by console connection.  Set a static ip and get into the web portal.  It is important to make sure you have a secure user and restrict access to only certain types of communication (ssh, https).  After you give it a static ip, you can access the management interface.

After getting your management interface set up and making sure you have access to the web portal, updates should be done to make sure your box is up to date.  Update the OS then the anti-malware package and set up to auto check and update.  To do this you need to let your management interface access the internet.

Once you are updated, set up your other interfaces appropriatly.  You generally want to do either a virtual wire or a layer3 interface.  Virtual wires act as a passthrough for traffic and just apply firewall rules.  Layer3 makes the ports have an IP address and act as a hop when going to or from a machine.  Virtual wires are good for applying rules without others knowing you're there while layer3 interfaces are better for more traditional firewalling.  After configuring interfaces, add your interfaces to zones, generally "inside" and "outside" are used.  There are commonly used in rules to specify traffic direction instead of using unique interfaces.

## Rules
