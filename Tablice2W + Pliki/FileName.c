#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypelnijTabLosowo(int tab[][10], int wiersze, int kolumny);
void pokazTab(int tab[][10], int wiersze, int kolumny);
void zerujTab(int tab[][10], int wiersze, int kolumny);

void zapiszTabDoPliku(const char* fileName, int tab[][10], int kolumny, int wiersze);
void wczytajTabZPliku(const char* fileName, int tab[][10], int kolumny, int wiersze);

int main()
{	
	int wiersze, kolumny;
	int Tablica[10][10];

	printf("Podaj wymiary tablicy: ");
	scanf_s("%d %d", &wiersze, &kolumny);
	if(kolumny > 10 || wiersze > 10)
	{
		printf("Wymiary tablicy sa zbyt duze.\n");
		return EXIT_FAILURE;
	} 

	srand((unsigned int)time(NULL));
	wypelnijTabLosowo(Tablica, wiersze, kolumny);
	pokazTab(Tablica, wiersze, kolumny);
	zapiszTabDoPliku("tablica.bin", Tablica, kolumny, wiersze);

	zerujTab(Tablica, wiersze, kolumny);
	pokazTab(Tablica, wiersze, kolumny);

	printf("Wczytywanie tablicy z pliku...\n");
	wczytajTabZPliku("tablica.bin", Tablica, kolumny, wiersze);
	pokazTab(Tablica, wiersze, kolumny);

	return EXIT_SUCCESS;
}

void wypelnijTabLosowo(int tab[][10], int wiersze, int kolumny)
{
	for (int i = 0; i < wiersze; i++)
		for (int j = 0; j < kolumny; j++)
			tab[i][j] = rand() % 100;
}

void pokazTab(int tab[][10], int wiersze, int kolumny)
{
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
			printf("%d ", tab[i][j]);
		printf("\n");
	}
}

void zerujTab(int tab[][10], int wiersze, int kolumny)
{
	puts("");
	for (int i = 0; i < wiersze; i++)
		for (int j = 0; j < kolumny; j++)
			tab[i][j] = 0;
}

void zapiszTabDoPliku(const char* fileName, int tab[][10], int kolumny, int wiersze)
{
	FILE* plik = fopen(fileName, "wb");
	if (plik == NULL)
	{
		printf("Nie mozna otworzyc pliku %s do zapisu.\n", fileName);
		return;
	}

	for (int i = 0; i < wiersze; i++)
		for (int j = 0; j < kolumny; j++)
			fwrite(&tab[i][j], sizeof(int), 1, plik);
	fclose(plik);
}

void wczytajTabZPliku(const char* fileName, int tab[][10], int kolumny, int wiersze)
{
	FILE* plik = fopen(fileName, "rb");
	if (plik == NULL)
	{
		printf("Nie mozna otworzyc pliku %s do odczytu.\n", fileName);
		return;
	}
	for (int i = 0; i < wiersze; i++)
		for (int j = 0; j < kolumny; j++)
			fread(&tab[i][j], sizeof(int), 1, plik);
	fclose(plik);
}