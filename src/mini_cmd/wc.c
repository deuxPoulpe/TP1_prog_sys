#include "../mini_lib/mini_lib.h"
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc < 2) {
        mini_printf("Usage: wc <nom_fichier>\n");
        return -1;
    }


    char* file_name = argv[1];
    MYFILE* file = mini_fopen(file_name, 'r');

    if (file == NULL) {
        mini_perror("wc failed to open file");
        return -1;
    }

    char buffer[BUF_SIZE];
    int word_count = 0;
    int previous_word = 0;

    while (1) {
        int bytes_read = mini_fread(buffer, 1, sizeof(buffer), file);
        if (bytes_read <= 0) {
            break;
        }

        if (buffer[0] == ' ' || buffer[0] == '\n' || buffer[0] == '\t') {
            previous_word = 1;
        }

        for (int i = 0; i < bytes_read; i++) {
            if ((buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t' )) {
                if (previous_word == 0) {
                    word_count++;
                    previous_word = 1;
                }
            }
            else {
                previous_word = 0;
            }
            
        }
    }

    char print_buffer[BUF_SIZE];
    mini_memset(print_buffer, 0, sizeof(print_buffer));
    mini_strcat(print_buffer, "Total word : ");
    mini_strcat(print_buffer, int_to_char(word_count));
    mini_printf(print_buffer);

    fclose(file);

    return 0;
}
