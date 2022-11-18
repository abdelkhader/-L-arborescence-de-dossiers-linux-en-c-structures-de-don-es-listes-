# -L-arborescence-de-dossiers-linux-en-c-structures-de-don-nées-listes-

Il s’agit d'une application localisant rapidement une entrée de répertoire (fichier, répertoire, lien, etc)
sur le disque. Par exemple, la recherche de passwd doit trouver /etc/passwd. De même, la recherche de tmp doit trouver /tmp et /var/tmp.

2 fonctions : load qui charge en mémoire, dans une structure de données adaptée, une arborescence de répertoires, et search qui localise 
les occurrences d’une entrée donnée (dont le nom est fourni en argument) dans la structure de données précédente.

Avant d'exécuter faut choisir l'arboresrence de chargement

Pour exécuter ce projet, il faut faire un make dans le dossier mylib et revenir sur le dossier du projet et faire un autre make
et puis exécure le treetest suivit de du nom du fichier ou dossier à chercher.
