#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void	*thread_function(void *arg)
{
	int thread_num = *(int *)arg;
	printf("Thread %d is running\n", thread_num);
	sleep(1);
	printf("Thread %d is done\n", thread_num);
	return (NULL);
}

int	main()
{
	pthread_t	thread1, thread2;
	int thread_num1 = 1;
	int thread_num2 = 2;

	pthread_create(&thread1, NULL, thread_function, &thread_num1);
	pthread_create(&thread2, NULL, thread_function, &thread_num2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("All threads are done\n");

	return (0);
}
