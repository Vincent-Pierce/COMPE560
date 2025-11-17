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
  printf("Hello World!\n");

  int client1 = socket(PF_INET, SOCK_STREAM,0); // TCP protocol
  if(client1 == -1)
  {
    perror("opening socket error\n");
  }

  // struct hostent* gethostbyname(char* name); // translating server name to address

  // struct servent* getservbyname(char* name, char* proto); // translating server name to address, protocol will be TCP

  // int error = connect(client1, sockaddr*, socketlen_t); // read unix programming manual about sockaddr_in

  // write() // just write the struct
  
  // read()
  close(client1);
}