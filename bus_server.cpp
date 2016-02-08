#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT					10212

class server_info
{
		int 						sockfd;
		int 						newsockfd;
		int 						portno;

		int 						n;

		socklen_t					clilen;

		char 						buffer[256];

		struct sockaddr_in			serv_addr;
		struct sockaddr_in			cli_addr;

		void configure_socket(void);
		void server_active(void);
		void error(const char *msg);
};

void server_info::configure_socket(void)
{
		sockfd = socket(AF_INET, SOCK_DATA, 0);
		if(sockfd < 0)
		{
				cout<<endl<<"Error on creating socket"<<endl;
		}

		bzero((char*) &serv_addr, sizeof(serv_addr));
		portno = atoi(SERVER_PORT);

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_addr.s_addr = INADDR_ANY;
		serv_addr.sin_port = htons(portno);

		if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		{
				cout<<endl<<"Error on bind"<<endl;
		}
}

void server_info::server_active(void)
{
		listen(sockfd,5);
		clilen = sizeof(cli_addr);
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if(newsockfd < 0)
		{
				cout<<endl<<"Error on accept"<<endl;
		}

        bzero(buffer,256);
        n = read(newsockfd,buffer,255);

        if (n < 0) 
			error("ERROR reading from socket");

        printf("Here is the message: %s\n",buffer);
        n = write(newsockfd,"I got your message",18);

        if (n < 0) 
			error("ERROR writing to socket");

        close(newsockfd);
        close(sockfd);

}

void server_info::error(const char *msg)
{
    perror(msg);
    exit(1);
}


int main(int argc, char *argv[])
{
     return 0; 
}class bus_server {
