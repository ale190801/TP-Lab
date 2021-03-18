#include <stdio.h>
#define MAX_SIZE 100
#define defaultValue -1
int V_Stiva[MAX_SIZE];
int Vf = -1;
int inversare_biti(int num)
{

	int  nr_inv = 0, i, x;

	for (i = 0; i < 8; i++)
	{
		x = (num & (1 << i));
		if (x)
			nr_inv |= (1 << ((8 - 1) - i));
	}

	return nr_inv;
}
int stiva_goala()
{
	if (Vf == -1)
		return(1);
	return(0);
}
int stiva_plina()
{
	if (Vf == MAX_SIZE - 1)
		return(1);
	return(0);
}
void push(int x)
{
	++Vf;
	if (MAX_SIZE > Vf)
		V_Stiva[Vf] = x;
	else
		printf("Stiva este plina");
}
int pop()
{
	int a;
	a = V_Stiva[Vf];
	V_Stiva[Vf] = defaultValue;
	Vf--;
	return a;
}
void afisare()
{
	int i;
	printf("\nStiva: ");
	for (i = 0; i <= Vf; i++)
	{
		printf("%d ", V_Stiva[i]);
	}
	printf("\n");
}
int main()
{
	int i, j, k, l, v[20], N, a, b, c;
	printf("Dati nr de elemete ale vectorului:");
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		printf("vec[%d]=", i);
		scanf("%d", &v[i]);

		printf("Numarul care urmeaza a fi inversat:%d\n", v[i]);
		printf("Numarul care urmeaza a fi inversat are forma binara:");
		for (j = 7; j >= 0; j--)
		{
			a = (v[i]) >> j;
			if ((a & 1))
				printf("1");
			else
				printf("0");

		}
		printf("\n");
		printf("Numarul inversat este: %u.\n", inversare_biti(v[i]));
		printf("Numarul inversat are forma binara:");

		for (k = 7; k >= 0; k--)
		{
			b = (inversare_biti(v[i])) >> k;
			if ((b & 1))

			{
				printf("1");
			}
			else
			{
				printf("0");
			}


		}
		printf("\n");
		for (l = 7; l >= 0; l--)
		{
			c = (inversare_biti(v[i])) >> l;
			if ((c & 1))
			{
				push(1); afisare();
			}
			else
			{
				push(0); afisare();
			}


		}
		printf("\n");

	}
}