#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *threadFunction(void *arg)
{
    printf("Running thread with number %d\n", arg);
    pthread_exit(NULL);
}


int main() {
    int n = 5;
    pthread_t thread_id;

    for (int i = 0; i < n; i++)
    {
        printf("Created thread with number %d\n", i);
        pthread_create(&thread_id, NULL, threadFunction, (void *)i);
        pthread_join(thread_id, NULL);
    }
}