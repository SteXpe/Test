#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	file = fopen("data.txt","w+");

	if (file != NULL)
    {
        fputs("Test d'écriture\n", file);
        fputs("Avion\n", file);

        fseek(file, -10, SEEK_CUR);

        char c;
        do
        {
            c = fgetc(file);
            printf("%c", c);
        } while (c != EOF);
    }
    else printf("Impossible d'ouvrir le fichier test.txt");

    if(!fclose(file)) printf("Ok !\n");

    remove("data.txt");

	return 0;
}
