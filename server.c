
//Based on man 2 bind example code:

	#include <sys/socket.h>
	//#include <sys/un.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <sys/types.h>
	#include <unistd.h>
	
	//for ip
	#include <netinet/in.h>
	#include <netinet/ip.h> /* superset of previous */
	
	
	#include <sys/stat.h>
	#include <fcntl.h>
	
	//for PATH_MAX
	#include <limits.h>
	
	
	//#define MY_SOCK_PATH "/somepath"
	//#define MY_SOCK_PATH "/student/khanim/3500/Studio/Studio25/serverSocket"
	#define MY_SOCK_PATH "serverSocket"
	#define LISTEN_BACKLOG 50
	//#define bufferSize 1000
	#define bufferSize 2000
	#define otherbuffSize 100
	
	#define handle_error(msg) \
		do { perror(msg); exit(EXIT_FAILURE); } while (0)

	int main(int argc, char *argv[])
	{
		if(argc!=2){
			printf("Incorrect number of arguments\n");
			printf("Server needs port number\n");
			printf("server <port number>\n");
			exit(1);
		}
		int port = atoi(argv[1]);
		
		int sfd, cfd;
		struct sockaddr_in my_addr, peer_addr;
		socklen_t peer_addr_size;
		int ret;
		int openfd;
		int shut;
		
		sfd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
		//if (sfd == -1)
		//	handle_error("socket");
		if (sfd == -1){
			perror("socket");
			exit(1);
		}
		
		memset(&my_addr, 0, sizeof(struct sockaddr_in));
			/* Clear structure */
		my_addr.sin_family = AF_INET;
		my_addr.sin_port = port;
		
		//strncpy(my_addr.sun_path, MY_SOCK_PATH,
			//sizeof(my_addr.sun_path) - 1);

		if (bind(sfd, (struct sockaddr *) &my_addr,
			sizeof(struct sockaddr_in)) == -1){
			perror("bind");
			exit(1);
			//handle_error("bind");
		}

		if (listen(sfd, LISTEN_BACKLOG) == -1){
			perror("listen");
			exit(1);
			//handle_error("listen");
		}

		/* Now we can accept incoming connections one
			at a time using accept(2) */

		//peer_addr_size = sizeof(struct sockaddr_in);
		
		//char buffer2 [bufferSize];
		while(1){
			peer_addr_size = sizeof(struct sockaddr_in);
			//cfd = accept(sfd, (struct sockaddr *) &peer_addr,
			//	&peer_addr_size);
			cfd = accept4(sfd, (struct sockaddr *) &peer_addr, &peer_addr_size, SOCK_NONBLOCK);

			/*
			if (cfd == -1){
				perror("accept");
				exit(1);
				//handle_error("accept");
			}

			
			printf("New client connected at %d\n", cfd);
			*/

			if(cfd>0){
				//push_list(cfd);
				printf("New client connected at %d\n", cfd);
			}
			
			/* Code to deal with incoming connection(s)... */
			
			
			//Can do like the following to keep track of clients
			//struct list_node* curr = head;
			
			//More code in here
			
			
		}
		
		/* When no longer required, the socket pathname, MY_SOCK_PATH
			should be deleted using unlink(2) or remove(3) */
		
		
		ret = unlink(MY_SOCK_PATH);
		if(ret==-1){
			perror("unlink");
			exit(1);
		}
		
		
		
		return 0;
		
	}




