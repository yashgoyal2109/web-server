
# Simple Web Server in C
This project implements a basic web server in C, designed to handle HTTP requests and respond with static HTML content. The web server listens for incoming client connections, processes their HTTP requests, and sends appropriate responses.

The web server demonstrates key concepts in network programming, including socket creation, binding, listening for connections, and handling client requests in a robust and efficient manner. The server is minimalistic and serves a basic HTML page with the message "Hello, world!"

# Features
1. Basic HTTP/1.0 protocol implementation
2. Socket-based networking using the sys/socket.h library
3. Serves static HTML content
4. Simple, clean C code demonstrating server-side programming concepts

### Installation
1. Clone the repository:
```bash
https://github.com/yashgoyal2109/web-server.git
```

2. Navigate to the project directory:
```bash
cd web-server
```

3. Compile the program:
```bash
gcc -o server_output main.c -L. lib_myLibrary.a

```

4. Run the program:
```bash
./server_output
```



# Usage
Once the server is running, open your web browser and visit `http://localhost:8080` to see the "Hello, world" HTML page.

You can modify the HTML response in the source code to serve custom content.


## Project Structure

- `server.h` - Header file containing function declarations and constants.
- `main.c` - Source file containing the implementation of the web server.
- `lib_myLibrary.a` - Library containing the implementation.
- `server.c` - The raw code without use of custom library or header file.
- `README.md` - Documentation of the project.


# How it Works

1. The server creates a socket and binds it to port 8080.
2. It listens for incoming connections and accepts them when a client connects.
3. The server reads the client's HTTP request, parses the method, URI, and version.
4. It responds with a hardcoded HTTP 200 OK message along with an HTML page.
5. After sending the response, the connection is closed.

# Known Issues

- The server currently handles only one connection at a time (no concurrency).
- The server only serves a single static HTML page.
