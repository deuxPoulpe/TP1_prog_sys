#include "mini_lib.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define BUF_SIZE 1024 

char buffer[BUF_SIZE]; 
int ind = -1; 


void mini_printf(char * str){


    memset(buffer, '\0', BUF_SIZE);

    for(int i = 0 ; str[i] != '\0'; i++){


        buffer[++ind] = str[i];
 

        if (ind >= BUF_SIZE - 1 || buffer[ind] == '\n') {
            write(1, buffer, ind + 1);
            ind = -1;

        }

    }

    if (ind != -1) {
        write(1, buffer, ind + 1);
        ind = -1;
        
    }
   
    memset(buffer, '\0', BUF_SIZE);

}