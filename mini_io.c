#include "mini_lib.h"
#include <unistd.h>
#include <fcntl.h>


#define IOBUFFER_SIZE 2048

// table des fichiers ouverts
MYFILE * tab[1024];
int ind_tab = 0;

void mini_exit_io(){
    for(int i = 0 ; i < ind_tab ; i++){
        if(tab[i] != NULL){
            mini_fflush(tab[i]);
            if(tab[i]->buffer_read != NULL){
                mini_free(tab[i]->buffer_read);
            }
            if(tab[i]->buffer_write != NULL){
                mini_free(tab[i]->buffer_write);
            }
            mini_free(tab[i]);
        }
    }
}


MYFILE* mini_fopen(char* file, char mode){
    MYFILE* fl = mini_calloc(1, sizeof(MYFILE));
    if (fl == NULL) {
        return NULL;
    }
    fl->ind_read = -1;
    fl->ind_write = -1;
    fl->fd = open(file, mode);

    if (fl->fd == -1) {
        mini_free(fl);
        return NULL;
    }

    tab[ind_tab++] = fl;
    return fl;
}



int mini_fread(void *buffer, int size_element, int number_element, MYFILE *file) {
    if (file == NULL || buffer == NULL) {
        return -1;
    }

    if (file->buffer_read == NULL) {
        file->buffer_read = (char *)mini_calloc(IOBUFFER_SIZE, sizeof(char));
        if (file->buffer_read == NULL) {
            return -1;
        }
        file->ind_read = IOBUFFER_SIZE; 
    }

    int total_bytes_read = 0;
    int bytes_to_read = size_element * number_element;

    while (bytes_to_read > 0) {
 
        if (file->ind_read >= IOBUFFER_SIZE) {
            int bytes_read = read(file->fd, file->buffer_read, IOBUFFER_SIZE);
            if (bytes_read <= 0) { 
                break;
            }
            file->ind_read = 0;
        }

        int bytes_available = IOBUFFER_SIZE - file->ind_read;
        int bytes_to_copy = bytes_available < bytes_to_read ? bytes_available : bytes_to_read;

        mini_memcpy((char *)buffer + total_bytes_read, file->buffer_read + file->ind_read, bytes_to_copy);

        

        file->ind_read += bytes_to_copy;
        total_bytes_read += bytes_to_copy;
        bytes_to_read -= bytes_to_copy;
    }

    return total_bytes_read;
}

int mini_fwrite(void *buffer, int size_element, int number_element, MYFILE *file) {
    if (file == NULL || buffer == NULL) {
        return -1;
    }

    if (file->buffer_write == NULL) {
        file->buffer_write = (char *)mini_calloc(IOBUFFER_SIZE, sizeof(char));
        if (file->buffer_write == NULL) {
            return -1;
        }
        file->ind_write = 0;
    }

    int total_bytes_written = 0;
    int bytes_to_write = size_element * number_element;

    while (bytes_to_write > 0) {
        int bytes_available = IOBUFFER_SIZE - file->ind_write;
        int bytes_to_copy = bytes_available < bytes_to_write ? bytes_available : bytes_to_write;

        mini_memcpy(file->buffer_write + file->ind_write, (char *)buffer + total_bytes_written, bytes_to_copy);
        file->ind_write += bytes_to_copy;
        total_bytes_written += bytes_to_copy;
        bytes_to_write -= bytes_to_copy;

        if (file->ind_write == IOBUFFER_SIZE) {
            int bytes_written = write(file->fd, file->buffer_write, IOBUFFER_SIZE);
            if (bytes_written < 0) {
                return -1;
            }
            file->ind_write = 0;
        }
    }

    return total_bytes_written;
}


int mini_fflush(MYFILE* file) {
    if (file == NULL) {
        return -1;
    }

    if (file->buffer_write == NULL || file->ind_write == 0) {
        return 0;
    }

    int bytes_written = write(file->fd, file->buffer_write, file->ind_write);
    if (bytes_written < 0) {
        return -1;
    }

    file->ind_write = 0;

    return bytes_written;
}


int fclose(MYFILE* file) {
    if (file == NULL) {
        return -1;
    }

    int flush_result = mini_fflush(file);
    if (flush_result == -1) {
        return -1;
    }

    int close_result = close(file->fd);
    if (close_result == -1) {
        return -1;
    }

    return 0;
}
