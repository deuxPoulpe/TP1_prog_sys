#include "./mini_lib/mini_lib.h"
#include <unistd.h>


int main() {

    mini_printf("Test de mini_calloc et mini_free\n");

    int *tab1 = (int *)mini_calloc(10, sizeof(int));
    if (tab1 == NULL) {
        mini_printf("Échec de l'allocation de tab1\n");
        mini_exit(1);
    }
    mini_printf("Mémoire allouée pour tab1\n");

    for (int i = 0; i < 10; i++) {
        tab1[i] = i;
    }

    mini_free(tab1);
    mini_printf("Mémoire libérée pour tab1\n");

    int *tab2 = (int *)mini_calloc(5, sizeof(int));
    if (tab2 == NULL) {
        mini_printf("Échec de l'allocation de tab2\n");
        mini_exit(1);
    }
    mini_printf("Mémoire réutilisée/réallouée pour tab2\n");

    for (int i = 0; i < 5; i++) {
        if (tab2[i] != 0) {
            mini_printf("Erreur: tab2 n'est pas correctement initialisé à zéro\n");
            mini_exit(1);
        }
    }
    mini_printf("tab2 est correctement initialisé à zéro\n");

    mini_free(tab2);
    mini_printf("Mémoire libérée pour tab2\n");



    mini_printf("Test de mini_printf\n");
    mini_printf("Hello world\n");
    mini_printf("Hello world");

    char str[5];
    mini_printf("Test mini_scanf:\n");
    mini_scanf(str, 6);
    mini_printf(str);


    mini_printf("=========== Test de mini_fread/write ===========\n");

    MYFILE *file = mini_fopen("test.txt", 'b');
    if (file == NULL) {
        mini_printf("Échec de l'ouverture du fichier\n");
        mini_exit(1);
    }
    mini_printf("Fichier ouvert\n");

    char buffer[1024];
    mini_fread(buffer, 1, 1024, file);
    mini_printf(buffer);

    char *str2 = "coucou";
    mini_fwrite(str2, 1, 6, file);
    mini_fflush(file);


    char *str3 = "toto";
    mini_fwrite(str3, 1, 4, file);
    mini_fflush(file);
    

    mini_printf("=========== Fin du test de mini_fread/write ===========\n");
    fclose(file);

    mini_printf("=========== Test de mini_fgetc ===========\n");

    MYFILE* new_file = mini_fopen("test.txt", 'b');
    if (new_file == NULL) {
        mini_printf("Échec de l'ouverture du fichier\n");
        mini_exit(1);
    }

    int charRead = 0;
    char gets_str[2];
    gets_str[1] = '\n';

    charRead = mini_fgetc(new_file);
    gets_str[0] = (char)charRead;
    mini_printf(int_to_char(charRead));
    mini_printf(gets_str);

    mini_fputc(new_file, 'a');

    
    mini_printf("=========== Fin du test de mini_fgetc ===========\n");
    fclose(new_file);


    mini_free(new_file);
    mini_free(file);


    mini_exit();
}
