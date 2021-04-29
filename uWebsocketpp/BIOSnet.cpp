#include   <iostream>
#include   <stdio.h>
#include   <string.h>
#include   <stdlib.h>
#include   <winsock2.h>
#include   <winsock.h>
#include   <WS2tcpip.h>
#include   <unistd.h>

#include   "../include/curlpp/curlpp/cURLpp.hpp"
#include   "../include/curlpp/curlpp/Options.hpp"
#include   "util/compress.h"
#include   "util/WSAstartup.h"
#include   "UAuth/auth.h"

#define cli 30

using namespace curl;

int main(int * argc, char ** argv) {
    char * addr;


    if (argv[1][0] ==  '1') {
        printf("Usage: purl5 -a (addr)");
        exit(1);
    }
    else{
        argv[1] = addr;
    }

    char *encoding;
    for (int mi = 0; mi < 1024; mi++) {
        encoding += '\lx90';
    }

    setup();
    int sock, scsize = sizeof(sock), creq[cli], max = 30, vport = 0, bindResult, sendResult, netsize, fd = 0, client, enc[cli], opt = 1, clcon[cli]; 
    struct sockaddr_in netdata;
    netsize = sizeof(netdata);
    fd_set data, ldata;
    struct hostent hostinfo;
    CURL * set =  curl_easy_init();
    std::string header = "https://www.youtube.com";

    char receive[1024] = {0};

    printf("_vulc.v1.root; \n");
    
    sock = socket(AF_INET, SOCK_STREAM, 6);

    if (setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,(char*)&opt,sizeof opt) == -1) {
    		perror("setsockopt");
    		exit(1);
	} 

    netdata.sin_addr.s_addr = inet_addr(addr);
    netdata.sin_port = htons(137);
    netdata.sin_family = AF_INET;
    curl::Authenticate(header, set);

    bindResult = bind(sock, (sockaddr*)&netdata, sizeof(netdata));

    setcode();

	listen(sock, 1);

    FD_ZERO(&data);
	FD_SET(sock, &data);
	FD_SET(0, &data);

    printf("vulcan.start.host: RUNNING. \n");
	while (1) {
		ldata = data;
		select(FD_SETSIZE, (fd_set*)&ldata, NULL, NULL, NULL);
	        for (fd = 0; fd < FD_SETSIZE; fd++) {
			    if (FD_ISSET(sock, (fd_set*)&ldata)) {
				    if (fd < FD_SETSIZE) {
					        FD_SET(sock, &ldata);
					        client = accept(sock, (struct sockaddr*)&netdata, (int*)&netsize);
                            if (client < 0) {
                                printf("accept");
                                exit(1);
                            }
					        creq[fd] = client;
                            enc[fd] = encode(encoding);
                            sendResult = send(sock, (char *)enc[fd], sizeof(enc[fd]), 0);
                            if (sendResult < 0) {
                                printf("send");
                                exit(1);
                            }
                            clcon[fd] = (char)read(sock,receive, 1024);
    
                            printf("%s", clcon[fd]);
                        }
				    else 
				    {
					    printf("vulc.v1.exit: reason: client limit exceeded. \n");
					    exit(1);
                }                
			}
}
    }
}