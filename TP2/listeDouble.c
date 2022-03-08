#include "listeDouble.h"

ListeDouble* new_listeDouble()
{
	ListeDouble* listeDouble = (ListeDouble*) malloc(sizeof(ListeDouble));
	listeDouble->premier = NULL;
	listeDouble->nb_result = 0;
	return listeDouble;
}

Result* new_result()
{
	Result* result = (Result*) malloc(sizeof(Result));
	result->suivant = result;
	result->precedent = result;
	result->nom = get_word("Nom");
	result->note = get_float("Note");
	return result;
}

void display_result(Result* result)
{
	printf("%s : %.2f \n", result->nom, result->note);
}

void display_listeDouble(ListeDouble* listeDouble)
{
	if(listeDouble->premier != NULL)
	{
		Result* current = listeDouble->premier;
		int index = 1;
		printf("%d. ", index++);
		display_result(current);
		while(current->suivant != listeDouble->premier)
		{
			current = current->suivant;
			printf("%d. ", index++);
			display_result(current);
		}
	}
	else printf("La liste est vide\n");
}

void add_result_tail(ListeDouble* listeDouble)
{
	Result* result = new_result();
	if(listeDouble->premier != NULL)
	{
		result->suivant = listeDouble->premier;
		result->precedent = listeDouble->premier->precedent;
		result->suivant->precedent = result;
		result->precedent->suivant = result;
	}
	else listeDouble->premier = result;
	listeDouble->nb_result++;
}

void add_result_head(ListeDouble* listeDouble)
{
	add_result_tail(listeDouble);
	listeDouble->premier = listeDouble->premier->precedent;
}

void add_result_index(ListeDouble* listeDouble)
{
	display_listeDouble(listeDouble);
	int index = get_int("Index auquel ajouter la cours");
	if(0<index && index<=listeDouble->nb_result+1)
	{
		if(index==1) add_result_head(listeDouble);
		else
		{
			ListeDouble* list_temp = new_listeDouble();
			list_temp->premier = listeDouble->premier;
			int current_index = 1;
			while(index != current_index)
			{
				list_temp->premier = list_temp->premier->suivant;
				current_index++;
			}
			add_result_head(list_temp);
			listeDouble->nb_result++;
			free(list_temp);
		}
	}
	else printf("Il n'y a pas d'index %d disponible dans la liste\n", index);
}

void add_result(ListeDouble* listeDouble)
{
	if(listeDouble->premier == NULL) add_result_head(listeDouble);
	else
	{
		int option;
		while(option!=4)
		{
			printf("------------------------------------\n");
			printf("Ajouter un cours:\n");
			printf("1. au debut\n");
			printf("2. à la fin\n");
			printf("3. à un index donné\n");
			printf("4. retour au menu principal\n");
			option = get_int("-> Choississez une option");
			printf("------------------------------------\n");

			switch(option)
			{
				case 1:
					add_result_head(listeDouble);
					break;

				case 2:
					add_result_tail(listeDouble);
					break;

				case 3:
					add_result_index(listeDouble);
					break;

				default:
					printf("Commande invalide\n");
			}
		}
	}
	
}

void supp_result_head(ListeDouble* listeDouble)
{
	if(listeDouble->premier != NULL)
	{
		Result* a_supp = listeDouble->premier;
		a_supp->precedent->suivant = a_supp->suivant;
		a_supp->suivant->precedent = a_supp->precedent;
		listeDouble->premier = a_supp->suivant;
		listeDouble->nb_result--;
		if(listeDouble->nb_result==0) listeDouble->premier = NULL;
		free(a_supp);
	}
}

void supp_result_tail(ListeDouble* listeDouble)
{
	if(listeDouble->premier != NULL)
	{
		listeDouble->premier = listeDouble->premier->precedent;
		supp_result_head(listeDouble);
	}
}

void supp_result_index(ListeDouble* listeDouble)
{
	display_listeDouble(listeDouble);
	int index = get_int("Index à supprimer");
	if(0<index && index<=listeDouble->nb_result)
	{
		Result* current = listeDouble->premier;
		if(listeDouble->nb_result!=1)
		{
			int current_index = 1;
			while(index != current_index)
			{
				current = current->suivant;
				current_index++;
			}
			if(index==1) listeDouble->premier = current->suivant;
			current->precedent->suivant = current->suivant;
			current->suivant->precedent = current->precedent;
		}
		else listeDouble->premier = NULL;
		listeDouble->nb_result--;
		free(current);
	}
	else printf("Il n'y a pas d'index %d dans la liste\n", index);
}

void supp_result_name(ListeDouble* listeDouble)
{
	display_listeDouble(listeDouble);
	char* name = get_word("Nom du cours à supprimer");
	Result* current = listeDouble->premier;
	while(strcmp(current->nom, name) && current->suivant != listeDouble->premier) current = current->suivant;
	if(!strcmp(current->nom, name))
	{
		current->precedent->suivant = current->suivant;
		current->suivant->precedent = current->precedent;
		if(current == listeDouble->premier) listeDouble->premier = current->suivant;
		listeDouble->nb_result--;
		if(listeDouble->nb_result == 0) listeDouble->premier = NULL;
		free(current);
	}
	else printf("Il n'y pas de cours %s dans la liste\n", name);	
}

void supp_result(ListeDouble* listeDouble)
{
	if(listeDouble->premier != NULL)
	{
		int option;
		while(option!=5)
		{
			printf("------------------------------------\n");
			printf("Supprimer un cours:\n");
			printf("1. au debut\n");
			printf("2. à la fin\n");
			printf("3. à un index donné\n");
			printf("4. avec le nom\n");
			printf("5. retour au menu principal\n");
			option = get_int("-> Choississez une option");
			printf("------------------------------------\n");

			switch(option)
			{
				case 1:
					supp_result_head(listeDouble);
					break;

				case 2:
					supp_result_tail(listeDouble);
					break;

				case 3:
					supp_result_index(listeDouble);
					break;

				case 4:
					supp_result_name(listeDouble);
					break;

				default:
						printf("Commande invalide\n");
			}
		}
	}
	else printf("La liste est déjà vide\n");
}

void inverse_liste(ListeDouble* listeDouble)
{
	if(listeDouble->premier != NULL)
	{
		Result* current = listeDouble->premier;
		Result* tpo = current->suivant;
		current->suivant = current->precedent;
		current->precedent = tpo;
		while(current->precedent != listeDouble->premier)
		{
			current = current->precedent;
			tpo = current->suivant;
			current->suivant = current->precedent;
			current->precedent = tpo;
		}
		listeDouble->premier = current;
	}
	else printf("La liste est vide\n");

	display_listeDouble(listeDouble);
}

void save_listeDouble(ListeDouble* listeDouble, char* name_file)
{
	FILE* fichier = fopen(name_file, "w");
	
	if(listeDouble->premier != NULL)
	{
		Result* current = listeDouble->premier;
		fprintf(fichier, "%s %.2f\n", current->nom, current->note);
		while(current->suivant != listeDouble->premier)
		{
			current = current->suivant;
			fprintf(fichier, "%s %.2f\n", current->nom, current->note);
		}
	}
	fclose(fichier);
}

void load_listeDouble(ListeDouble* listeDouble, char* name_file)
{
	delete_listeDouble(listeDouble);

	FILE* fichier = fopen(name_file, "r");
	char* name = NULL;
	float note;

	while(fscanf(fichier, " %ms %f", &name, &note)==2)
	{
		Result* result = (Result*) malloc(sizeof(Result));
		result->nom = name;
		result->note = note;
		result->suivant = result;
		result->precedent = result;

		if(listeDouble->premier != NULL)
		{
			result->suivant = listeDouble->premier;
			result->precedent = listeDouble->premier->precedent;
			result->suivant->precedent = result;
			result->precedent->suivant = result;
		}
		else listeDouble->premier = result;
		listeDouble->nb_result++;
	}
	fclose(fichier);
}

void delete_listeDouble(ListeDouble* listeDouble)
{
	while(listeDouble->premier != NULL) supp_result_head(listeDouble);
}

void menu_listeDouble(ListeDouble* listeDouble)
{
	int option;
	while(option!=7)
	{
		printf("------------------------------------\n");
		printf("1. Afficher la liste\n");
		printf("2. Ajouter un cours\n");
		printf("3. Supprimer un cours\n");
		printf("4. Inverer la liste\n");
		printf("5. Sauver la liste\n");
		printf("6. Charger la liste\n");
		printf("7. Quitter\n");
		option = get_int("-> Choississez une option");
		printf("------------------------------------\n");

		switch(option)
		{
			case 1:
				display_listeDouble(listeDouble);
				break;

			case 2:
				add_result(listeDouble);
				break;

			case 3:
				supp_result(listeDouble);
				break;

			case 4:
				inverse_liste(listeDouble);
				break;

			case 5:
				save_listeDouble(listeDouble, "listeDouble.txt");
				break;

			case 6:
				load_listeDouble(listeDouble, "listeDouble.txt");
				break;

			case 7:
				delete_listeDouble(listeDouble);
				break;

			default:
					printf("Commande invalide\n");
		}
	}
	
}
