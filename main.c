#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "point.h"

int main()
{
    t_file* mafile = NULL;
    t_point* p = NULL;

    mafile = file_creer();

    if(file_vide(mafile))
        printf("file vide\n");
    else
        printf("file non vide\n");

    printf("on ajoute un point\n");
    p = point_creer(1,1);
    file_enfiler(mafile,p);

    if(file_vide(mafile))
        printf("file vide\n");
    else
        printf("file non vide\n");

    p = point_creer(2,2);
    file_enfiler(mafile,p);

    p = point_creer(3,3);
    file_enfiler(mafile,p);

    // on affiche le sommet actuel
    point_afficher(file_elem_sommet(mafile));

    p = point_creer(4,4);
    file_enfiler(mafile,p);

    p = point_creer(5,5);
    file_enfiler(mafile,p);

    p = file_defiler(mafile);
    // on affiche l'élément défilé
    point_afficher(p);

    // on affiche le sommet actuel
    point_afficher(file_elem_sommet(mafile));

    // on vide la file
    file_vider(mafile, (tpf_detruire)point_detruire);
    if(file_vide(mafile))
        printf("file vide\n");
    else
        printf("file non vide\n");

    file_detruire(mafile, (tpf_detruire)point_detruire);

    return 0;
}
