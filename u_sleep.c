#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main()
{
    struct timeval start, end;

    gettimeofday(&start, NULL);
    usleep(500000);
    gettimeofday(&end, NULL);

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsedMilliseconds = (seconds * 1000) + (microseconds / 1000);
    printf("Expected sleep: 500 milliseconds\n");
}
