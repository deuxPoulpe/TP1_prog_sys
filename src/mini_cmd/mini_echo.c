#include "../mini_lib/mini_lib.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        mini_printf("Usage: mini_echo <chaine>\n");
        return -1;
    }

    char final_output[1024] = "";
    for (int i = 1; i < argc; i++) {
        mini_strcat(final_output, argv[i]);
        if (i < argc - 1) {
            mini_strcat(final_output, " ");
        }
    }

    mini_strcat(final_output, "\n");
    mini_printf(final_output);

    return 0;
}
