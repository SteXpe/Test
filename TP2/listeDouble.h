#ifndef _LISTEDOUBLE_H_
#define _LISTEDOUBLE_H_

#include "get.h"
#include <string.h>

typedef struct Result Result;
struct Result
{
	char* nom;
	float note;
	Result* suivant;
	Result* precedent;
};

typedef struct
{
	int nb_result;
	Result* premier;
} ListeDouble;

ListeDouble* new_listeDouble();
Result* new_result();
void display_result(Result* resultat);
void display_listeDouble(ListeDouble* listeDouble);
void add_result_tail(ListeDouble* listeDouble);
void add_result_head(ListeDouble* listeDouble);
void add_result_index(ListeDouble* listeDouble);
void add_result(ListeDouble* listeDouble);
void supp_result_head(ListeDouble* listeDouble);
void supp_result_tail(ListeDouble* listeDouble);
void supp_result_index(ListeDouble* listeDouble);
void supp_result_name(ListeDouble* listeDouble);
void supp_result(ListeDouble* listeDouble);
void inverse_liste(ListeDouble* listeDouble);
void save_listeDouble(ListeDouble* listeDouble, char* name_file);
void load_listeDouble(ListeDouble* listeDouble, char* name_file);
void delete_listeDouble(ListeDouble* listeDouble);
void menu_listeDouble(ListeDouble* listeDouble);

#endif