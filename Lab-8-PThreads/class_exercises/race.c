#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS      100
#define LOOPS         10000

int sum = 0;
//pthread_mutex_t mutex;

void *pth_func() 
{
  int i;
  
  //pthread_mutex_lock(&mutex);
  
  for (i=0; i<LOOPS; i++)
    sum = sum + 1;
  
  //pthread_mutex_unlock(&mutex);
   
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  int i;
  pthread_t threads[NTHREADS];

  //pthread_mutex_init(&mutex, NULL);

  for (i=0; i<NTHREADS; i++)
    pthread_create(&threads[i], NULL, &pth_func, NULL);

  for (i=0; i<NTHREADS; i++)
    pthread_join(threads[i], NULL);

  printf ("Thread sum: %d\n", sum);

  sum=0;
  for (i=0;i<NTHREADS * LOOPS;i++)
    sum = sum + 1;
  printf("Check sum:  %d\n",sum);

  //pthread_mutex_destroy(&mutex);
  pthread_exit(NULL);
}
