#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h>


int main(){

    int pipe1[2];

    pid_t p;

    if(pipe(pipe1)==-1){
        exit(1);
    }
    p=fork();

   // parent proses
    if(p > 0){
        
        dup2(pipe1[0],0);

        close(pipe1[0]);
        close(pipe1[1]);

        char *argv[]={"wc","-l",NULL};
        execv("/usr/bin/wc", argv);
    
    }

    //child proses
    else{

        dup2(pipe1[1],1);

        close(pipe1[0]);
        close(pipe1[1]);

        char *argv[]={"ls","/home/herri/Documents/soalShift3/soal4/",NULL};
        execv("/bin/ls", argv);


    }
}