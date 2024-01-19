#include "../mini_lib.h"
#define BUF_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc != 4) {
        mini_printf("Usage: mini_tail -n N <nom_fichier>\n");
        return -1;
    }

    if (mini_strcmp(argv[1], "-n") != 0) {
        mini_printf("Usage: mini_tail -n N <nom_fichier>\n");
        return -1;
    }

    int n = char_to_int(argv[2]);
    if (n <= 0) {
        mini_printf("N need to ne positif\n");
        return -1;
    }

    char* file_name = argv[3];
    MYFILE* file = mini_fopen(file_name, 'r');

    if (file == NULL) {
        mini_perror("mini_tail failed to open file");
        return -1;
    }

    char buffer[BUF_SIZE];
    int total_line = 0;

    while (1) {
        int bytes_read = mini_fread(buffer, 1, sizeof(buffer), file);
        if (bytes_read <= 0) {
            break;
        }

        for (int i = 0; i < bytes_read; i++) {
            if (buffer[i] == '\n') {
                total_line++;
            }
        }
    }

    int line_count = 0;
    char print_buffer[BUF_SIZE];
    mini_memset(print_buffer, 0, sizeof(print_buffer));
    mini_fseek(file, 0, 0);

    while (1) {
        int bytes_read = mini_fread(buffer, 1, sizeof(buffer), file);
        if (bytes_read <= 0) {
            break;
        }

        for (int i = 0, j = 0; i < bytes_read; i++, j++) {
            print_buffer[j] = buffer[i];
            if (buffer[i] == '\n') {
                if ((total_line - line_count) <= n) {
                    mini_printf(print_buffer);
                }
                line_count++;
                mini_memset(print_buffer, 0, sizeof(print_buffer));
                j = -1;
            }
        }
    }

    fclose(file);

    return 0;
}
