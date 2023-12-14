#include "mini_lib.h"
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024 
#define MAX_SIZE 1024

char buffer[BUF_SIZE]; 
int ind = -1; 


void mini_printf(char * str){

    if(str == NULL){
        mini_exit(1);
    }

    memset(buffer, '\0', BUF_SIZE);
    
    for(int i = 0 ; str[i] != '\0'; i++){


        buffer[++ind] = str[i];
 

        if (ind >= BUF_SIZE - 1 || buffer[ind] == '\n') {
            if (write(1, buffer, ind + 1) == -1) {
                mini_perror("Error while writing");
                mini_exit(1);
            }
            ind = -1;


        }

    }

    if (ind != -1) {
        if (write(1, buffer, ind + 1) == -1) {
                mini_perror("Error while writing");
                mini_exit(1);
            }
        ind = -1;

        
    }
   
    memset(buffer, '\0', BUF_SIZE);

}


int mini_scanf(char* buffer,int size_buffer){   
    if(size_buffer < 0 || buffer == NULL){
        return -1;
    }

    int bytes_read = read(0,buffer,size_buffer);

    if(bytes_read == -1){
        mini_perror("Error while reading");
        return -1;
    }
    buffer[bytes_read] = '\0';

    return bytes_read;
    
}

int mini_strlen(char* s) {
    int length = 0;
    while (s[length] != '\0' && length < MAX_SIZE)
    {
        length++;
    }
    
    return length;
}

int mini_strcpy(char* s, char* d) {
    if(s == NULL || d == NULL){
        return -1;
    }
    int i = 0;
    while (s[i] != '\0' && i < MAX_SIZE)
    {
        d[i] = s[i];
        i++;
    }
    d[i] = '\0';  
    return i;     
}

int mini_strcmp(char* s1, char* s2){
    if(s1 == NULL || s2 == NULL){
        return -1;
    }
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && i < MAX_SIZE)
    {
        if(s1[i] != s2[i]){
            return s1[i] - s2[i];
        }
        i++;
    }
    if(s1[i] == '\0' && s2[i] == '\0'){
        return 0;
    }
    else if(s1[i] == '\0'){
        return -1;
    }
    else{
        return 1;
    }
}