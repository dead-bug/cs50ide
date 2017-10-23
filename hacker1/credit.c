#include<stdio.h>
#include<cs50.h>
#include<string.h>

bool CheckIfValid();
int PrintCardType();

int main(void){
    long long number;
    char numberString[sizeof(long long)];

    printf("Number: ");
    number = GetLongLong();
    sprintf(numberString, "%lld", number);

    if (CheckIfValid(numberString)!=1){
        printf("INVALID\n");
        return 0;
    }
    
    PrintCardType(numberString);
    
}

bool CheckIfValid(char* numberString){
    int sumEven=0;
    int sumOdd=0;
    for(int i=strlen(numberString)-1; i>-1;i-=2){
        sumOdd+=numberString[i] - '0';
    }
    for(int i=strlen(numberString)-2; i>-1;i-=2){
        char currentEven[sizeof(int)];
        sprintf(currentEven, "%i", 2*(numberString[i] - '0'));
        for(int i=0; i<strlen(currentEven);i++){
            sumEven+=currentEven[i] - '0';
        }
    }
    int checkSum = sumOdd + sumEven;
    if(checkSum%10==0){
        return 1;
    }
    else {
        return 0;
    }
}

int PrintCardType(char* numberString){
    char firstTwoChars[3];
    strncpy(firstTwoChars, numberString, 2);
    firstTwoChars[2]=0;

    if(strlen(numberString)==15){
        if((strcmp(firstTwoChars,"34")==0)||
        (strcmp(firstTwoChars,"37")==0)){
        printf("AMEX\n");
        }
        else printf("INVALID\n");
    }
    
    if(strlen(numberString)==16){
        if((strcmp(firstTwoChars,"51")==0)||
        (strcmp(firstTwoChars,"52")==0)||
        (strcmp(firstTwoChars,"53")==0)||
        (strcmp(firstTwoChars,"54")==0)||
        (strcmp(firstTwoChars,"55")==0)){
        printf("MASTERCARD\n");
        }
        
        else if(firstTwoChars[0]=='4'){
        printf("VISA\n");
        }
        
        else printf("INVALID\n");
    }
    
     if(strlen(numberString)==13){
        if(firstTwoChars[0]=='4'){
        printf("VISA\n");
        }
        else printf("INVALID\n");
    }
    
    return 0;
    
}