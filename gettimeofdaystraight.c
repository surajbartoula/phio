#include <stdio.h>
#include <sys/time.h>

int main()
{
	struct timeval 	tv;
	struct timezone tz;
	int		retval;

	retval = gettimeofday(&tv, &tz);
	if (retval == 0)
		printf("Seconds: %ld\nMicroseconds: %d\n", tv.tv_sec, tv.tv_usec);
	else
	 	perror("gettimeofday");
	return (0);
}
