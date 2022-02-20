#include "tab.h"

int rand_nb(int borne_inf, int borne_sup)
{
	return (rand()%(borne_sup-borne_inf+1))+borne_inf;
}

int* new_tab(int taille)
{
	int* tab = (int*) malloc(taille * sizeof(int));

	return tab;
}

void fill_tab(int* tab, int taille)
{
	int borne_inf, borne_sup;
	printf("borne_inf: ");
	scanf(" %d", &borne_inf);
	printf("borne_sup: ");
	scanf(" %d", &borne_sup);

	for(int i=0; i<taille; i++)
	{
		*(tab+i) = rand_nb(borne_inf, borne_sup);
	}
}

void display_tab(int* tab, int taille)
{
	for(int i=0; i<taille; i++)
	{
		printf("%d ", *(tab+i));
		if((i+1)%10==0) printf("\n");
	}
}

void sort_tab(int* tab, int taille)
{
	char mode;
	printf("Tri croissant(c) ou decroissant(d): ");
	scanf(" %c", &mode);

	for(int i=0; i<taille; i++)
	{
		for(int j=i+1; j<taille; j++)
		{
			if(((*(tab+j) < *(tab+i)) && mode == 'c') || ((*(tab+j) > *(tab+i)) && mode == 'd'))
			{
				*(tab+j) += *(tab+i);
				*(tab+i) = *(tab+j) - *(tab+i);
				*(tab+j) -= *(tab+i);
			} 
		}
	}
}

void save_tab(int* tab, int taille, char* name_file)
{
	FILE* fichier = fopen(name_file, "w");
	for(int i=0; i<taille; i++) fprintf(fichier, "%d\n", *(tab+i));
	fclose(fichier);
}

int* load_tab(int* taille, char* name_file)
{
	FILE* fichier = fopen(name_file, "r");

	*taille=0;
	int nb;
	while(fscanf(fichier, " %d", &nb)==1) taille++;
	fseek(fichier, 0, SEEK_SET);

	int* tab = new_tab(*taille);
	for(int i=0; i<*taille; i++) fscanf(fichier, " %d", tab+i);
	return tab;
}