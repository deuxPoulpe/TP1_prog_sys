#ifndef MINI_LIB_H
#define MINI_LIB_H

/**
 * @file mini_lib.h
 * @brief Une mini bibliothèque de fonctions pour la gestion de la mémoire,
 * l'entrée/sortie simple et les opérations sur les chaînes de caractères.
 * tout la documentation a été faite par ChatGPT.
 */

/**
 * @brief Structure MYFILE pour représenter un fichier personnalisé.
 *
 * Cette structure est utilisée pour gérer la lecture/écriture dans un fichier.
 */
typedef struct {
    int fd;                 ///< Descripteur de fichier.
    void* buffer_read;      ///< Pointeur vers un tampon de lecture.
    void* buffer_write;     ///< Pointeur vers un tampon d'écriture.
    int ind_read;           ///< Indice de lecture dans le tampon de lecture.
    int ind_write;          ///< Indice d'écriture dans le tampon d'écriture.
} MYFILE;

/**
 * @brief Alloue et initialise une zone de mémoire pour un tableau d'éléments.
 *
 * @param size_element Taille en octets de chaque élément.
 * @param nb_element Nombre d'éléments à allouer.
 * @return Un pointeur vers la mémoire allouée, ou NULL en cas d'erreur.
 */
void* mini_calloc(int size_element, int nb_element);

/**
 * @brief Libère la mémoire allouée précédemment par mini_calloc.
 *
 * @param ptr Pointeur vers la mémoire à libérer.
 */
void mini_free(void* ptr);

/**
 * @brief Sort de manière propre le programme en libérant toutes les ressources.
 */
void mini_exit();

/**
 * @brief Affiche une chaîne de caractères sur la sortie standard.
 *
 * @param str Chaîne de caractères à afficher.
 */
void mini_printf(char* str);

/**
 * @brief Lit une ligne de caractères depuis l'entrée standard dans un tampon.
 *
 * @param buffer Tampon pour stocker la ligne lue.
 * @param size_buffer Taille du tampon.
 * @return Le nombre de caractères lus ou une valeur négative en cas d'erreur.
 */
int mini_scanf(char* buffer, int size_buffer);

/**
 * @brief Affiche un message d'erreur avec une description.
 *
 * @param message Message d'erreur à afficher.
 */
void mini_perror(char* message);

/**
 * @brief Remplit une zone de mémoire avec une valeur spécifiée.
 *
 * @param s Pointeur vers la zone de mémoire à remplir.
 * @param c Valeur à copier dans chaque octet de la zone.
 * @param n Nombre d'octets à remplir.
 */
void mini_memset(void* s, int c, unsigned long int n);

/**
 * @brief Compare deux chaînes de caractères.
 *
 * @param str1 Première chaîne de caractères.
 * @param str2 Deuxième chaîne de caractères.
 * @return 0 si les chaînes sont identiques, une valeur négative si str1 < str2,
 *         ou une valeur positive si str1 > str2.
 */
int mini_strcmp(char* str1, char* str2);

/**
 * @brief Copie une chaîne de caractères dans une autre.
 *
 * @param str1 Chaîne de destination.
 * @param str2 Chaîne source.
 * @return La longueur de la chaîne copiée.
 */
int mini_strcpy(char* str1, char* str2);

/**
 * @brief Calcule la longueur d'une chaîne de caractères.
 *
 * @param str Chaîne de caractères.
 * @return Le nombre de caractères dans la chaîne (sans compter le caractère nul).
 */
int mini_strlen(char* str);

/**
 * @brief Sort de manière propre le programme en affichant une chaîne de caractères.
 */
void mini_exit_string();

/**
 * @brief Ouvre un fichier avec le mode spécifié.
 *
 * @param file Nom du fichier à ouvrir.
 * @param mode Mode d'ouverture ("r" pour lecture, "w" pour écriture).
 * @return Un pointeur vers la structure MYFILE représentant le fichier, ou NULL en cas d'erreur.
 */
MYFILE* mini_fopen(char* file, char mode);

/**
 * @brief Lit des données depuis un fichier ouvert avec mini_fopen.
 *
 * @param buffer Tampon pour stocker les données lues.
 * @param size_element Taille en octets de chaque élément.
 * @param number_element Nombre d'éléments à lire.
 * @param file Pointeur vers la structure MYFILE représentant le fichier.
 * @return Le nombre d'éléments lus avec succès ou une valeur négative en cas d'erreur.
 */
int mini_fread(void* buffer, int size_element, int number_element, MYFILE* file);

/**
 * @brief Copie des données depuis une source vers une destination.
 *
 * @param dest Pointeur vers la destination.
 * @param src Pointeur vers la source.
 * @param n Nombre d'octets à copier.
 */
void mini_memcpy(void* dest, const void* src, unsigned long int n);

/**
 * @brief Écrit des données dans un fichier ouvert avec mini_fopen.
 *
 * @param buffer Tampon contenant les données à écrire.
 * @param size_element Taille en octets de chaque élément.
 * @param number_element Nombre d'éléments à écrire.
 * @param file Pointeur vers la structure MYFILE représentant le fichier.
 * @return Le nombre d'éléments écrits avec succès ou une valeur négative en cas d'erreur.
 */
int mini_fwrite(void* buffer, int size_element, int number_element, MYFILE* file);

/**
 * @brief Convertit un entier en une chaîne de caractères.
 *
 * @param i Entier à convertir.
 * @return Un pointeur vers la chaîne de caractères représentant l'entier.
 */
char* int_to_char(int i);

/**
 * @brief Vide le tampon d'écriture d'un fichier.
 *
 * @param file Pointeur vers la structure MYFILE représentant le fichier.
 * @return 0 si le tampon a été vidé avec succès, ou une valeur négative en cas d'erreur.
 */
int mini_fflush(MYFILE* file);

/**
 * @brief Ferme un fichier ouvert avec mini_fopen.
 *
 * @param file Pointeur vers la structure MYFILE représentant le fichier.
 * @return 0 si le fichier a été fermé avec succès, ou une valeur négative en cas d'erreur.
 */
int fclose(MYFILE* file);

/**
 * @brief Libère toutes les ressources utilisées par la bibliothèque.
 */
void mini_exit_io();


/**
 * @brief Lit un caractère depuis un fichier ouvert avec mini_fopen.
 *      Si le tampon de lecture est vide, il est rempli avec mini_fread.    
 * @param file Pointeur vers la structure MYFILE représentant le fichier
 * @return Le caractère lu ou -1 en cas d'erreur.
 */

int mini_fgetc(MYFILE *file);


/**
 * @brief Écrit un caractère dans un fichier ouvert avec mini_fopen.
 *      Si le tampon d'écriture est plein, il est vidé avec mini_fflush.
 * @param file Pointeur vers la structure MYFILE représentant le fichier
 * @param c Caractère à écrire
 * @return Le caractère écrit ou -1 en cas d'erreur.
 */
int mini_fputc(MYFILE* file, char c);




#endif
