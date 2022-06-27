#include <stdio.h>
#include <stdlib.h>

/**
 * main - fonction give pq of n
 * @file: file with n numbers
 * Return: 0 if succed or 1 if fail.
 */

int main(int argc, char *argv[])
{
	FILE* fichier = NULL;
	unsigned long long int chiffre_actuel = 0, nombre = 0;

	fichier = fopen("tests/test00", "r");
	if (fichier != NULL)
	{
		do
		{
			chiffre_actuel = fgetc(fichier);
			if (chiffre_actuel == '\n')
			{
				chiffre_actuel = 2;
				do
				{
					if (nombre % chiffre_actuel == 0)
						printf("%lld=%lld*%lld\n", nombre, nombre / chiffre_actuel, chiffre_actuel);
					else
						chiffre_actuel += 1;
				}while (nombre % chiffre_actuel != 0);
				nombre = 0;
			}
			else if (nombre != 0)
				nombre = nombre * 10 + chiffre_actuel - 48;
			else
				nombre = chiffre_actuel - 48;
		}while (chiffre_actuel != EOF);
		fclose(fichier);
	}
	else
		printf("Impossible d'ouvrir le fichier");
	return (0);
}
