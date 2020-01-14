#include <stdio.h>

typedef struct {
	int I = 1;
	int V = 5;
	int X = 10;
	int L = 50;
	int C = 100;
	int D = 500;
	int M = 1000;
	int n = 7;
} charactor;

int main(int argc, char const *argv[])
{
	charactor dict;

	printf("%d\n", dict.I);	

	return 0;
}
