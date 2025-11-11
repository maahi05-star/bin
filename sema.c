#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

sem_t mutex, wrt;
pthread_t tid;
int sharedvar = 99;
pthread_t writers[5], readers[5];
int readercount = 0;

void *reader(void* pram)
{
    sem_wait(&mutex);
    readercount++;
    if(readercount == 1)
    {
        sem_wait(&wrt);
    }
    sem_post(&mutex);

    printf("\n%d readers is reading sharedvar = %d", readercount, sharedvar);

    sem_wait(&mutex);
    readercount--;
    if(readercount == 0)
    {
        sem_post(&wrt);
    }
    sem_post(&mutex);
    printf("\n%d reader is done", readercount + 1);
   
}

void *writer(void* param)
{
    printf("\n writer is trying to enter");
    sem_wait(&wrt);
    printf("\n writer entered critical section");
    sharedvar++;
    printf("\n writer changed the value of shared var to %d", sharedvar);
    sem_post(&wrt);
    printf("\n writer is out of critical section");

}

int main()
{
    int n2, i;
    printf("Enter the number of readers:");
    scanf("%d", &n2);
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for(i = 0; i < n2; i++)
    {
        pthread_create(&writers[i], NULL, writer, NULL);
        pthread_create(&readers[i], NULL, reader, NULL);
    }

    for(i = 0; i < n2; i++)
    {
        pthread_join(writers[i], NULL);
        pthread_join(readers[i], NULL);
    }
}

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 5

int buffer[SIZE], in = 0, out = 0;
sem_t mutex, empty, full;

void* producer(void* arg) {
    for(int item = 1; item <= 5; item++) {
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % SIZE;

        sem_post(&mutex);
        sem_post(&full);
    }
}

void* consumer(void* arg) {
    for(int i = 1; i <= 5; i++) {
        sem_wait(&full);
        sem_wait(&mutex);

        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % SIZE;

        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main() {
    pthread_t p, c;

    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}
