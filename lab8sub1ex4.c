#include <stdio.h>

#include <stdlib.h>



typedef struct stacck

{

    int info;

    struct stacck * next;

};



void Push ( struct stacck ** p );

void Pop( struct stacck ** head );

void Afisare ( struct stacck * p );



int press;

int i;



int main()

{

    struct stacck * p = ( struct stacck*) malloc( sizeof( struct stacck) );

    p -> next = NULL;



    struct stacck ** pp = &p;



    for ( i=0 ; ; i++ )

    {

        printf ( "\nIf you want to add a new value, press 1\n If you want to delete a value, press 2\n" );

        scanf ( "%d", &press );



        if ( press == 1 )

        {

            Push( pp );

            Afisare ( p );

            printf ( "\n" );

        }

        if ( press == 2 )

        {

            Pop( pp );

            Afisare ( p );

            printf ( "\n" );

        }

    }



    return 0;

}



void Push( struct stacck ** p )

{

    struct stacck * newEl = (struct stacck *) malloc( sizeof( struct stacck) );



    printf ( "\nEnter the new value: ");

    scanf ( "%d", &newEl -> info);



    newEl -> next = *p ;

    *p = newEl;

}



void Pop( struct stacck ** head )

{

    struct stacck * r;

    r = *head;



    if ( r -> next )

    {

        *head = r -> next ;

        printf ( "\n You delete the node with the value : %d \n", r -> info );

        free (r);

    }

    else

        printf ("\nAttention! Empty list!\n");

}



void Afisare ( struct stacck * p )

{

    printf ( "\n Now, the stack looks like : ");



    if ( p -> next == NULL )

        printf( "\nEmpty list!\n" );



    while ( p -> next )

    {

        printf ( "\n%d " , p -> info );

        p = p -> next;

    }

}
