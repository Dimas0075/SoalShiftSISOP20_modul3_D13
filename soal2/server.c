#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#define PORT 8080

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = (char*)"Hello from server";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    int val = 0;
    while (1) {
        memset(buffer, 0, 1024);
	read(new_socket, buffer, 1024);
	char* arr[] = {"touch","akun.txt", NULL};
	execv("/usr/bin/touch", arr);

      //if (strcmp(buffer, "tambah") == 0) {
        //val++;
        //strcpy(buffer, "penambahan berhasil");
        //printf("Nilai saat ini: %d", val);
      //} else if (strcmp(buffer, "cek") == 0) {
        //sprintf(buffer, "nilai: %d", val);
      //} else {
        //strcpy(buffer, "NO");
      //}

      //send(new_socket, buffer, 1024, 0);
    }
}
