# Exercise 10: Implementation of HTTP (Hyper Text Transfer Protocol)

## Steps

### Step 1: Setup Devices in Packet Tracer

1. **Open Packet Tracer**.
2. Go to **End Devices**, select **PC**, and drag it onto the screen.
3. Again, go to **End Devices**, select a **Server**, and drag it onto the screen.
4. **Connect** the PC and Server:
   - Use a **cable** (e.g., copper straight-through) to connect the PC to the server.
   - Click on the PC and the server in sequence to establish the connection.

### Step 2: Configure IP Addresses

1. **PC Configuration**:
   - Double-click on **PC0**.
   - Go to **Desktop > IP Configuration**.
   - Set an IP address for PC0 (e.g., `192.168.1.2`).

2. **Server Configuration**:
   - Double-click on **Server0**.
   - Go to **Desktop > IP Configuration**.
   - Set an IP address for the web server (e.g., `192.168.1.1`).

### Step 3: Configure the Web Server

1. Double-click on **Server0** and go to **Services > HTTP**.
2. **Add HTML Content**:
   - Click on **HTML** and add a simple HTML code.
   - Example HTML code:

     ```html
     <!DOCTYPE html>
     <html>
     <head>
         <title>Page Title</title>
     </head>
     <body>
         <h2>Welcome To GFG</h2>
         <p>Default code has been loaded into the Editor.</p>
     </body>
     </html>
     ```

3. Save the changes to ensure the content is ready for serving.

### Step 4: Access the Web Server from the Client

1. On **PC0**, go to **Desktop > Web Browser**.
2. Enter the server’s IP address in the address bar (e.g., `192.168.1.1`).
3. Click **Go** to request the webpage.
