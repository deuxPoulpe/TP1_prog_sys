#include "mini_lib.h"
#include <errno.h>  
#include <unistd.h>
#include <string.h>
extern int errno;

void mini_exit() {
    mini_exit_string();
    _exit(1);
}


void mini_perror(char * message){
    mini_printf(message);
    mini_printf("\n:");
    mini_printf(int_to_char(errno));

}

void mini_memset(void *s, int c, size_t n){
    char *p = s;
    while(n--)
        *p++ = (char)c;
}

void mini_memcpy(void *dest, const void *src, size_t n) {
            char *cdest = (char *)dest;
            const char *csrc = (const char *)src;

            for (size_t i = 0; i < n; i++) {
                cdest[i] = csrc[i];
            }
}

char * int_to_char(int i){
    char *str = mini_calloc(12, sizeof(char));
    if (str == NULL) {
        return NULL;
    }

    int j = 0;
    if (i < 0) {
        str[j++] = '-';
        i = -i;
    }

    int k = 0;
    int tmp = i;
    while (tmp > 0) {
        tmp /= 10;
        k++;
    }

    if (k == 0) {
        str[j++] = '0';
    } else {
        for (int l = 0; l < k; l++) {
            str[j + k - l - 1] = '0' + i % 10;
            i /= 10;
        }
        j += k;
    }

    str[j] = '\0';
    return str;
}