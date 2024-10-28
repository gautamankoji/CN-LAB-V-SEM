# Exercise 3: Switch and Router Configuration and Configuring VLAN in Packet Tracer

## Overview

A switch is a network device used to segment a network into sub-networks, called subnets or LAN segments. It filters and forwards packets between LAN segments based on the MAC address. This exercise demonstrates how to configure a switch, set up VLANs (Virtual Local Area Networks), and verify network connectivity using Packet Tracer.

### Steps to Configure the Switch

1. **Open Packet Tracer** and select a switch (PT-Switch) from the device list.

2. **Configure the Hostname of Switch0:**
   - Click on Switch0 and access the Command Line Interface (CLI).
   - Change the hostname to "sh."

   **Commands:**

   ```shell
   switch> en
   switch# conf t
   switch(config)# hostname sh
   sh(config)# exit
   ```

3. **Set a Message of the Day (MOTD) Banner:**
   - Set an MOTD banner for the users and end it with `$` to exit.

   **Command:**

   ```shell
   sh(config)# banner motd $
   ```

4. **Set Line Control and Enable Secret Passwords:**
   - Configure the line control password and enable secret for better security.

   **Commands:**

   ```shell
   sh# conf t
   sh(config)# line con 0
   sh(config-line)# password 123
   sh(config-line)# login
   sh(config-line)# exit
   ```

5. **Verify Password:**
   - When you log in, it will prompt for the line control password. To configure the terminal, it will ask for the enable secret password.

6. **Save the Configuration:**
   - Save the current running configuration to ensure changes are not lost after rebooting the device.

   **Command:**

   ```shell
   sh# copy run startup-config
   ```

### Router Configuration

After connecting computers with routers using copper straight-through cables, we can simulate network connectivity by transferring a simple PDU (Protocol Data Unit) from PC0 to PC1. The following procedure helps in configuring the router to handle the data flow between multiple devices.

#### Step 1: Configuring Router1

1. Select the router and open the CLI.
2. Press **ENTER** to start configuring Router1.
3. Type `enable` to enter privileged mode.
4. Type `config t` to access the configuration terminal.
5. Configure the router's interfaces and set IP addresses for both FastEthernet0/0 and FastEthernet0/1.

   **Commands:**

   ```shell
   Router> enable
   Router# config t
   Router(config)# interface FastEthernet0/0
   Router(config-if)# ip address 192.168.10.1 255.255.255.0
   Router(config-if)# no shutdown

   Router(config)# interface FastEthernet0/1
   Router(config-if)# ip address 192.168.20.1 255.255.255.0
   Router(config-if)# no shutdown
   ```

#### Step 2: Configuring PCs

Assign IP addresses to each PC in the network and set the default gateway.

- **PC0:** IP: `192.168.10.2`, Gateway: `192.168.10.1`
- **PC1:** IP: `192.168.20.2`, Gateway: `192.168.20.1`

#### Step 3: Connecting PCs with Router

- Connect the **FastEthernet0** port of **PC0** to **FastEthernet0/0** port of **Router1** using a copper straight-through cable.
- Connect the **FastEthernet0** port of **PC1** to **FastEthernet0/1** port of **Router1** using a copper straight-through cable.

#### Router Configuration Table

| Device Name | IP Address (FastEthernet0/0) | Subnet Mask   | IP Address (FastEthernet0/1) | Subnet Mask   |
| ----------- | ---------------------------- | ------------- | ---------------------------- | ------------- |
| Router1     | 192.168.10.1                 | 255.255.255.0 | 192.168.20.1                 | 255.255.255.0 |

#### PC Configuration Table

| Device Name | IP Address   | Subnet Mask   | Gateway      |
| ----------- | ------------ | ------------- | ------------ |
| PC0         | 192.168.10.2 | 255.255.255.0 | 192.168.10.1 |
| PC1         | 192.168.20.2 | 255.255.255.0 | 192.168.20.1 |

### Configuring VLAN in Packet Tracer

A **Virtual Local Area Network (VLAN)** is a custom network created from one or more existing LANs, enabling a group of devices from multiple networks (wired or wireless) to be combined into a single logical network. VLANs can be managed like a physical network, and the equipment must support VLAN configurations.

#### Step 1: Creating LAN-A

1. Create a LAN with 6 hosts and 1 Layer 2 Switch (Switch0).
2. Assign IP addresses to the hosts starting from `192.168.10.1`.

#### Step 2: Creating VLANs

1. Create two VLANs:
   - **VLAN 150: STUDENT**
   - **VLAN 250: FACULTY**

2. Add these VLANs in the VLAN Database.

   **Process:**
   - Go to **Switch0** → **Config** → **Switching** → **VLAN Database**.
   - Assign numbers 150 (for STUDENT) and 250 (for FACULTY).

#### Step 3: Assign Hosts to VLAN-STUDENT

- Assign IP addresses from `192.168.10.1` to `192.168.10.3` under **VLAN-STUDENT**.
- Select the corresponding FastEthernet interfaces and assign them to VLAN 150: STUDENT.

#### Step 4: Assign Hosts to VLAN-FACULTY

- Assign IP addresses from `192.168.10.4` to `192.168.10.6` under **VLAN-FACULTY**.
- Assign these hosts to VLAN 250: FACULTY.

### Verifying VLAN Configuration

1. To verify the configuration, **ping** from `192.168.10.1` to `192.168.10.3`.
2. Select the host with IP `192.168.10.1`, go to **Desktop** → **Command Prompt**, and run the following command:

   ```shell
   ping 192.168.10.3
   ```

This confirms that the VLAN is functioning properly, allowing communication within the VLAN groups.
