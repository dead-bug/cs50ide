/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Check number of arguments. If there aren't 2 or 3 command line arguments, prompt the user with correct usage.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Assign integer n as the number of pseudorandom numbers to print using the second command line argument.
    int n = atoi(argv[1]);

    // If the user provided a third command line arguemnt, use this as the seed for generating the pseudorandom numbers. Srand48 is an initialization functions that should be run before drand48().
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // Generate n random numbers using drand48(). drand48() returns a nonnegative double-precision
    //floating-point values uniformly distributed between [0.0, 1.0). Each number is scaled by the limit and printed as an integer.
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}