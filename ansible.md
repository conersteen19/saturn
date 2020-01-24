# Ansible
## Terms
Ansible is a program that allows for automation of tasks on machines via SSH and Python.  There is a client machine which runs Ansible.  That client machine’s Ansible instance then uses SSH to go into each node machine and perform the tasks assigned.  Requires the client’s public key on each node to work.

*Hosts file*: file that contains the hosts to run the ansible script on.  Written in yml.  Example: 
```
all:
  hosts:
    192.168.6.176:
  vars:
    global_keys:
      - conersteen
```
Where hosts lists the ip addresses of the machines to run the cookbook on and global_keys has the ssh key to use to get into the machines.  Store those keys in a folder titled public_keys in the same directory.  Name files “conersteen”, no extension.

*Cookbook*: Script that Ansible uses to run.  Written in yml.  Defines different actions to perform on the machines.  Run with:
```
ansible-cookbook -u <user> -i <hostsfile.yml> <cookbookfile.yml>
```
Example:
```
---

- hosts: all
  vars:
    host_ssh: "{{ host_keys | default([]) | list }}"
    group_ssh: "{{ group_keys | default([]) | list }}"
    global_ssh: "{{ global_keys | default([]) | list }}"
    ssh_keys: "{{ host_ssh + group_ssh + global_ssh }}"

  tasks:

    - name: Install Web Server
      package: name={{ item }} state=present
      with_items:
        - nginx 
```
Where hosts defines what hosts the tasks should be performed on and tasks defines what actions need to be done.  Note that whitespace matters; use two spaces to go up a line.

## Tasks
*file*: Used to work with files and directories.  Use different states to specify what action is being performed.  To make a file, use touch with tag path (and mode to specify permissions).  To link a file, use link with tags src and dest.  

*copy*: Used to copy a local file on the client machine to overwrite or add a file to a node machine.  Specify a src, dest, and state.

*get_url*: Used as a wget to download a file from the internet to a local machine.  Specify file download location and url to get file from.

*subversion*: Used to create an svn repository.  Includes either adding a new one or updating an existing repository.  Specify a url, username, password, and destination folder.

*apt*: Used to install packages.  Specify name of packages and current state.
