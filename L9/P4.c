#include<stdio.h>



int cautare_element(int M[10][10], int a, int b,int m, int n, int x)
{
	int i, j,contor=0;
	i = a + (b - a) / 2;
	j = m + (n - m) / 2;

	if (M[i][j] == x)
	{
		printf("Am gasit elementul %d!\n", x);
		
	}

		else
			if (M[i][j] != x)

			{
             	if (i != b || j != m)
					cautare_element(M, a, i, j, n, x);


				if (M[i][j] < x)
				{
					if (i + 1 <= b)
						cautare_element(M, i + 1, b, m, n, x);

				}

				else
				{
					if (j - 1 >= m)
						cautare_element(M, a, b, m, j - 1, x);

				}
				if (a == b && m + 1 == n)
					if (M[a][n] == x)
						printf("Am gasit elementul %d!\n", x);
				

         	}
	
	
}


int main()
{
	int A[10][10];
	int i, j, l, c,x,n,k;

	printf("Introdu numarul de linii si de coloane:");
	scanf("%d %d", &l,&c);
	

	printf("\nDati elementele matricei in ordine crescatoare pe linii si pe coloane :\n");
	for (i = 0; i < l; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf(" A[%d,%d] : ", i , j );
			scanf("%d", &A[i][j]);
		}
	}
	printf("\nMatricea introdusa este:\n");
	for (i = 0; i < l; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d\t", A[i][j]);
		}
		printf("\n");  
	}

	printf("Dati elementul pe care doriti sa l cautati:");
	scanf("%d", &x);
    cautare_element(A,0,l-1,0,c-1,x);
	
	
	return 0;
	
	
			
	
}
