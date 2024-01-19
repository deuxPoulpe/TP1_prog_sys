#include "./mini_lib/mini_lib.h"
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_CMD_ARGS 1024
#define BUF_SIZE 1024
#define PREFIX "mini_shell> "
#define CMD_PREFIX "./"

char* allowed_cmds[] = {
    "mini_cat",
    "mini_touch",
    "mini_clean",
    "mini_echo",
    "exit",
    "wc",
    "mini_grep",
    "mini_head",
    "mini_tail",
    NULL
};



int main(){
    
  
   
    return 0;
}
