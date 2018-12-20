#include "pipe_networking.h"

int main() {
  int to_server, from_server;

  char buff[BUFFER_SIZE];

  from_server = client_handshake( &to_server );

  char wr[BUFFER_SIZE];
  char rd[BUFFER_SIZE];

  while(1){
    printf("[client] enter message to sent to server: ");
    fgets(wr, BUFFER_SIZE, stdin);
    wr[strlen(wr) - 1] = '\0';
    write(to_server, wr, BUFFER_SIZE);
    read(from_server, rd, BUFFER_SIZE);
    printf("[server]: %s\n", rd);
  }
}
