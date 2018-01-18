#include <stdio.h>

#include <stdlib.h>



typedef struct hola

{

    int info;

    struct hola * next;

};



int i;

int index;



void getNth ( struct hola * p );



int main()

{

    struct hola * arrow = ( struct hola *) malloc( sizeof( struct hola) );

    arrow -> next = NULL;



    struct hola * head = arrow;

    struct hola * newnew;



    for ( i = 0 ; i < 12 ; i++ )

    {

        newnew = ( struct hola *) malloc ( sizeof( struct hola) );

        newnew -> info = rand() % 50;

        newnew -> next = NULL;

        arrow -> next = newnew;

        arrow = newnew;

    }



    arrow = head;

    for ( i = 0 ; i < 12 ; i++ )

    {

        arrow = arrow -> next;

        printf ( "\n%d", arrow -> info );

    }



    printf ( "\nEnter the index position: ");

    scanf ( "%d", &index );



    arrow = head;



    getNth ( arrow );



    while( head -> next )

    {

        arrow = head -> next;

        free( head );

        head = arrow;

    }



    return 0;

}



void getNth ( struct hola * p )

{

    int i;

    int ok = 1;



    for ( i = 0 ; i < index ; i++ )

    {

        p = p -> next;

        if ( p -> next == NULL && i >= index )

        {

            ok = 0;

            break;

        }

    }



    if ( ok )

        printf ( "\nThe data value stored in the node at that index position is : %d \n ", p -> info );

    else

        printf ( "\nThe list is shortest then this index! \n ");

}
