//Tomas Ukrinas

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
  int messageSize = 100;

  int cSocket;
  unsigned int port = 9000;

  cSocket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in address;
  memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_port = htons(port);

  int connStatus = connect(cSocket, (struct sockaddr *) &address, sizeof(address));
  if(connStatus != -1) {
    printf("Connection is successful\n");

    char * message = (char*)calloc(messageSize, sizeof(char));

  	scanf("%s", message);
    send(cSocket, message, strlen(message), 0);
    printf("---\nMessage sent: %s\nMessage size: %d\n---\n", message, (int) strlen(message));
  } else {
    printf("Connection is not successful\n");
  }
  return 0;
}
