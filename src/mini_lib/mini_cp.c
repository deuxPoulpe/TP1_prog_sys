#include "../mini_lib.h"
#include <unistd.h>

#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    if (argc != 3) {
        mini_printf("Usage: mini_cp <src> <dest>\n");
        return -1;
    }

    char *src_file = argv[1];
    char *dest_file = argv[2];

    MYFILE *src = mini_fopen(src_file, 'r');
    if (src == NULL) {
        mini_perror("mini_cp failed to open source file");
        return -1;
    }

    MYFILE *dest = mini_fopen(dest_file, 'b');
    if (dest == NULL) {
        mini_perror("mini_cp failed to open destination file");
        fclose(src);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read, bytes_written;

    while ((bytes_read = mini_fread(buffer, sizeof(char), BUFFER_SIZE, src)) > 0) {
        bytes_written = mini_fwrite(buffer, sizeof(char), bytes_read, dest);
        if (bytes_written != bytes_read) {
            mini_perror("mini_cp failed to write to destination file");
            fclose(src);
            fclose(dest);
            return -1;
        }
    }

    fclose(src);
    fclose(dest);
    return 0;
}