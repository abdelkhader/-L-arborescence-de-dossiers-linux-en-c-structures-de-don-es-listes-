#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#define false 0
#define true 1
typedef int bool;
#define MAX_PATH 1024*2
#define MIN_PATH 100*2
#include "structure.h"


ListeEntrees *initialisationEntrees();
void insertionEntrees(ListeEntrees *liste, char c[MIN_PATH]);
void afficherListeEntrees(ListeEntrees *liste);
ListeEntrees * copierListeEntrees(ListeEntrees *l1, ListeEntrees * l2);
Liste *initialisation();
void insertion(Liste *liste,char n[MIN_PATH], char c[MAX_PATH], ListeEntrees *lE);
void insertionListe(Liste *liste,Element *e);
void afficherListe(Liste *liste);


Element * loadRep(char n[MIN_PATH],char c[MIN_PATH]);
Liste * loadReps(char dir[MAX_PATH],Liste *l);
Liste * load(char dir[MAX_PATH],Liste *l);



void search(char n[MIN_PATH], Liste *l);
void searchListeEntrees(char n[MIN_PATH],char c[MAX_PATH],ListeEntrees *lE);

int parse(const char *src, char *v1, char *v2);
