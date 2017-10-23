/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>


#include "helpers.h"

bool binarySearch();

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{

    if(binarySearch(value, values, 0, n-1))
            return true;
    
    else return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for(int i=1; i<n; i++){
        int temp=values[i];
        for(int j=i-1; j>-1; j--){
            if (temp<values[j]){
                values[j+1]=values[j];
                values[j]=temp;
            }
            else break;
        }
    }
    return;
    
}

bool binarySearch(int value, int values[], int min, int max){
    
    int midpoint;
    
    //if (max<min){
    //    return false;
    // }
    //else {
        midpoint = (max+min)/2;
    //}
    
    if (min<=max){
        
    
        if (value == values[midpoint]){
            return true;
        }
        else if (value < values[midpoint]){
            return binarySearch(value, values, min, midpoint-1);
        }
        else{
            return binarySearch(value, values, midpoint+1, max);
        }
    }
    
    return false;

}