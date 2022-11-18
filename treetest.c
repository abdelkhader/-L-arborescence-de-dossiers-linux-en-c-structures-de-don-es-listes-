#include <stdio.h>
#include "mylib/mylib.h"

int main(int argc, char *argv[]){

char v1[BUFSIZ];
char v2[BUFSIZ];
FILE *fp;
char s[BUFSIZ];
fp=fopen("tree.conf","r");
if(fp==NULL)
{
    perror("tree.conf");
    return 1;
}
while(fgets(s,BUFSIZ,fp)!=NULL)
{     
    s[strlen(s)-1]='\0' ; // supprime le \n final 
    char *ptr = strchr(s,'#');

    if(ptr!=NULL)
    {
        *ptr='\0' ; //pour ne pas tenir compte des lignes de commentaire
    }
    else
    {
        continue;
    }
}

fclose(fp);

parse(s,v1,v2);

Liste *l;
l=initialisation();
load(v2,l);
//afficherListe(l);
if(argc !=2 )
{
    printf("Echec:\t./treetest nom\n");
    return 0;
}

printf("\n");
//printf("%s\n",argv[1]);
search(argv[1] ,l);

/*ListeEntrees *lE;
lE=initialisationEntrees();
insertionEntrees(lE,"Abdou");
insertionEntrees(lE,"Fatna");
afficherListeEntrees(lE);
searchListeEntrees("Abdou","/kadro/Abdou__ma",lE);
printf("\n");*/
//search(argv[2] ,l);
/*
Element *actuel = l->premier;
while(actuel != NULL){
    //ListeEntrees *lE=actuel->fichiers;
    //afficherListeEntrees(lE);
    //Entrees *e=lE->premier;
    //printf("%s\n", e->nomFich);
    searchListeEntrees(argv[2],actuel->chemin, actuel->fichiers);
    printf("%s\n",actuel->chemin);
    actuel = actuel->suivant;
}
*/

return 0;

}