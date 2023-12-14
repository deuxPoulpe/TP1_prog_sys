#include <unistd.h>
#include <string.h>
#include "mini_lib.h"



malloc_element *malloc_list = NULL;

void * mini_calloc(int size_element, int nb_element){

    for (malloc_element *current = malloc_list ; current != NULL ; current = current->next) {
        if (current->status == 0 && current->size >= size_element * nb_element) {
            memset(current->ptr, '\0', size_element * nb_element);
            current->status = 1;
            return current->ptr;
        }
    }

    void * ptr = sbrk(size_element * nb_element);
    if(ptr == (void *) -1){
        return NULL;
    }

    memset(ptr, '\0', size_element * nb_element);

    malloc_element *new_element = sbrk(sizeof(malloc_element));
    if (new_element == (void *)-1) {
        sbrk(-size_element * nb_element);
        return NULL;
    }

    new_element->size = size_element * nb_element;
    new_element->ptr = ptr;
    new_element->status = 1;
    new_element->next = malloc_list;
    malloc_list = new_element;

    return ptr;
}

void mini_free(void *ptr){
    for (malloc_element *current = malloc_list ; current != NULL ; current = current->next) {
        if (current->ptr == ptr) {
            current->status = 0;
            return;
        }
    }
}

void mini_exit(int status) {
    _exit(status);
}

