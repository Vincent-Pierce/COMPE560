/**************************************************************************************
 * Author: Vincent Pierce 
 * 
 * Description: COMPE560 Network Programming Project -- Introduction to Sockets.
 * This project accomplishes inter-machine communication via sockets. A struct 
 * containing an integer, character and float is passed between a client and server 
 * before being printed out. In total three machines representing, two clients, and one
 * server will be utilized.
 * 
 * Client1 machine
 * ***********************************************************************************/

/* FILE INCLUSIONS ****************************************************************/
#include "client1.h"
#include <sys/socket.h>

int main()
{
  printf("Hello World! This is Client1 saying Hi! \n");

  primitiveStruct dataStruct = {1, 'a', 1.1};

  int client1 = socket(PF_INET, SOCK_STREAM,0); // TCP protocol
  if(client1 == -1)
  {
    perror("opening socket error\n");
    exit(1);
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(32351);
  inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

  printf("before connect\n");
  if(connect(client1, (struct sockaddr *)&addr, sizeof(addr))  < 0)
  {
    perror("connect error\n");
    exit(1);
  }
  
  printf("before write\n");
  size_t bytesWritten = write(client1, &dataStruct, sizeof(dataStruct));
  if(bytesWritten < 0)
  {
    perror("fail on write\n");
    close(client1);
    exit(-1);
  }

  close(client1);
  return 0;
  // struct hostent* gethostbyname(char* name); // translating server name to address

  // struct servent* getservbyname(char* name, char* proto); // translating server name to address, protocol will be TCP

  // int error = connect(client1, sockaddr*, socketlen_t); // read unix programming manual about sockaddr_in

  // write() // just write the struct
  
  // read()
  close(client1);
}