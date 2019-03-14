#include<iostream>
#include<winsock.h> 
#include<stdio.h>
#define server_addr_Port 1111
#define server_addr_IP "127.0.0.1"
#pragma comment(lib, "Ws2_32.lib")
using namespace std;
int main()
{
	WORD sockVersion=MAKEWORD(2,2);
	WSADATA wsaData;
	if(WSAStartup(sockVersion,&wsaData)!=0) {
		return 0;
	}
    SOCKET client=socket(AF_INET,SOCK_DGRAM,0);
	if(client==INVALID_SOCKET)
	{
		printf("socket error!\n");
		return 0;
	}
	sockaddr_in server_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(server_addr_Port) ;
	server_addr.sin_addr.s_addr=inet_addr(server_addr_IP);
	FILE *fp=fopen("com3","r");
	char temp;
	int size=sizeof(server_addr);
	while(1)
	{
		temp=0;
	    fscanf(fp,"%c",& temp);
		if(temp!=0)
		{
			putchar(temp);
			int set=sendto(client,& temp, 1, 0, (SOCKADDR *)&server_addr, sizeof(server_addr));	
		}	
	}
	fclose(fp);
    closesocket(client);
	WSACleanup();
	return 0;
}
