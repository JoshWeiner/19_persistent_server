#include "pipe_networking.h"

static void sighandler(int signo) {
  if (signo == SIGINT) {
      remove("wkp");
      exit(0);
  }
}

int main() {
  signal(SIGINT, sighandler);

    int to_client;
    int from_client;

    while(1) {

      from_client = server_handshake( &to_client );
      char msg[BUFFER_SIZE];

      while(read(from_client, msg, BUFFER_SIZE)) {
        printf("[client] %s\n", msg);
        strcat(msg, " -- copy that, client");
        write(to_client, msg, BUFFER_SIZE);
      }
    }
}
