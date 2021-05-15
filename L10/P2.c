#include<stdio.h>

int minimFibonacci(int k) {
	int v[45];
	v[0] = v[1] = 1;
	for (int i = 2; i < 45; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}
	int x = 0;
	for (int i = 44; i >= 0; i--) {
		if (k >= v[i]) {
			k -= v[i];
			x++;
		}
		if (k == 0) 
			break;
	}
	return x;
}
int main()
{
	int k, n;
	printf("Dati numarul k:");
	scanf("%d", &k);
	n=minimFibonacci(k);
	printf("%d\n", n);
	system("pause");
	return 0;
}