#include "../mini_lib/mini_lib.h"
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        mini_printf("Usage: mini_cat <nom_fichier>\n");
        return -1;
    }

    char* file_name = argv[1];
    MYFILE* file = mini_fopen(file_name, 'r');

    if (file == NULL) {
        mini_perror("failed to open file");
        return -1;
    }

    char buffer[1024];
    int bytes_read;

    while ((bytes_read = mini_fread(buffer, 1, sizeof(buffer), file)) > 0) {
        mini_printf(buffer);
    }

    fclose(file);

    return 0;
}
