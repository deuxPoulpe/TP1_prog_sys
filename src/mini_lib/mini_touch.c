#include "../mini_lib.h"
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mini_printf("Usage: mini_touch file\n");
        return 1;
    }

    char *file_name = argv[1];
    MYFILE *file = mini_fopen(file_name, 'a');
    if (file == NULL) {
        mini_perror("mini_touch");
        return 1;
    }

    fclose(file);
    return 0;
}
