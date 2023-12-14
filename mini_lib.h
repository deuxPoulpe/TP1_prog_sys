#ifndef MINI_LIB_H
#include <stddef.h>

typedef struct malloc_element {
    void *ptr;
    int size;
    int status;
    struct malloc_element *next;
} malloc_element;


void * mini_calloc(int size_element, int nb_element);
void mini_free(void *ptr);
void mini_exit(int status);
void mini_printf(char * str);



#endif