#include "liste.h"

liste* new_liste()
{
	liste* liste_t = (liste*) malloc(sizeof(liste));
	liste_t->premier = NULL;
	return liste_t;
}

cours* new_cours()
{
	cours* cours_t = (cours*) malloc(sizeof(cours));

	printf("Nom: ");
	scanf(" %ms", &cours_t->nom);
	printf("Note: ");
	scanf(" %f", &cours_t->note);

	return cours_t;
}

void display_cours(cours* cours_t)
{
	printf("%s : %.2f \n", cours_t->nom, cours_t->note);
}

void display_liste(liste* liste_t)
{
	if(liste_t->premier != NULL)
	{
		cours* current_t = liste_t->premier;
		while(current_t != NULL)
		{
			display_cours(current_t);
			current_t = current_t->suivant;
		}
	}
}

void add_cours_head(liste* liste_t)
{
	cours* cours_t = new_cours();
	cours_t->suivant = liste_t->premier;
	liste_t->premier = cours_t;
}

void add_cours_tail(liste* liste_t)
{
	cours* current_t = liste_t->premier;
	while(current_t->suivant != NULL) current_t = current_t->suivant;
	cours* cours_t = new_cours();
	cours_t->suivant = current_t->suivant;
	current_t->suivant = cours_t;
}

void menu_list(liste* liste_t)
{
	int option;
	while(option!=6)
	{
		printf("------------------------------------\n");
		printf("1. Afficher la liste\n");
		printf("2. Ajouter un cours au debut\n");
		printf("3. Ajouter un cours a la fin\n");
		printf("4. Supprimer un cours\n");
		printf("5. Afficher la moyenne des notes\n");
		printf("6. Quitter\n");
		printf("-> Choississez une option: ");
		scanf(" %d", &option);
		printf("------------------------------------\n");

		switch(option)
		{
			case 1:
				display_liste(liste_t);
				break;

			case 2:
				add_cours_head(liste_t);
				break;

			case 3:
				add_cours_tail(liste_t);
				break;

			case 4:
				break;

			case 5:
				break;
		}
	}
	
}