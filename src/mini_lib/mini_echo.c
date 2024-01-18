#include "../mini_lib.h"
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mini_printf("Usage: mini_echo string\n");
        return 1;
    }

    argv[1][mini_strlen(argv[1])] = '\n';
    mini_printf(argv[1]);
    
    return 0;
}
