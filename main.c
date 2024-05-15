#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define M 4096
#define N 4096

double A[M][N], x[N], y[M];

double second()
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ts.tv_sec + (double)(ts.tv_nsec) / 1.0e9;
}

int main()
{
	double start = second();
	int m = 0;
#pragma omp parallel for
	for (m = 0; m < M; m++)
	{
		y[m] = 0;
		int n = 0;
		for (n = 0; n < N; n++)
		{
			y[m] += A[m][n] * x[n];
		}
	}
	double end = second();
	printf("%f", end - start);
}