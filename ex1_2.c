#include "ex1_2.h"




int main (){
      
     char fluxEntrant[TAILLELECTURE];

     printf("\nBonjour Monsieur Coninx et Monsieur Rocherolle. Que souhaitez-vous faire ?\n ");
      
     // Lire lettre par lettre le flux d'entré
     while (strcmp(fluxEntrant,"exit") != 0) { // Tant que les deux chaînes sont différentes

	  // On commence par lire le flux rentrant
	  Lecture_Flux_Arg(fluxEntrant); 

	  // On fait un fork
	  pid_t pid ;
	  pid = fork();

	  // Si le fork n'a pas fonctionné
	  if (pid < 0){
	       perror("fork ");
	  }
	  
	  // Si on est dans le processus fils
	  else if (pid == 0){
	       printf("Nous sommes dans le fils \n");

	       char *argv[16];
	       printf("fluxEntrant : %s\n",fluxEntrant);
	       argv[0]=fluxEntrant;

	       // ici NULL dans argv[2] car on s'occupe des cas sans arguments à l'exécution
	       argv[1]=NULL;

	       printf("flux entrant 2 : %s\n", fluxEntrant);
	       // On vérifie qu'il n'y a ps de problème à l'éxécution de execvp
	       if (execvp(argv[0],argv) < 0){
		    perror("execvp ");
	       }
	  }

	   
	  // Si on est dans le père
	  else {
	       int status;
	       //TEST
	       printf("Nous sommes dans le père \n");
	       while(wait(&status) != pid){
	       }
	  }
	  
     }
     return(0);
}

void Lecture_Flux_Arg(char * fluxEntrant){
     
     char * marquageFin;

     // On utilise fgets pour prendre le mot saisie au clavier par l'utilisateur
     if (fgets(fluxEntrant,TAILLELECTURE,stdin) == NULL){
	  // Si un problème occure lors de l'utilisation de la fonction, on appelle perror
	  perror("Problème gets");
     }

     if (strlen(fluxEntrant) < 99){
	  // A la fin de la chaîne de caractère, on a toujours \n, on utilise strrchr pour pointer sur sa position
	  marquageFin = strrchr(fluxEntrant,'\n');
	  // On le remplace par un autre carazctère "neutre"
	  *marquageFin = '\0';
     }

     // Dans le cas où la commande a depassé du buffer ou ==, on utilise getchar pour vider le buffer
     else{
	  char trash;
	  do {
	       trash = getchar();
	  } while(trash != '\n' && trash != EOF);
     }
     printf("\nflux entrant : %s\n", fluxEntrant);

}


     
