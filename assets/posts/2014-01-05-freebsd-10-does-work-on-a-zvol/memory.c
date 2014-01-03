#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void alloc_one_meg() {
    int number_of_bytes_of_int = (int)sizeof(int);
    int number_of_ints_for_one_megabyte = 1024*1024/number_of_bytes_of_int;
    int *megabyte = malloc(sizeof(int) * number_of_ints_for_one_megabyte);

    for (int i=0; i < number_of_ints_for_one_megabyte; i++) {
        megabyte[i] = rand();
    }
}

void waitFor (unsigned int secs) {
    printf("waiting for %d seconds\n", secs);

    int retTime = time(0) + secs;
    while (time(0) < retTime);
}

int main ( int argc, char *argv[] )
{
    if ( argc != 2 ) {
        printf( "usage: %s <megabytes>\n", argv[0] );

    } else  {

        int number_of_megabytes;
        sscanf (argv[1],"%d",&number_of_megabytes);

        for (int i=0; i < number_of_megabytes; i++) {
            alloc_one_meg();
        }

        printf("allocated %d MB\n", number_of_megabytes);

        waitFor(600);
    }
}