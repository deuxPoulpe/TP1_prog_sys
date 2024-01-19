#include "../mini_lib.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        mini_printf("Usage: mini_head -n N <nom_fichier> non\n");
        return -1;
    }

    if (mini_strcmp(argv[1], "-n") != 0) {
        mini_printf("Usage: mini_head -n N <nom_fichier>\n");

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
        mini_perror("failed to open file");
        return -1;
    }

    char buffer[1024], print_buffer[1024];
    mini_memset(print_buffer, 0, sizeof(print_buffer));

    int line_count = 0;

    while (line_count < n) {
        int bytes_read = mini_fread(buffer, 1, sizeof(buffer), file);
        if (bytes_read <= 0) {
            break;
        }

        for (int i = 0, j = 0; i < bytes_read; i++, j++) {
            print_buffer[j] = buffer[i];
            if (buffer[i] == '\n') {
                line_count++;
                mini_printf(print_buffer);
                mini_memset(print_buffer, 0, sizeof(print_buffer));
                j = -1;
                if (line_count >= n) {
                    break;
                }
            }
        }
    }

    fclose(file);

    return 0;
}
