#include <stdio.h>
#include <sys/time.h>

int	main()
{
	struct timeval	currentTime;
	gettimeofday(&currentTime, NULL);

	printf("Seconds: %ld\n", currentTime.tv_sec);
	printf("Microseconds: %ld\n", currentTime.tv_usec);
	printf("Hours: %ld\n", currentTime.tv_sec / 3600);
}
