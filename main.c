#include <stdio.h>
#include "mini_lib.h"

int main(int argc, char **argv) {

    printf("Test de mini_calloc et mini_free\n");

    int *tab1 = (int *)mini_calloc(10, sizeof(int));
    if (tab1 == NULL) {
        printf("Échec de l'allocation de tab1\n");
        mini_exit(1);
    }
    printf("Mémoire allouée pour tab1\n");

    for (int i = 0; i < 10; i++) {
        tab1[i] = i;
    }

    mini_free(tab1);
    printf("Mémoire libérée pour tab1\n");

    int *tab2 = (int *)mini_calloc(5, sizeof(int));
    if (tab2 == NULL) {
        printf("Échec de l'allocation de tab2\n");
        mini_exit(1);
    }
    printf("Mémoire réutilisée/réallouée pour tab2\n");

    for (int i = 0; i < 5; i++) {
        if (tab2[i] != 0) {
            printf("Erreur: tab2 n'est pas correctement initialisé à zéro\n");
            mini_exit(1);
        }
    }
    printf("tab2 est correctement initialisé à zéro\n");

    mini_free(tab2);
    printf("Mémoire libérée pour tab2\n");



    printf("Test de mini_printf\n");
    mini_printf("Hello world\n");

    char str[5];
    mini_scanf(str, 6);
    mini_printf(str);

    mini_exit(0);
}
