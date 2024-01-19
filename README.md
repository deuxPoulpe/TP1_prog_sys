# TP1_prog_sys
Repository for the TP1 of prog sys.


## Exercice 6:

free rend la mémoire allouée disponible a l'utilisation.


## Exercice 10:

le problème et que si la chaine de caractère est plus petit que le buffer et ne finis pas par 'n' alors le buffer ne sera pas afficher.


## Exercice 20:

si le nombre de caractères saisis est supérieur à la taille du buffer on peut alors éxécuter du code sur le terminal.
mais après ma solution si le nombre de caractère saisis est supérieur a BUF_SIZE alors Segmentation fault.


## Exercice 22:

si les chaines de caractère donné au fonction ne finis pas par '\0' alors celle ci sorterons du des chaines de caractère et il peut y avoir aussi un dépassement de mémoire, on peut corriger cela on ajoutant un longueur max pour les chaines à traiter.

## Exercice 40:

Pour benchmarck mon programme je créer 3 fichier de 1 Mo a 100Mo puis je les copie ave mini_cp

| Taille du fichier | Temps réel | Temps utilisateur | Temps système|
|-------------------|------------|-------------------|--------------|
| 1Mo               | 0m0,016s   | 0m0,009s          | 0m0,006s     |
| 10Mo              | 0m0,076s   | 0m0,040s          | 0m0,037s     |
| 100Mo             | 0m0,526s   | 0m0,308s          | 0m0,218s     |

Temps du benchmarck pour les différentes implémentation en td:

|taille du fichier | Appels systèmes |      Glibc      |       MMap      |
|------------------|-----------------|-----------------|-----------------|
|1 Mo              |     0,016s      |     0,014s      |     0,008s      |
|10 Mo             |      0,16s      |     0,115s      |     0,067s      |
|100 Mo            |      1,30s      |       0,9s      |       0,5s      |

On peut donc voir que notre implémentation du cp est plus rapide que l'utilisation d'appels systèmes ou de la Glibc
