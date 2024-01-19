#include "mini_lib/mini_lib.h"
#include <unistd.h>
#include <sys/wait.h>


#define CMD_LENGTH_MAX 1024
#define ARGS_MAX 1024
#define ARG_LENGTH_MAX 1024
#define CMD_PREFIX "./"

char *permitted_commands[] = { "mini_cat", "mini_clean", "mini_cp", "mini_echo", "mini_grep", "mini_head", "mini_tail", "mini_touch", "wc", "color" ,"clear", "help", "exit" ,NULL };


void change_color(char *color) {

    if (mini_strcmp(color, "red") == 0) {
        mini_printf("\033[31m");
    }
    else if (mini_strcmp(color, "green") == 0) {
        mini_printf("\033[32m");
    }
    else if (mini_strcmp(color, "yellow") == 0) {
        mini_printf("\033[33m");
    }
    else if (mini_strcmp(color, "blue") == 0) {
        mini_printf("\033[34m");
    }
    else if (mini_strcmp(color, "magenta") == 0) {
        mini_printf("\033[35m");
    }
    else if (mini_strcmp(color, "cyan") == 0) {
        mini_printf("\033[36m");
    }
    else if (mini_strcmp(color, "white") == 0) {
        mini_printf("\033[37m");
    }
    else if (mini_strcmp(color, "reset") == 0) {
        mini_printf("\033[0m");
    }
    else {
        mini_printf("Color not found\n");
        mini_printf("Available colors: red, green, yellow, blue, magenta, cyan, white, reset\n");
    }

    
}


void clear_screen() {
    mini_printf("\033[2J");
    mini_printf("\033[1;1H");
}



int main(void) {
    char command[CMD_LENGTH_MAX];
    char argv_mini_shell[ARGS_MAX][ARG_LENGTH_MAX];
    char *arg_p[ARGS_MAX];
    int process_status;

    mini_printf("Welcome to mini_shell\n");
    mini_printf("Type 'help' to see the list of commands\n");



    while (1) {
        mini_printf("\n");
        mini_printf("mini_shell>  ");
        mini_memset(command, 0, CMD_LENGTH_MAX * sizeof(char));
        mini_memset(argv_mini_shell, 0, ARGS_MAX * ARG_LENGTH_MAX * sizeof(char));
        mini_memset(arg_p, 0, ARGS_MAX * sizeof(char*));

        int char_read = mini_scanf(command, CMD_LENGTH_MAX * sizeof(char));


        if (char_read > 0){
            command[char_read] = '\0';

            int arg_count = 0;
            int arg_len = 0;
            
            for (int i = 0; i < char_read; i++) {
                if (command[i] == ' ' || command[i] == '\n') {
                    argv_mini_shell[arg_count][arg_len] = '\0';
                    arg_p[arg_count] = argv_mini_shell[arg_count];
                    arg_count++;
                    arg_len = 0;
                } else {
                    argv_mini_shell[arg_count][arg_len] = command[i];
                    arg_len++;
                }
            }

            arg_p[arg_count] = NULL;

            int is_command_allowed = 0;
            for (int i = 0; permitted_commands[i] != NULL; i++) {
                if (mini_strcmp(arg_p[0], permitted_commands[i]) == 0) {
                    is_command_allowed = 1;
                }
            }

            if (mini_strcmp(arg_p[0], "color") == 0) {
                change_color(arg_p[1]);
            }

            else if (mini_strcmp(arg_p[0], "help") == 0) {
                mini_printf("List of commands: \n");
                for (int i = 0; permitted_commands[i] != NULL; i++) {
                    mini_printf(" - ");
                    mini_printf(permitted_commands[i]);
                    mini_printf("\n");
                }
            }

            else if (mini_strcmp(arg_p[0], "clear") == 0) {
                clear_screen();
            }
            else if (mini_strcmp(arg_p[0], "exit") == 0) {
                    mini_printf("Exiting mini_shell.... \n");
                    mini_exit();
            }






            else if (is_command_allowed) {
                pid_t pid = fork();

                if (pid == 0) {
                    char final_cmd[CMD_LENGTH_MAX] = { 0 };
                    mini_strcat(final_cmd, CMD_PREFIX);
                    mini_strcat(final_cmd, arg_p[0]);
                    arg_p[0] = final_cmd;

                    
                    execv(arg_p[0], arg_p);

                    mini_exit();
                }
                else if (pid > 0) {
                    waitpid(pid, &process_status, 0);
                }
                else {
                    mini_perror("Error creating process\n");
                }

            }
            else {
                mini_printf("Command not found\n");}
            



        }
    }

    return 0;
}
