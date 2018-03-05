//Tomas Ukrinas

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main(int argc, char *argv[]){
  int messageSize = 100;
  int howManyConnections = 10;

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
  printf("Bind was successful\n\n");

  char * buffer = (char*)calloc(messageSize, sizeof(char));
  while(1){
    listen(serverSocket, howManyConnections);
    printf("Server is listening...\n\n");

    clientSocket = accept(serverSocket, NULL, NULL);
    printf("Client connected!!\n");

    while(recv(clientSocket, buffer, messageSize, 0) != 0){
      printf("Recieved message: %s\n", buffer);
      printf("Message size: %d\n\n", (int) strlen(buffer));
      send(clientSocket, buffer, strlen(buffer), 0);
      free(buffer);
      buffer = (char*)calloc(messageSize, sizeof(char));
    }
    printf("Client disconnected\n");
  }

  return 0;
}
