/*
    Compiling instructions
    gcc -o pemex pemex.c -lpthread -lrt
*/

// hacky code for running it on windows or linux. Thanks to reddit stranger https://www.reddit.com/r/C_Programming/comments/44hsrr/c_programming_in_windows_with_semaphores/
#ifdef __WIN32
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
typedef HANDLE sem_t;
#define sem_init(s, p, v) *(s) = CreateSemaphore(NULL, v, LONG_MAX, NULL)
#define sem_wait(s) WaitForSingleObject(*(s), INFINITE)
#define sem_post(s) ReleaseSemaphore(*(s), 1, NULL)
#define sem_destroy(s) CloseHandle(*(s))
#else
#include <semaphore.h>
#endif

#include <pthread.h>


//includes that are not related to threading stuff
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// definitions
#define NCLIENTS 5
#define DELAYREQUESTS 30000 //miliseconds
#define NREQUESTS 5
#define LIMITPRODUCTION 20


//define functions
void getTime();

//define variables
int counter_requests = 0;
int pemex_production = 10;

//init stuff
sem_t mutex; 


void *threadproc(void *arg)
{
    Sleep(2000);
    printf("Spawning pemex thread \n");   
    while(counter_requests < NREQUESTS)
    {
        getTime();
        pemex_production =  pemex_production + rand() % LIMITPRODUCTION;
        printf("Pemex has an inventory of %d liters \n",pemex_production);
        int i;
        for (i=0; i<NCLIENTS; ++i){
            sem_post(&mutex); 
        }
        Sleep(DELAYREQUESTS);
        counter_requests++;
    }
    exit(1);
}


void *threadComsumers(void *arg)
{
    do{
        sem_wait(&mutex); 
        int tid;
        tid = *((int *) arg);
        int order = rand() % (pemex_production);
        pemex_production = pemex_production - order;
        printf("Client %d! has bought %d. Liters that are available %d \n ", tid, order, pemex_production);
    }while(1);
}



void getTime()
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ( "Pemex is delivering! Current local time and date: %s", asctime (timeinfo) );
}

int main(void){
    sem_init(&mutex, 0, 0); 
    pthread_t tid;
    pthread_create(&tid, NULL, &threadproc, NULL);
    
    pthread_t threads[NCLIENTS];
    int thread_args[NCLIENTS];
    int rc, i;
    /* spawn the threads */
    for (i=0; i<NCLIENTS; ++i)
    {
      thread_args[i] = i;
      printf("spawning client %d\n", i);
      rc = pthread_create(&threads[i], NULL, threadComsumers, (void *) &thread_args[i]);
    }
    while(1){
        
    }
    return 0;
}