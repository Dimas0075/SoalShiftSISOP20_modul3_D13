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

int matrikA[4][2] ={
    {2,8},
    {8,2},
    {1,3},
    {2,5}
};
int matrikB[2][5]= {
    {6,0,5,5,4},
    {0,4,3,1,3}
};
int matrikC[4][5];
int iter =0;

void* perkalianMatriks(void *arg)
{
    
    for (int i = iter ; i < (iter + 1) ; i++){
        for(int j = 0; j < 5; j++){
            for(int k =0; k < 2; k++){
                matrikC[i][j] += matrikA[i][k] * matrikB[k][j];
         
            }
        }   
    }
    iter++;
}

int main(void)
{
    key_t key = 1234;
    int (*matriksShare)[10];

    int shmid = shmget(key,sizeof *matriksShare * 20, IPC_CREAT | 0666);
    matriksShare = shmat(shmid, NULL, 0);
    
    printf("MatriksA :\n");
    for(int i = 0; i < 4 ; i ++){
        for(int k = 0; k < 2; k++){
            printf("%d ", matrikA[i][k]);
            
        }
        printf("\n");
    }

    printf("\nMatriksB :\n");
    for(int k = 0; k < 2 ; k ++){
        for(int j = 0; j < 5; j++){
            printf("%d ", matrikB[k][j]);
            
        }
        printf("\n");
    }

    pthread_t thread[MAX_THREAD];

    for (int i = 0; i < MAX_THREAD; i++) { 
        int* p; 
        pthread_create(&thread[i], NULL, perkalianMatriks, (void*)(p)); 
    } 
  
    for (int i = 0; i < MAX_THREAD; i++)  
        pthread_join(thread[i], NULL);     

    printf("\nHasil :\n");
    for(int i =0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            matriksShare[i][j]=matrikC[i][j];
            printf("%d ", matriksShare[i][j]);
            
        }
        printf("\n");
    }

    shmdt(matriksShare);
  //return 0;

}
