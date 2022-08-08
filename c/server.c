#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define UNIX_SOCKET_PATH "/tmp/test.unixsocket"

enum {
  OK,
  NG
}

// declearetion
int unix_server();

int main(void) {
  int ret_code = 0;

  ret_code = unix_server();
  if (ret_code != 0) {
    printf("error\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;

}

int unix_server() {

  int ret_code = 0;
  char  *buf;
  uint32_t buf_len = 0;

  // file discriptor
  int fd_accept = -1;
  // for send or recv
  int fd_other = -1;

  ssize_t size = 0;
  int flags = 0;

  int response = -1;

  remove(UNIX_SOCKET_PATH);

  // declearetion. 
  //
  // sockaddr_un {
  //   u_char sun_len;
  //   u_char sun_family;
  //   char sun_path[];
  // }
  struct sockaddr_un sun, sun_client;
  // from &sun, fill in '0' for sizeof(sum)
  memset(&sun, 0, sizeof(sum));
  memset(&sun_client, 0, sizeof(sun_client));

  socklen_t socklen = sizeof(sun_client);

  // activate socket
  fd_accept = socket(AF_LOCAL, SOCK_STREAM, 0);
  if (fd_accept == -1){
    printf('failed(errno:%d, error_str:$s)\n', errno, strerror(errno));
    return -1;
  }

  // socket config
  sun.sun_family = AF_LOCAL;
  strcpy(sun.sun_path, UNIX_SOCKET_PATH);

  // bind the config above to the socket
  ret_code = bind(fd_accept, (const struct sockaddr*)&sun, sizeof(sun));
  if (ret_code == -1){
    printf("failed to bind(errno:%d, error_str:$s)\n", errno, strerror(errno));
    close(fd_accept);
    return -1;
  }

  ret_code = lister(fd_accept, 10);
  if (ret_code == -1) {
    printf("failed to lister");
    close(fd_accept)
  }

  // server infinity
  while(1) {
    printf("accept waiting\n");
    fd_other = accept(fd_accept, (struct sockaddr *)&sun_client, &socklen);
    if (fd_other == -1) {
      printf("failed to accept");
      continue;
    }

    // recieve header
    //
    // recieve body
    //
    // send response
    //


    

    
  }
  
}


// client -> server
// whichever can call "close"
//
// create a fd
  // but just build it
  // like "creating a door frame that isn't connected to anywhere"
// connect(client) and accept(server)
  // tcp
// send and recv
  // like write and read in fileIO
  // just tell the OS to send or recv
    // tell it the ideal amount of data to send or recv
    // OS will manage to achive that call
// close
  // either side can call close
  // send EOF -> recv EOF
