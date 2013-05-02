#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int global = 0;

void* pth_func(void *arg) 
{
  printf("%i - t: Hello %i, sleeping for 5s \n", ++global, getpid());
  sleep(5);
  printf("%i - t: Ok, slept.\n", ++global);
  return NULL;
}

int main(void) 
{

  pthread_t pth;
  
  printf("%i - begin pid: %i \n", ++global, getpid());

  if ( pthread_create(&pth, NULL, pth_func, NULL) ) 
  {
    printf("error creating thread.");
    exit(-1);
  }
  else
    printf("%i - New thread generated.\n", ++global);

  printf("%i - Main process is here, waiting for thread termination.\n", ++global);

  if ( pthread_join(pth, NULL) )
  {
    printf("%i - error joining thread.\n", ++global);
    exit(-1);
  }

  printf("%i - end pid: %i\n", ++global, getpid());
    
}
