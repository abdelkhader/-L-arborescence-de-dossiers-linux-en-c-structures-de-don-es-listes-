#include "mylib.h"

Element * loadRep(char n[MIN_PATH],char c[MIN_PATH]){
    Element *e=malloc(sizeof(*e));
    ListeEntrees *fichs=initialisationEntrees();
   struct dirent *dp;
   DIR *dfd;
 
   if ((dfd = opendir(c)) == NULL) {
      fprintf(stderr, "Echec d'ouverture du dossier: %s\n", n);
      exit(EXIT_FAILURE);
   }
    //dp = readdir(dfd);
    strcpy(e->nom,n);
    strcpy(e->chemin,c);
    //strcat(c,"/");
    //strcpy(e->chemin, c);
    while ( (dp = readdir(dfd)) != NULL){
        /*if (dp->d_type == DT_DIR){
            if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
                continue;
            insertionEntrees(fichs,dp->d_name);
        }
        else
             insertionEntrees(fichs,dp->d_name);*/
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
                continue;
        insertionEntrees(fichs,dp->d_name);
    }
    e->fichiers=fichs;
   closedir(dfd);
   return e;
}

Liste * loadReps(char dir[MAX_PATH],Liste *l)
{
    /*char const racine[MIN_PATH];
    racine=dir;*/
   char path[MAX_PATH]="";
   //char pathElse[MAX_PATH]="";
   struct dirent *dp;
   DIR *dfd;
    //printf("%s\n", dir);
   if ((dfd = opendir(dir)) == NULL) {
      fprintf(stderr, "Echec d'ouverture du dossier: %s\n", dir);
      exit(EXIT_FAILURE);
   }
    //ListeEntrees *fichs=initialisationEntrees();
    while ( (dp = readdir(dfd)) != NULL){
        
        if (dp->d_type == DT_DIR){
            path[0] = '\0';
            if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
                continue;
            Element *e=malloc(sizeof(*e));
            char c[MAX_PATH];
            strcpy(c,dir);
            strcat(c,"/");
            strcat(c,dp->d_name);
            e=loadRep(dp->d_name,c);//insertionEntrees(fichs, dp->d_name);
            sprintf(path, "%s/%s", dir, dp->d_name);
            insertionListe(l,e);
            loadReps(path, l);
      }
      //else
        //continue;
      //sprintf(pathElse, "/%s", dir);
      //insertion(l, dir,/*pathElse,*/ fichs);
    }   
    closedir(dfd);
   return l;
}

Liste * load(char dir[MAX_PATH],Liste *l)
{
    Element *e=malloc(sizeof(*e));
    e=loadRep(dir,dir);
    insertionListe(l,e);
    loadReps(dir,l);
    return l;
}

