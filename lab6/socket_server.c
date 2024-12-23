/* socket_server.c */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SOCKETNAME "mynewsocket"

int main(int argc, char *argv[])
{
  char buffer[1024];
  int n, sock, nsock, len;
  struct sockaddr_un name;

  /**********************************************************
  * YOUR TASK:                                              *
  * Create a new socket.                                    *
  **********************************************************/
  sock = socket( AF_UNIX , SOCK_STREAM , 0);

  // Create the address of the server.
  memset(&name, 0, sizeof(struct sockaddr_un));
  name.sun_family = AF_UNIX;
  strcpy(name.sun_path, SOCKETNAME);
  len = sizeof(name.sun_family) + strlen(name.sun_path);

  // Remove any previous socket.
  unlink(name.sun_path);

  // Bind the socket to the address.
  if (bind(sock, (struct sockaddr *)&name, SUN_LEN(&name)) < 0)
  {
    perror("server: bind");
    exit(1);
  }

  // Listen for connections.
  if (listen(sock, 5) < 0)
  {
    perror("server: listen");
    exit(1);
  }

  // Accept a connection.
  if ((nsock = accept(sock, (struct sockaddr *)&name, &len)) < 0)
  {
    perror("server: accept");
    exit(1);
  }

  /**********************************************************
  * YOUR TASK:                                              *
  * Read from the new socket until end-of-file and          *
  * print all the data received on the standard output.     *
  **********************************************************/

   while ((len = recv(nsock, buffer, 1024, 0)) > 0) {
    buffer[len] = '\0';  // Null-terminate the received data
    printf("Received: %s\n", buffer);
  }

  if (len < 0) {
    perror("server: recv");
  }
  close(nsock);
  close(sock);
  exit(0);
}
