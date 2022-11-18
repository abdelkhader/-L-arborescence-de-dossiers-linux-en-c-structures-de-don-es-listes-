#include "mylib.h"

void searchListeEntrees(char n[MIN_PATH],char c[MAX_PATH],ListeEntrees *liste){
     if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Entrees *actuel = liste->premier;
    while (actuel != NULL)
    {
        
        if(strcmp(n,actuel->nomFich)==0){
            strcat(c,"/");
            strcat(c,n);
            //insertionEntrees(lE,chemin);
            printf("%s\n", c);
        }
        actuel = actuel->suivant;
    }
}

void search(char n[], Liste *l){
    //ListeEntrees *lE=malloc(sizeof(*lE));
    Element *actuel = l->premier;
    while(actuel != NULL){
        ListeEntrees *e=actuel->fichiers;
        
        searchListeEntrees(n,actuel->chemin,e);
        actuel = actuel->suivant;
    }
    //return lE;
}
