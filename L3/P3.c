#include<stdio.h>
#define citire(x) scanf("%d",&x)
int suma_numere(int a, int b)
{
	int *suma, *p, *q;
	p = &a;
	q = &b;
	suma = *p + *q;
	return suma;
}
int main()
{
	int m, n, sum, v[20], i, k;
	printf("Primul numar este:");
	citire(m);
	printf("Al doilea numar este:");
	citire(n);
	sum = suma_numere(m, n);
	printf("Suma celor doua numere este:%d\n", sum);
	printf("Dati numarul de elemente ale vectorului:");
	scanf("%d", &k);
	for (i = 0; i < k; i++)
	{
		printf("v[%d]=", i);
		scanf("%d", &v[i]);
		printf("Vectorul v[%d] are valoarea %d si adresa %x\n", i, v[i], &v[i]);

	}
	int *x = &v[0];
	printf("Vectorul  are adresa %x si valoarea %d\n", x, *x);
	x++;
	printf("Dupa incrementare vectorul are adresa %x si valoarea %d\n", x, *x);
	int *y = &v[0];
	y--;
	printf("Dupa decrementare vectorul are adresa %x si valoarea %d\n", y, *y);
	return 0;
}