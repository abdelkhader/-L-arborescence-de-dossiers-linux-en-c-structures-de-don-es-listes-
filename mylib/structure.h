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
#include<string.h>
#define MAX_PATH 1024*2
#define MIN_PATH 100*2


typedef struct Entrees Entrees;
struct Entrees{
    char nomFich[MIN_PATH];
    Entrees *suivant;
};
typedef struct ListeEntrees ListeEntrees;
struct ListeEntrees
{
    Entrees *premier;
};



typedef struct Element Element;
struct Element
{
    char nom[MIN_PATH];
    char chemin[MAX_PATH];
    ListeEntrees *fichiers;
    Element *suivant;
};
typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};