#include <stdio.h>

#include <stdlib.h>



typedef struct listNode

{

    int no;

    struct listNode * next;

};



int sum( struct listNode* someList);

int i;



int main()

{

    struct listNode * p = ( struct listNode *) malloc ( sizeof( struct listNode ) );

    p -> next = NULL;



    struct listNode * head = p;

    struct listNode * newElement;



    for ( i = 0 ; i < 10 ; i++ )

    {

        newElement = ( struct listNode *) malloc ( sizeof( struct listNode ) );

        newElement -> no = rand() % 21;

        newElement -> next = NULL;



        p -> next = newElement;

        p = newElement;

    }



    p = head;



    printf ( "\nThe sum of the terms is: %d", sum( p ) );



    while( head -> next )

    {

        p = head -> next;

        free( head );

        head = p;

    }



    return 0;

}





int sum( struct listNode* someList)

{

    int sum = 0;



    while ( someList -> next )

    {

        someList = someList -> next;

        sum += someList -> no;

    }

    return sum;

}
