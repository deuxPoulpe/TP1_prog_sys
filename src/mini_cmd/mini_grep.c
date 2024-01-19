#include "../mini_lib/mini_lib.h"
#include <unistd.h>


int main(int argc, char* argv[]) {
    if (argc != 3) {
        mini_printf("Usage: mini_grep <mot> <nom_fichier>\n");
        return -1;
    }

    MYFILE* file = mini_fopen(argv[2], 'r');

    if (file == NULL) {
        mini_perror("mini_grep failed to open file");
        return -1;
    }

    char buffer[1024], print_buffer[1024], line_buffer[1024];
    int line_number = 1;

    mini_memset(print_buffer, 0, sizeof(print_buffer));

    while (1) {
        int bytes_read = mini_fread(buffer, 1, sizeof(buffer), file);

        if (bytes_read <= 0) {
            break;
        }

        for (int i = 0, j = 0; i < bytes_read; i++, j++) {
            line_buffer[j] = buffer[i];

            if (buffer[i] == '\n') {
                if (mini_strstr(line_buffer, argv[1]) != NULL) {
                    mini_strcat(print_buffer, "Line : ");
                    mini_strcat(print_buffer, int_to_char(line_number));
                    mini_strcat(print_buffer, " ");
                    mini_strcat(print_buffer, line_buffer);
                    mini_printf(print_buffer);

                    mini_memset(print_buffer, 0, sizeof(print_buffer));
                    mini_memset(line_buffer, 0, sizeof(line_buffer));

                }
                j = -1;
                line_number++;
            }
        }

    }

    fclose(file);

    return 0;
}
