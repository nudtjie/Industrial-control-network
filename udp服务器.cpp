#include<iostream>
#include<winsock.h> 
#include<stdio.h>
#define server_Port 1111
#define MAX 1024 
#pragma comment(lib, "Ws2_32.lib")
using namespace std;
int main()
{
	WORD sockVersion=MAKEWORD(2,2);
	WSADATA wsaData;
	if(WSAStartup(sockVersion,&wsaData)!=0) {
		printf("winsock加载失败！\n");
		return 1;
	}
	SOCKET socket_ser=socket(AF_INET,SOCK_DGRAM,0);
	if(socket_ser==INVALID_SOCKET)
	{
		printf("socket创建失败！：%d\n",WSAGetLastError());
		return 1;
	}
	sockaddr_in server;
	server.sin_family=AF_INET;
	server.sin_port=htons(server_Port) ;
	server.sin_addr.s_addr=htonl(INADDR_ANY);
	if(bind(socket_ser,(struct sockaddr*)& server,sizeof(server))==SOCKET_ERROR)
	{
		printf("捆绑失败：%d\n",WSAGetLastError());
		return 1;
	}
	printf("开始服务----\n"); 
	char receivemessage[1024];
	sockaddr_in client_addr;
	int len =sizeof(client_addr);
	while(1)
	{
		int set=recvfrom(socket_ser, receivemessage, 1, 0, (SOCKADDR *)&client_addr, &len);
        printf(receivemessage);
    }
}
