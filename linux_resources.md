# Linux Resources and Programs
This file is a compliation of resources that can be used to perform various tasks.  They are meant to be hosted on Linux boxes but many can also be done on other operating systems.  There are not guides or examples to use these programs, just the names and why they're useful.

**Network File System (NFS)**: Used to create a network shared folder.  Works well with Linux and files are synced on a per-file basis, unlike iSCSI.

**internet Small Computer System Interface (iSCSI)**: Another network sharing platform.  Plays nice with Windows machines and appears as a whole network drive and works as a whole drive.  Can be clustered to prevent downtime.  Configured with targetcli on Linux.

**Corosync/Heartbeat/Pacemaker**: Linux programs designed to link together machines and failover services between the boxes as necessary.  Communicates with DRBD.  Configured in pcs and can work with iSCSI, NFS, MySQL, etc.  Heartbeat is the older product while Pacemaker is newer.

**File Transfer Protocol (FTP)**: Used to transfer files from one machine to another.  FTP is insecure while TFTP is more secure.  Comes in a variety of flavors and is easy to configure.

**Distributed Replicated Block Device (DRBD)**: Program used for high availability clusters.  Designed to allow servers to communiate with one another.  Helps with implementation of lots of backup and reliability programs such as Pacemaker.

To Add:
nmon\
atop\
iftop - tcpip\
bwm - interfaces\

