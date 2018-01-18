#include <stdio.h>

#include <stdlib.h>



typedef struct needDelete

{

    int nombre;

    struct needDelete * next;

};

int i;

void deleteList( struct needDelete ** arrow , struct needDelete * r  );



int main()

{

    struct needDelete * arrow = ( struct needDelete *) malloc( sizeof( struct needDelete) );

    arrow -> next = NULL;



    struct needDelete * tete = arrow;

    struct needDelete * nouveau;



    for ( i = 0 ; i < 5 ; i++ )

    {

        nouveau = ( struct needDelete *) malloc( sizeof( struct needDelete) );

        nouveau -> nombre = 1;

        nouveau -> next = NULL;

        arrow -> next = nouveau;

        arrow = nouveau;

    }



    struct needDelete ** arroww;

    arroww = &tete;

    nouveau = tete;



    deleteList( arroww , nouveau );



    if ( tete == NULL )

        printf ( "\nThe list is empty \n" );



    return 0;

}



void deleteList( struct needDelete ** arrow , struct needDelete * r )

{

    while ( r -> next )

    {

        r = *arrow;

        *arrow = r -> next;

        free(r);

    }

}
