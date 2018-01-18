#include <stdio.h>

#include <stdlib.h>





typedef struct add

{

    int info;

    struct add * next;

};

void Display( struct add * p );

void addFunction( struct add * p );



int i;

int index;



int main()

{

    struct add * arrow = (struct add*) malloc( sizeof( struct add) );

    arrow -> next = NULL;



    struct add * head = arrow;

    struct add * newEl;





    for ( i=0 ; i < 6 ; i++ )

    {

        newEl = ( struct add* ) malloc( sizeof( struct add) );

        newEl -> info = rand() % 15;

        newEl -> next = NULL;

        arrow -> next = newEl;

        arrow = newEl;

    }



    Display( head );



    printf( "\nEnter the index when the new node should add: \n" );

    scanf( "%d", &index );



    arrow = head;



    for( i=0 ; i < index - 1 ; i++ )

    {

        if( arrow -> next == NULL )

        {

            printf( "\nOverflow!\n" );



            while( head -> next )

            {

            arrow = head -> next;

            free(head);

            head = arrow;

            }



            return 0;

        }



        arrow = arrow -> next;

    }

    addFunction( arrow );

    Display( head );



    while( head -> next )

    {

        arrow = head -> next;

        free(head);

        head = arrow;

    }



    return 0;

}



void Display( struct add * p )

{

    printf ( "\n Now, the list looks like: " );



    while ( p -> next )

    {

        p = p -> next;

        printf ( "\n %d", p -> info );

    }

}



void addFunction( struct add * p )

{

    struct add * addEl = ( struct add*) malloc( sizeof( struct add));

    addEl -> info = rand() % 10 + 10;



    if ( p )

    {

        addEl -> next = p -> next;

        p -> next = addEl;

    }

}
