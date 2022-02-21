#include "liste.h"

liste* new_liste()
{
	liste* liste_t = (liste*) malloc(sizeof(liste));
	liste_t->premier = NULL;
	liste_t->nb_cours = 0;
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
	liste_t->nb_cours++;
}

void add_cours_tail(liste* liste_t)
{
	cours* current_t = liste_t->premier;
	while(current_t->suivant != NULL) current_t = current_t->suivant;
	cours* cours_t = new_cours();
	cours_t->suivant = current_t->suivant;
	current_t->suivant = cours_t;
	liste_t->nb_cours++;
}

void supp_cours_head(liste* liste_t)
{
	if(liste_t->premier != NULL)
	{
		cours* a_supp_t = liste_t->premier;
		liste_t->premier = liste_t->premier->suivant;
		free(a_supp_t);
	}
}

void supp_cours_tail(liste* liste_t)
{
	if(liste_t->premier != NULL)
	{
		cours* a_supp_t = liste_t->premier;
		if(liste_t->premier->suivant != NULL)
		{
			cours* current_t = liste_t->premier;
			while(current_t->suivant->suivant != NULL) current_t = current_t->suivant;
			a_supp_t = current_t->suivant;
			current_t->suivant = NULL;
		}
		else liste_t->premier = NULL;
		free(a_supp_t);
	}
}

void save_liste(liste* liste_t, char* name_file)
{
	FILE* fichier = fopen(name_file, "w");
	
	if(liste_t->premier != NULL)
	{
		cours* current_t = liste_t->premier;
		while(current_t != NULL)
		{
			fprintf(fichier, "%s %.2f\n", current_t->nom, current_t->note);
			current_t = current_t->suivant;
		}
	}
	fclose(fichier);
}

void load_liste(liste* liste_t, char* name_file)
{
	FILE* fichier = fopen(name_file, "r");
	char* name = NULL;
	float note;

	while(fscanf(fichier, " %ms %f", &name, &note)==2)
	{
		cours* cours_t = (cours*) malloc(sizeof(cours));
		cours_t->nom = name;
		cours_t->note = note;
		cours_t->suivant = liste_t->premier;
		liste_t->premier = cours_t;
		liste_t->nb_cours++;
	}
	fclose(fichier);
}

void delete_list(liste* liste_t)
{
	
}

void menu_list(liste* liste_t)
{
	int option;
	while(option!=8)
	{
		printf("------------------------------------\n");
		printf("1. Afficher la liste\n");
		printf("2. Ajouter un cours au debut\n");
		printf("3. Ajouter un cours a la fin\n");
		printf("4. Supprimer un cours\n");
		printf("5. Afficher la moyenne des notes\n");
		printf("6. Sauver la liste\n");
		printf("7. Charger la liste\n");
		printf("8. Quitter\n");
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
				supp_cours_head(liste_t);
				break;

			case 5:
				supp_cours_tail(liste_t);
				break;

			case 6:
				save_liste(liste_t, "liste.txt");
				break;

			case 7:
				load_liste(liste_t, "liste.txt");
				break;

			case 8:
				delete_list(liste_t);
		}
	}
	
}