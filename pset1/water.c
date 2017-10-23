#include<stdio.h>
#include<cs50.h>

int GetShowerLength();
int CalculateBottles();

int main(void){
    int showerLength;
    int bottles;
    showerLength = GetShowerLength();
    bottles = CalculateBottles(showerLength);
    printf("bottles: %i\n",bottles);
    
}

int GetShowerLength(void){
    int showerLength;
    do{
        printf("minutes: ");
        showerLength = GetInt();
    } while (showerLength < 1);
    return showerLength;
}

int CalculateBottles(int showerLength){
    int bottles;
    return bottles = showerLength*12;
}