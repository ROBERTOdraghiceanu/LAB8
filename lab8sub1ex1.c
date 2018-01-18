#include <stdio.h>

#include <stdlib.h>



typedef struct portocala

{

    int no;

    struct portocala * next;

};



int i;

int searched;

int contor = 0;



int countf ( struct portocala * p );



int main()

{

    struct portocala * p = (struct portocala *) malloc( sizeof( struct portocala) );

    p -> next = NULL;



    struct portocala * head = p;

    struct portocala * newEl;



    for ( i = 0 ; i < 10 ; i++ )

    {

        newEl = (struct portocala *) malloc( sizeof( struct portocala) );

        newEl -> no = rand() % 10;

        newEl -> next = NULL;

        p -> next = newEl;

        p = newEl;

    }



    p = head;



    for ( i = 0 ; i < 10 ; i++ )

    {

        p = p -> next;

        printf ( "\n %d ", p -> no );

    }



    printf ( "\n Enter the searched number: " );

    scanf ( "%d", &searched );



    p = head;



    printf ( "\n The number of appearances is:  %d \n", countf( p ) );



    while( head -> next )

    {

        p = head -> next;

        free( head );

        head = p;

    }



    return 0;

}



int countf ( struct portocala * p )

{

    int contor = 0;



    while ( p -> next )

    {

        p = p -> next;

        if ( p -> no == searched )

            contor++;

    }



    return contor;

}
