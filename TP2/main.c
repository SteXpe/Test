#include "liste.h"

int main(int argc, char **argv)
{
	srand(time(NULL));

	/*int taille;
	printf("Taille: ");
	scanf(" %d", &taille);
	int* tab = new_tab(taille);

	fill_tab(tab, taille);
	sort_tab(tab, taille);
	display_tab(tab, taille);
	save_tab(tab, taille, "tab.txt");
	int* tab_load = load_tab(&taille, "tab.txt");
	display_tab(tab_load, taille);

	free(tab);*/

	liste* liste_t = new_liste();
	menu_list(liste_t);

	free(liste_t);

	return 0;
}
