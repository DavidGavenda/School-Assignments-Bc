// 98533_BLOK3.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma warning(disable:4996)

#pragma comment(lib, "Ws2_32.lib")

void gotoxy(int x, int y);
int prvocislo(int cislo);

int main()
{
	//zmena farby textu a vypis slovenciny
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	FILE *f;
	f = fopen("vysledok.txt","a");


	// prva cast = pripojenie 

	WSADATA wsaData;
	int iResult;
	int nic = 0;
	int x = 0,i,j=0;

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		printf("WSAStartup failed: %d \n", iResult);
		return 1;
	}

	struct addrinfo *result = NULL, *ptr = NULL;
	struct addrinfo hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	iResult = getaddrinfo("147.175.115.34", "777", &hints, &result);
	if (iResult != 0)
	{
		printf("getaddrinfo failed: %d \n", iResult);
		WSACleanup();
		return 1;
	}
	else
	{
		//printf("gettaddrinfo worked... \n");
		//x = x + 1;
	}

	// druha cast

	SOCKET ConnectSocket = INVALID_SOCKET;
	ptr = result;


	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

	if (ConnectSocket == INVALID_SOCKET)
	{
		printf("Error at socket() : %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		x = x + 1;
		return 1;
	}
	else
	{
		//printf("Error at socket worked\n");
		//x = x + 1;
	}


	iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);

	if (iResult == SOCKET_ERROR)    
	{
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
		WSACleanup();
		return 1;
	}

	Sleep(250);
	char sendbuf[4096]="98533"; //aby som sa stale nemusel prihlasovat

	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	if (iResult == SOCKET_ERROR)
	{
		printf("send failed : %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}


	// cast styri prijimanie


#define DEFAULT_BUFLEN 4096 //makro, kde definujeme velkost prijimacieho buffera

	int recvbuflen = DEFAULT_BUFLEN;
	char recvbuf[DEFAULT_BUFLEN];


	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);     //funkcia na príjimanie

	for (int i = 1; i < strlen(recvbuf); i++) //skontrolujem a najdem koniec
	{
		if ((recvbuf[i] == '\n'))
		{

			recvbuf[i] = '\0';
			i = i + 1;
		}
	}

	gotoxy(100, x); //posuniem sa a vypisem
	printf("%s", recvbuf);
	if (strlen(recvbuf) > 100) x = x + (strlen(recvbuf) / 100);
	x = x + 1;
	gotoxy(0, x);

	while (1)
	{


		

		//moje zoradenie
		gotoxy(0, x); //napisem nieco co chcem poslat
		fgets(sendbuf, 1024, stdin);
		if (strlen(sendbuf) < 2) break;
		fprintf(f, "David: %s\n", sendbuf);

		sendbuf[strlen(sendbuf)+1] ='\0';
		//printf("'%s'",sendbuf);
		x = x + 1;

		iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0); //odoslem to
		if (iResult == SOCKET_ERROR)
		{
			printf("send failed : %d\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
			return 1;
		}

		iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);     //funkcia na príjimanie

		gotoxy(100, x); //posuniem sa a vypisem
		x = x + 1;
		fprintf(f, "Morpheus: ");
		if (iResult == 129)
		{

			for (i = 0;i < 129;i++)
			{
				recvbuf[i] = recvbuf[i] ^ 55;
				printf("%c", recvbuf[i]);
				fprintf(f, "%c", recvbuf[i]);
				j = j + 1;
				if ((recvbuf[i] == ' ') && (j + 10 > 90) && (i >= 100))
				{
					j = 0;
					//x = x + 1;
					gotoxy(100, x);
					x = x + 1;
				}
			}
		}
		
		
		else if (iResult == 23)
		{

			for (i = 0;i < strlen(recvbuf);i++)
			{
				if (prvocislo(i + 1) == 1)
				{
					printf("%c", recvbuf[i]);
					fprintf(f, "%c", recvbuf[i]);
				}
				
			}
			x = x + 1;
		}
		

		else
		{
			for (int i = 1; i < strlen(recvbuf); i++) //skontrolujem a najdem koniec
			{
				if ((recvbuf[i] == '\n'))
				{

					recvbuf[i] = '\0';
					i = i + 1;
				}
			}

			for (i = 0;i < strlen(recvbuf);i++)
			{
				printf("%c", recvbuf[i]);
				fprintf(f, "%c", recvbuf[i]);
				j = j + 1;
				if ((recvbuf[i] == ' ') && (j + 10 > 90) && (i >= 100))
				{
					j = 0;
					//x = x + 1;
					gotoxy(100, x);
					x = x + 1;
				}
			}
		}
		x = x + 1;


		Sleep(250);
		fprintf(f, "\n");
	}
	//zavretie socketu

	fclose(f);
	closesocket(ConnectSocket);
	WSACleanup();
	return 0;
}

void gotoxy(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int prvocislo(int cislo)
{
	int i;
	if (cislo <= 1) return 0;
	if ((cislo % 2 == 0) && (cislo > 2)) return 0;
	for (i = 3;i < cislo / 2;i = i + 2)
	{
		if (cislo %i == 0) return 0;
	}
	return 1;
}