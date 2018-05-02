

//Based on man 2 bind example code:

	#include <sys/socket.h>
	//#include <sys/un.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <unistd.h>
	#include <sys/types.h>
	
	//for ip
	#include <netinet/in.h>
	#include <netinet/ip.h> /* superset of previous */
	
	
	
	//#define MY_SOCK_PATH "/somepath"
	//#define MY_SOCK_PATH "/student/khanim/3500/Studio/Studio25/serverSocket"
	#define MY_SOCK_PATH "serverSocket"
	//#define bufferSize 1000
	#define bufferSize 5000
	#define bufferSize2 100
	
	#define handle_error(msg) \
		do { perror(msg); exit(EXIT_FAILURE); } while (0)

	int main(int argc, char *argv[])
	{
		if(argc!=3){
			printf("Incorrect number of arguments\n");
			printf("client <IP address> <port number>\n");
			exit(1);
		}
		
		char *address = argv[1];
		
		int port = atoi(argv[2]);
		
		int sfd, cfd;
		struct sockaddr_in my_addr, peer_addr;
		socklen_t peer_addr_size;
		
		sfd = socket(AF_INET, SOCK_STREAM, 0);
		if (sfd == -1)
			handle_error("socket");
		
		memset(&peer_addr, 0, sizeof(struct sockaddr_in));
			/* Clear structure */
		peer_addr.sin_family = AF_INET;
		peer_addr.sin_addr.s_addr = inet_addr(address);
		peer_addr.sin_port = port;
		//strncpy(peer_addr.sun_path, MY_SOCK_PATH,
		//	sizeof(peer_addr.sun_path) - 1);
		
		
		
		if(connect(sfd, (struct sockaddr *) &peer_addr, sizeof(struct sockaddr_in)) == -1){
			perror("connect");
			exit(1);
		}
		

		/* Code to deal with incoming connection(s)... */
		
		//More code in here
		
		
		
		
		
		
		
		
		
		return 0;
		
	}








