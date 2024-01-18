#include "mini_lib.h"
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024
#define MAX_SIZE 1024

char buffer[BUF_SIZE]; 
int ind = -1; 

void mini_exit_string(){
    write(1,buffer,ind);
    ind = -1;
    mini_memset(buffer,'\0',BUF_SIZE);
}

void mini_printf(char * str){

    if(str == NULL){
        mini_exit();
    }

    mini_memset(buffer, '\0', BUF_SIZE);
    
    for(int i = 0 ; str[i] != '\0'; i++){


        buffer[++ind] = str[i];
 

        if (ind >= BUF_SIZE - 1 || buffer[ind] == '\n') {
            if (write(1, buffer, ind + 1) == -1) {
                mini_perror("Error while writing");
                mini_exit();

            }
            ind = -1;
            mini_memset(buffer, '\0', BUF_SIZE);


        }
    }
}


int mini_scanf(char* buffer_scan,int size_buffer){   
    if(size_buffer < 0 || buffer == NULL){
        return -1;
    }
    
    char buff_sec[BUF_SIZE];
    int bytes_read = 0;

    while (((read(0, &buff_sec[bytes_read], 1)) > 0)) {
        if (buff_sec[bytes_read++] == '\n') {
            break; 
        }
    }
    for (int i = 0; i < size_buffer; i++) {
        buffer_scan[i] = buff_sec[i];
    }
    buffer_scan[size_buffer] = '\0'; 

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

int mini_strcpy(char* str1, char* str2) {
    if(str1 == NULL || str2 == NULL){
        return -1;
    }
    int i = 0;
    while (str1[i] != '\0' && i < MAX_SIZE)
    {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';  
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
