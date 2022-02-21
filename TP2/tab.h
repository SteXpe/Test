#ifndef _TAB_H_
#define _TAB_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int rand_nb(int borne_inf, int borne_sup);
int* new_tab(int taille);
void fill_tab(int* tab, int taille);
void display_tab(int* tab, int taille);
void sort_tab(int* tab, int taille);
void save_tab(int* tab, int taille, char* name_file);
int* load_tab(int* taille, char* name_file);

#endif