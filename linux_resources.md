# Linux Resources and Programs
This file is a compliation of resources that can be used to perform various tasks.  They are meant to be hosted on Linux boxes but many can also be done on othehr operating systems

**Network File System (NFS)**: Used to create a network shared folder.  Works well with Linux and files are synced on a per-file basis, unlike iSCSI.

**internet Small Computer System Interface (iSCSI)**: Another network sharing platform.  Plays nice with Windows machines and appears as a whole network drive and works as a whole drive.  Can be clustered to prevent downtime.  Configured with targetcli on Linux.

**Corosync/Heartbeat/Pacemaker**: Linux programs designed to link together machines and failover services between the boxes as necessary.  Communicates with DRBD.  Configured in pcs and can work with iSCSI, NFS, MySQL, etc.  Heartbeat is the older product while Pacemaker is newer.

