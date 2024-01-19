#include "../mini_lib.h"
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char* argv[]) {
    if (argc < 2) {
        mini_printf("Usage: mini_clean <file>\n");
        return -1;
    }

    MYFILE* file = mini_fopen(argv[1], 'b');
    if (file == NULL) {
        mini_perror("mini_clean failed to open file");
        return -1;
    }

    ftruncate(file->fd, 0);

    fclose(file);

    return 0;
}