#ifndef _LISTE_H_
#define _LISTE_H_

#include "tab.h"

typedef struct cours cours;
struct cours
{
	char* nom;
	float note;
	cours* suivant;
	cours* precedent;
};

typedef struct
{
	int nb_cours;
	cours* premier;
} liste;

/*
liste* new_liste();
cours* new_cours();
void display_cours(cours* cours_t);
void display_liste(liste* liste_t);
void add_cours_head(liste* liste_t);
void add_cours_tail(liste* liste_t);
void supp_cours_head(liste* liste_t);
void supp_cours_tail(liste* liste_t);
void save_liste(liste* liste_t, char* name_file);
void load_liste(liste* liste_t, char* name_file);
void delete_list(liste* liste_t);
void menu_list(liste* liste_t);
*/

#endif