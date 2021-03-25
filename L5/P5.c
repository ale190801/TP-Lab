#include <stdio.h>
#define SIZE 100

int vec[SIZE];
int vf1 = -1;
int vf2 = SIZE;
int biti(int x)
{
	int n = 0, p = 1;
	do {
		n = n + (x % 2) * p;
		p = p * 10;
		x = x / 2;
	} while (x);
	return n;
}

void push_stiva1(int x)
{
	++vf1;
	if (SIZE > vf1)
		vec[vf1] = x;
	else
		printf("Stiva este plina");
}
void push_stiva2(int x)
{
	if (vf1 < vf2 - 1)
	{
		vec[--vf2] = x;
	}
	else
	{
		printf("Stiva este plina");
	}
}


void pop_stiva1()
{
	if (vf1 >= 0)
	{
		int x = vec[vf1--];

	}
	else
	{
		printf("Stiva este goala\n");
	}
}
void pop_stiva2()
{
	if (vf2 < SIZE)
	{
		int x = vec[vf2++];

	}
	else
	{
		printf("Stiva este goala\n");
	}
}


void afisare_stiva1()
{
	int i;
	printf("Prima stiva: ");
	for (i = 0; i <= vf1; i++)
	{
		printf("%d ", vec[i]);
	}
	printf("\n");
}
void afisare_stiva2()
{
	int i;
	printf("A doua stiva: ");
	for (i = SIZE - 1; i >= vf2; i--)
	{
		printf("%d ", vec[i]);
	}
	printf("\n");
}

int main()
{
	int vec[SIZE];
	int i, j, prim, k;




	for (i = 1; i <= 50; ++i)
	{

		push_stiva1(i);



		if (i == 1 || i == 0)
			continue;
		prim = 1;
		for (j = 2; j <= i / 2; j++)
		{

			if (i % j == 0) {
				prim = 0;
				break;
			}
		}

		if (prim == 1)
		{
			pop_stiva1(i);

			push_stiva2(biti(i));
		}


	}

	afisare_stiva1();
	afisare_stiva2();





	return 0;
}