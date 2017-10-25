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
    
    void *ptr;
    ptr = (void *)malloc(512);;
    
    printf("test\n");
    for (int i=0; i<100; i++)
    {
        printf("%d: ",i);
        fread(ptr, 512, 1, file);
        printf("%p\n",ptr);
    }
    
}
