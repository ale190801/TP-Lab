#include<stdio.h>

unsigned int factorial_tail(unsigned int n, unsigned int x)
{
	if (n == 0)
		return x;
	return factorial_tail(n - 1, n*x);

}
unsigned int factorial(unsigned int n)
{
	return factorial_tail(n, 1);
}
unsigned int factorial_non_tail(unsigned int n)
{
	if (n == 0)
		return 1;
	return n * factorial_non_tail(n - 1);
}
unsigned int factorial_direct(unsigned int n)
{
	if (n <= 1)
		return 1;
	else
		return n * factorial_direct(n - 1);
}
unsigned int factorial_indirect1(unsigned int);
unsigned int factorial_indirect2(unsigned int);
unsigned int factorial_indirect1(unsigned int n)
{
	if (n <= 1)
		return 1;
	else
		return n * factorial_indirect2(n - 1);
}
unsigned int factorial_indirect2(unsigned int n)
{
	if (n <= 1)
		return 1;
	else
		return n * factorial_indirect1(n - 1);
}
int binary_search_recursive(int[], int, int, int);
int binary_search_recursive(int v[], int a, int b, int x)
{
	int mij;
	if (a > b)
		return -1;

	mij = (a + b) / 2;

	if (v[mij] == x)
		return mij;
	else if (x > v[mij])
		return binary_search_recursive(v, mij + 1, b, x);
	else
		return binary_search_recursive(v, a, mij - 1, x);
}
int suma_recursion(int);
int suma_recursion(int n)
{
	if (n != 0)
		return n + suma_recursion(n - 1);
	else
		return n;
}
int suma_for(int n)
{
	int i, suma = 0;
	for (i = 1; i <= n; i++)
		suma = suma + i;
	return suma;
	return 0;
}
int suma_while(int n)
{
	int i = 1;
	int suma = 0;
	while (i <= n)
	{
		suma = suma + i;
		++i;
	}
	return suma;
	return 0;

}
int suma_do_while(int n)
{
	int i = 1;
	int suma = 0;
	do
	{
		suma = suma + i;
		i++;
	} while (i <= n);
	return suma;
	return 0;
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partitie(int A[], int a, int b)
{
	int x = A[b];
	int i = a - 1;

	for (int j = a; j <= b - 1; j++)
	{
		if (A[j] <= x)
		{
			i++;
			swap(&A[i], &A[j]);
		}
	}
	swap(&A[i + 1], &A[b]);
	return (i + 1);
}

void quick_sort_recursive(int V[], int a, int b)
{
	if (a < b)
	{
		int q = partitie(V, a, b);
		quick_sort_recursive(V, a, q - 1);
		quick_sort_recursive(V, a + 1, b);
	}
}
void bubble_sort_recursive(int v[], int n)
{
	int i, aux;
	if (n == 1)
		return;
	for (i = 0; i < n - 1; i++)
		if (v[i] > v[i + 1])
		{
			aux = v[i];
			v[i] = v[i + 1];
			v[i + 1] = aux;
		}

	bubble_sort_recursive(v, n - 1);

}
int main()
{
	int n, factorial1, factorial2, factorial3, factorial4;
	int c, a, b, m, x, v[100], elem;
	int num;
	int vec[100], k, j;
	int vec2[100], l, z;
	enum { iesire, fact, binary_search, sum, quick_s, bubble_s }opt;
	do {
		printf("\n0.Iesire\n");
		printf("1.Calculul factorial\n");
		printf("2.Binary search\n");
		printf("3.Suma numerelor pana la N folosind o functie recursiva,for,while,do while\n");
		printf("4.QuickSort\n");
		printf("5.BubbleSort\n");
		scanf("%d", &opt);
		switch (opt)
		{
		case iesire:exit(0);
			break;
		case fact:printf("Dati valoarea numarului n:");
			scanf("%d", &n);
			factorial1 = factorial(n);
			printf("%d!=%d(folosind tail recursion)\n", n, factorial1);
			factorial2 = factorial_non_tail(n);
			printf("%d!=%d(folosind non-tail recursion)\n", n, factorial2);
			factorial3 = factorial_direct(n);
			printf("%d!=%d(folosind direct recursion)\n", n, factorial3);
			factorial4 = factorial_indirect1(n);
			printf("%d!=%d(folosind indirect recursion)\n", n, factorial4);
			break;
		case binary_search:printf("Dati numarul de elemente al vectorului:\n");
			scanf("%d", &m);

			printf("Scrieti elementele vectorului in ordine crescatoare\n");

			for (c = 0; c < m; c++)
				scanf("%d", &v[c]);

			printf("Ce element doriti sa cautati in vector\n");
			scanf("%d", &x);

			a = 0;
			b = m - 1;

			elem = binary_search_recursive(v, a, b, x);

			if (elem == -1)
				printf("Elementul dat nu exista in vector");
			else
				printf("%d se afla pe pozitia %d.\n", x, elem + 1);



			break;
		case sum:printf("Dati numarul:");
			scanf("%d", &num);
			printf("Suma numerelor pana la N folosind functia recursiva este:%d\n", suma_recursion(num));
			printf("Suma numerelor pana la N folosind for este:%d\n", suma_for(num));
			printf("Suma numerelor pana la N folosind while este:%d\n", suma_while(num));
			printf("Suma numerelor pana la N folosind do while este:%d\n", suma_do_while(num));

			break;
		case quick_s:printf("Dati numarul de elemente al vectorului:\n");
			scanf("%d", &k);
			printf("Scrieti elementele care urmeaza a fi sortate:\n");
			for (j = 0; j < k; j++)
				scanf("%d", &vec[j]);

			quick_sort_recursive(vec, 0, k - 1);
			printf("Vecorul sortat:\n");
			for (j = 0; j < k; j++)
				printf("%d\n", vec[j]);

			break;
		case bubble_s:printf("Dati numarul de elemente al vectorului:\n");
			scanf("%d", &z);
			printf("Scrieti elementele care urmeaza a fi sortate:\n");
			for (l = 0; l < z; l++)
				scanf("%d", &vec2[l]);

			bubble_sort_recursive(vec2, z);
			printf("Vecorul sortat:\n");
			for (l = 0; l < z; l++)
				printf("%d\n", vec2[l]);
			break;
		default:printf("Optiune gresita!\n");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}