#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main(int argc, char *argv[]){
  int serverSocket;
  int clientSocket;
  unsigned int port = 9000;

  serverSocket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in address;
  memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = htonl(INADDR_ANY);

  bind(serverSocket, (struct sockaddr *) &address, sizeof(address));
  printf("Bind was successful\n");
  listen(serverSocket, 1);
  printf("Server is listening...\n");

  clientSocket = accept(serverSocket, NULL, NULL);

  printf("Client connected!!\n");

  return 0;
}
