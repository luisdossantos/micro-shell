#include <stdlib.h>
#include <stdio.h>
// Pour le fork et le execvp
#include <unistd.h>
// Pour le wait
#include <sys/wait.h>
// Pour strcmp
#include <string.h>

#define TAILLELECTURE 100


#ifndef EXERCICE1_1
#define EXERCICE1_1

// Fonction qui lit le flux entré au clavier et qui renvoie un pointeur sur la commande marquée sans le \n de fin
void Lecture_Flux(char * fluxEntrant);

#endif
