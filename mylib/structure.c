#include "structure.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#define false 0
#define true 1




ListeEntrees *initialisationEntrees(){
    ListeEntrees *liste = malloc(sizeof(*liste));
    Entrees *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    strcpy(element->nomFich,"");
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}
void insertionEntrees(ListeEntrees *liste, char c[MIN_PATH])
{
    /* Création du nouvel élément */
    Entrees *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(nouveau->nomFich,c);

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}
void afficherListeEntrees(ListeEntrees *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Entrees *actuel = liste->premier;
    while (actuel != NULL)
    {
        
        printf("%s\t", actuel->nomFich);
        actuel = actuel->suivant;
    }
    printf("\n");
}
ListeEntrees * copierListeEntrees(ListeEntrees *l1, ListeEntrees * l2){
    l2=initialisationEntrees();
    if (l1 == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Entrees *actuel = l1->premier;

    while (actuel != NULL)
    {
        char elt[MAX_PATH];
        strcpy(elt,actuel->nomFich);
        actuel = actuel->suivant;
    }
    return l2;
}



Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    strcpy(element->nom, "");
    strcpy(element->chemin,"");
    element->fichiers= NULL;
    
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste,char n[MIN_PATH], char c[MAX_PATH], ListeEntrees *lE)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(nouveau->nom,n);
    strcpy(nouveau->chemin,c);
    nouveau->fichiers=lE;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}


void insertionListe(Liste *liste,Element *e)
{
    
    if (liste == NULL || e == NULL)
    {
        exit(EXIT_FAILURE);
    };

    /* Insertion de l'élément au début de la liste */
    e->suivant = liste->premier;
    liste->premier = e;
}

void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    Element *actuel = liste->premier;
    while (actuel != NULL)
    {

        printf("||-Nom du dossier-||\t" );
        printf("%s\n", actuel->nom);
        printf("||-Nom du chemin-||\t" );
        printf("%s\n", actuel->chemin);
        printf("||-Les entées du dossier-|| ");
        afficherListeEntrees(actuel->fichiers);
        actuel = actuel->suivant;
        printf("\n\n");
    }
}