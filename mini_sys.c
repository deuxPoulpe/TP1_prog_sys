#include "mini_lib.h"
#include <errno.h>  
#include <unistd.h>
#include <stdio.h>

void mini_exit(int status) {
    _exit(status);
}

void mini_perror(char * message){
    mini_printf(message);
    mini_printf("\t:");
    printf("%i\n", errno);

}

void mini_memset(void *s, int c, size_t n){
    char *p = s;
    while(n--)
        *p++ = (char)c;
}