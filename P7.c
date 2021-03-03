#include<stdio.h>
int main()
{
	int N, x, i, sum,j;
	printf("N=");
	scanf("%d", &N);
	sum = 0;
	for (i = 0; i < N; i++) {
		scanf("%d", &x);
		for (j = 0; j < 32; j++)
			if (x&(1 << j))
				sum = sum + 1;
		
	}
	printf("Suma numerelor date este:%d", sum);
	return 0;
}
	
