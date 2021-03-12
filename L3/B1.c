#include<stdio.h>
#define cit(x) scanf("%d",&x)
int suma(int v[20], int n)
{
	int  sum = 0, i;
	int *p;
	p = v;

	for (i = 0; i < n; i++)
	{
		sum = sum + *p;
		p++;
	}
	return sum;

}
void swap(int** a, int** b)
{
	int* temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int v[20], n, sum, i, *a, *b;

	printf("Dati nr de elemete alea vectorului:");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("vec[%d]=", i);
		scanf("%d", &v[i]);
	}
	sum = suma(v, n);
	printf("Suma elementelor vectorului:%d\n", sum);
	printf("Primul numar este:");
	cit(a);
	printf("Al doilea numar este:");
	cit(b);
	swap(&a, &b);
	printf("Dupa interschimbare:%d %d", a, b);
}