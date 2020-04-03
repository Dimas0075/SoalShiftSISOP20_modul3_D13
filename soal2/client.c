#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080

int main(int argc, char const *argv[]) {
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    char username[1024];
    char password[1024];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    while(1) {
	printf("1. Login \n");
	printf("2. Register \n");
	scanf("%s", buffer);
 
	if (strcmp(buffer, "Register") == 0){
	printf ("Username : ");
	scanf("%s", username);
	printf ("Password : ");
	scanf ("%s", password);	
	FILE *fileptr;
    	char id [30];
    	char name [47];
    	char amt[50];

    	fileptr = fopen("/home/dimas/Documents/Modul3/soal2/akun.txt", "a");
    	if (fileptr == NULL) {
        printf("File couldn't be opened\n\a\a");
        fclose(fileptr);
        exit(0);
    	}
    	fputs(username, fileptr);
	fputs(password, fileptr);
	fputs("\n", fileptr);
    	fclose(fileptr);
	printf("Register Berhasil \n");
	}

	else if (strcmp(buffer, "Login") == 0){
	FILE *fp = fopen("/home/dimas/Documents/Modul3/soal2/akun.txt","r");
	char guess[10];
 	char secret[10];
	char pass[20];
	char string[50];
	char *find;
	int i;

	if(fgets(secret, sizeof(secret), fp) == NULL)
	{
    	printf("Error while reading file\n");
    	return 0;
	}

	//fclose(fp);

	  printf("Username: ");
    	  scanf("%s", guess);
	  printf("Password: ");
	  scanf("%s", pass);
	  strcat(guess,pass);
   	  while(fgets(string, sizeof string, fp)){
	    if((find = strstr(string,guess)) || (find = strstr(string,pass)))
          {
              printf("ok");
          }
        else
          {
              printf("Still processing");
          }
        }
     }
    }
}
