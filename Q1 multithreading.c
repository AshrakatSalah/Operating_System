// CPP Program to find sum of random 5 numbers between 1 and 10
#include <stdio.h>
#include <pthread.h>

#define MAX 5
#define MAX_THREAD 5
  
int a[5];
int sum[5] = { 0 };
int part = 0;
  
void* sum_array(void* arg)
{
  
    int *thread_part = (int *)arg;
	int i=0;
  for(i=0; i<MAX;i++)
  {
	  scanf("%d", &a[i]);
  }
  
    for ( i = thread_part * (MAX / 5); i < (thread_part + 1) * (MAX / 5); i++){
	sum[thread_part] += a[i];
	}
}
  
int main()
{
  
    pthread_t threads[MAX_THREAD];
  int i, j, y;
    for ( i = 0; i < MAX_THREAD; i++)
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL);
  
    for ( j = 0; i < MAX_THREAD; i++)
        pthread_join(threads[i], NULL);
  
    int total_sum = 0;
    for ( y = 0; i < MAX_THREAD; i++)
        total_sum += sum[i];
  
    printf( "sum is : %d ", total_sum);
  
    return 0;
}
