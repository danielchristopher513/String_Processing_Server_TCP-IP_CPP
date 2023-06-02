# String_Processing_Server_TCP-IP_CPP
### This project implements a TCP server and client in C, using the TCP/IP protocol. The server and client communicate over a network connection and perform string processing operations based on the client's request.
-------------
## TCP Server
### The TCP server performs the following steps:

+ **Creating the TCP Socket**: The server creates a TCP socket using the socket() function.

+ **Binding the Socket**: The server binds the socket to a specific server address using the bind() function.

+ **Listening for Connections**: The server puts the socket in a passive mode using the listen() function. It waits for the client to approach and establish a connection.

+ **Accepting Connections**: The server accepts the client's connection using the accept() function. At this point, a connection is established between the server and the client, and they are ready to transfer data.

+ **Processing Client Requests**: Once the connection is established, the server receives string processing requests from the client. It processes the string based on the choice sent by the client, which includes operations such as converting to uppercase or lowercase, checking if the string is a palindrome, determining the length of the string, checking for anagrams, pangrams, isograms, and reversing the string.

+ **Exiting the Application**: The server can be terminated by entering "exit". Upon termination, the TCP/IP connection is closed.
-------------
## TCP Client
### The TCP client performs the following steps:

+ **Creating the TCP Socket**: The client creates a TCP socket using the socket() function.

+ **Connecting to the Server**: The client connects the newly created socket to the server's address using the connect() function.

+ **Sending Requests to Server**: The client sends string processing requests to the server in the format <choice>#<string>. The server processes the requests and returns the results.

+ **Receiving Responses from Server**: The client receives the processed string from the server.

+ **Continuing or Exiting the Client**: After receiving the response, the client can choose to continue sending requests or exit the client application.
  --------------
## Usage
To run the TCP server and client, follow these steps:
### Open two terminal One for client one for Server:
+ Compile and run the server program on one Terminal.
  ```
  gcc str server.c  -o server
  ./server
  ```

+ Compile the Client Program and run on another terminal.
  ```
  gcc str_ctient.c -o client
  ./client
  ```

+ Enter string processing requests in the format '<choice>#<string>'.

+ View the processed string results received from the server on the client terminal.

+ Enter "exit" to terminate the application and close the TCP/IP connection.
  
  Requirements:
  Ubuntu 18.6 and above and gcc 6.3.0
  
