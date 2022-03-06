#include "get.h"

void clear()
{
    char c;
    while((c=getchar())!='\n' && c!=EOF);
}

int get_int(char* label)
{
	int nb;
    printf("%s: ", label);
    while(scanf(" %d", &nb)!=1 || getchar()!='\n')
    {
        printf("Format invalide, entrez uniquement un int.\n");
        clear();
    }
    return nb;
}

float get_float(char* label)
{
    float nb;
    printf("%s: ", label);
    while(scanf(" %f", &nb)!=1 || getchar()!='\n')
    {
        printf("Format invalide, entrez uniquement un float.\n");
        clear();
    }
    return nb;
}

char* get_word(char* label)
{
	char* word = NULL;
	printf("%s: ", label);
	while(scanf(" %ms", &word)!=1 || getchar()!='\n')
	{
		printf("Format invalide, entrez uniquement un mot.\n");
		clear();
	}
	return word;
}
