#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define MAX_THREAD 4

int matriksA[4][5];
long long matriksB[4][5];

int iter =0;

void* faktorial(void *arg){

    for (int i = iter; i < (iter +1 ); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int simpanAngka = matriksA[i][j];
            long long faktorialMatriks= 0;
            for (int k = 1; k <= simpanAngka; k++)
            {
                faktorialMatriks += k ;
            }
            matriksB[i][j]=faktorialMatriks;
        }
        
    }
    iter++;
    

}

int main(){
    key_t key = 1234;
    int (*matriksShare)[10];

    int shmid = shmget(key,sizeof *matriksShare * 20, IPC_CREAT | 0666);
    matriksShare = shmat(shmid, NULL, 0);

    printf("Hasil :\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ",matriksShare[i][j]);
            matriksA[i][j]=matriksShare[i][j];
        }
        printf("\n");
    }

    pthread_t thread[MAX_THREAD];

    for (int i = 0; i < MAX_THREAD; i++) { 
        long long* p; 
        pthread_create(&thread[i], NULL, faktorial, (void*)(p)); 
    } 
  
    for (int i = 0; i < MAX_THREAD; i++)  
        pthread_join(thread[i], NULL); 

    printf("\nHasil Faktorial :\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%lld ",matriksB[i][j]);
        }
        printf("\n");
    }
    shmdt(matriksShare);
    //shmctl(shmid,IPC_RMID,NULL);

    
}
