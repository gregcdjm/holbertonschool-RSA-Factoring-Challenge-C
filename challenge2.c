#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include <limits.h>
#include <math.h>

/**
 * main - fonction give pq of n
 * @file: file with n numbers
 * Return: 0 if succed or 1 if fail.
 */

int main(int argc, char *argv[])
{
	FILE* fichier = NULL;
	unsigned long long int chiffre_actuel = 0;
	int tab[40], i = 0, tab2[40], n = 2, j = 0, r = 0, k = 0, p, t = 0, a;

	fichier = fopen("tests/test00", "r");
	if (fichier != NULL)
	{
		do
		{
			chiffre_actuel = fgetc(fichier);
			if (chiffre_actuel == '\n')
			{
			        printtab(tab, i);
				n = 2, t = 0, j=0, k = 0, p = 0, a = 1;
				while (p < 38)
				{
					tab2[p] = tab[p];
					p++;
				}
				while ((tab2[i-1] != 0 || j != i-1) || a == 1)
				{
					a = 0;
					if (tab2[j] >= n)
					{
					        tab2[j] -=n;
						k++;
						continue;
					}
					else if (tab2[j] == 0)
					{
						j++;
						k *= 10;
						continue;
					}
					else if (tab2[j] < n && j <= i-1)
					{
						tab2[j+1] = tab2[j]*10 + tab2[j+1], tab2[j] = 0;
						t++;
						j++;
						k *= 10;
						continue;
					}
					p = 0;
					while (p < 38)
					{
						tab2[p] = tab[p];
						p++;
					}
					n++, j = 0, k = 0;
					}
				printf("=%d*%d\n", k, n);
				i = 0;
				for (int m = 0; m < 37; m++)
					tab[m] = 0;
				for (int m = 0; m < 37; m++)
					tab2[m] = 0;
			}
			else
			{
				tab[i] = chiffre_actuel - 48;
				i++;
			}
		}while (chiffre_actuel != EOF);
		fclose(fichier);
	}
	return (0);
}
void printtab(int tab[], int t)
{
	int i = 0, a = 0;

	while (t > 0)
	{
		if (tab[0] != 0 || a == 1)
			printf("%d", tab[i]);
		else
			a = 1;
		t--;
		i++;
	}
}
/*void divnumber(int tab[], unsigned long long int n)
{
	int j = 0, r = 0, tab2[40];

	tab2 = copytab(tab);

	while (tab2[j])
	{
		if (tab2[j] > n)
		{
			r = tab2[j] % n;
			tab2[j] /= n;
			tab2[j+1] = r*10 + tab2[j+1];
		}
		else
			tab2[j+1] = tab2[j]*10 + tab2[j+1];
		j++;
	}
}
int* copytab(int tab[])
{

	int tab2[40], i = 0;

	while (tab[i])
	{
		tab2[i] = tab[i];
	}
	return (tab2);
}
*/
