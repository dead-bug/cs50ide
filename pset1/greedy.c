#include<stdio.h>
#include<cs50.h>
#include <math.h>

int CharDraw(char character, int count);

int main(void){
    
    printf("O hai! ");
    //Get change as a non negative float
    //Loop until valid float is given.
    float dollars;
    do{
        printf("How much change is owed?\n");
        dollars = GetFloat();
    } while (dollars<0);
    
    //convert to cents
    int cents = round(dollars*100);
    int coinSizes[] = {25,10,5,1};
    int coinCount = 0;
    
    
    for(int i=0; i<4;i++){
        coinCount+=cents/coinSizes[i];
        cents=cents%coinSizes[i];
    }
    printf("%i\n",coinCount);
    
    return 0;
    
}
    