#include "mini_lib.h"
#include <errno.h>  


void mini_exit(int status) {
    _exit(status);
}

void mini_perror(char * message){
    mini_printf(message);
    mini_printf("\t:");
    mini_printf(errno);
}