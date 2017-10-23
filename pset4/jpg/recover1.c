/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* file = fopen("card.raw", "r");
    //int IMGcount = 0;
    //char *buffer=malloc(sizeof(4));
    //char buffer=malloc(sizeof(char));
    
    printf("test\n");
    for (int i=0; i<10000000; i+=100000)
    {
        printf("%d: ",i);
    int j = fgetc(file);

    if (j != EOF)
        printf("first byte = %d\n", j);
    }
    
}
