#include<stdio.h>
#include <stdlib.h>

#define NAME "a.txt"
#define A 8
#define B 8
void floodFill_1(int v[][B], int x, int y, int culoarea1, int culoarea2)
{

	if (x < 0 || x >= A || y < 0 || y >= B)
		return;
	if (v[x][y] != culoarea1)
		return;
	if (v[x][y] == culoarea2)
		return;


	v[x][y] = culoarea2;


	floodFill_1(v, x + 1, y, culoarea1, culoarea2);
	floodFill_1(v, x - 1, y, culoarea1, culoarea2);
	floodFill_1(v, x, y + 1, culoarea1, culoarea2);
	floodFill_1(v, x, y - 1, culoarea1, culoarea2);
}


void floodFill(int v[][B], int x, int y, int culoarea2)
{
	int culoarea1 = v[x][y];
	floodFill_1(v, x, y, culoarea1, culoarea2);
}

int main()
{
	FILE *f;
	int n, m, i, j;
	int x = 7, y = 6, culoarea_noua = 5;
	int v[A][B];

	f = fopen(NAME, "r");
	if (f == NULL) {
		printf("Fisierul nu poate fi deschis!");
	}


	for (i = 0; i < A; i++)
		for (j = 0; j < B; j++)
			fscanf(f, "%d", &v[i][j]);
	printf("Matricea inainte de schimbarea culorii:\n");
	for (i = 0; i < A; i++) {
		for (j = 0; j < B; j++)
			printf("%d ", v[i][j]);
		printf("\n");
	}
	printf("Pentru cifra 0 avem culoarea rosu!\n");
	printf("Pentru cifra 1 avem culoarea verde!\n");
	printf("Pentru cifra 2 avem culoarea albastru!\n");
	floodFill(v, x, y, culoarea_noua);
	printf("Pentru culoarea 5 vom avea culoarea mov ,iar aceasta se va afla in locul culorii albastru!\n");
	printf("Afisarea matricei dupa schimbarea culorii: \n");
	for (int i = 0; i < A; i++)
	{
		printf("\n");
		for (int j = 0; j < B; j++)

			printf("%d ", v[i][j]);

	}
	fclose(f);
	return 0;

}