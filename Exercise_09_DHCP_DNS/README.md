# Exercise 9: Configuration of DHCP Server and Implementation of DNS

## Steps

### Step 1: Set Up Devices in Network Topology

- **Required Devices**:
  - **PCs**: 5 units
  - **Switches**: 2 units (Model: PT-Switch)
  - **Router**: 1 unit (Model: PT-Router)
  - **Server**: 1 unit (Model: Server-PT)
- **Instructions**:
  - Arrange devices in Packet Tracer or a similar simulation tool.
  - Use automatic connecting cables to connect devices (PCs, switches, router, and server) as per the network topology.

### Step 2: Configure the Server’s IPv4 Address and Subnet Mask

1. Select the **Server-PT** device and go to **Desktop > IP Configuration**.
2. Enter the **IPv4 address**, **Subnet Mask**, and **Default Gateway** based on provided network details.

- **Alternative Method**:
  - Use the command prompt on the server to assign the IP address:

    ```bash
    ipconfig <IPv4 address> <subnet mask> <default gateway> (if needed)
    ```

### Step 3: Configuring the DHCP Server

1. On the server, navigate to **Services** > **DHCP**.
2. **Enable DHCP Services**:
   - Turn on DHCP.
3. Configure the DHCP Server:
   - Delete default values from **Start IP Address** and **Subnet Mask** fields.
4. **Create IP Pools**:
   - Set up two IP pools: **POOL1** and **POOL2**, filling in details as per network requirements.

### Step 4: Configure Router with IPv4 Address and Subnet Mask

1. Select **Router0** and navigate to **Config > Interfaces**.
2. Turn on the required ports for connectivity.
3. Configure the **IPv4 address** and **Subnet Mask** in the FastEthernet interface as per the IP addressing table.

### Step 5: Configure PCs and Enable DHCP

1. For each PC (starting with **PC0**), go to **Desktop > IP Configuration**.
2. Change the IP configuration from **Static** to **DHCP**.
3. The PC will now automatically obtain its IP address, subnet mask, and default gateway from the DHCP server.
4. Repeat this process for each PC to complete network configuration.
