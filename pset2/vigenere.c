#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include <ctype.h>

int CheckIfLetter(char c);
char offsetCalc(char c);
int rot();


int main(int argc, string argv[]){
    
    if (!argv[1]){
        printf("BAD INPUT");
        return 1;
    }
    if (argv[2]){
        printf("BAD INPUT");
        return 1;
    }
    
    string k = argv[1];
    
    for(int i=0; i<strlen(k);i++){
        if (!CheckIfLetter(k[i])){
            printf("BAD INPUT");
            return 1;
        }
    }
            
    
    
    if (k<0){
        printf("BAD INPUT");
        return 1;
    }

    string text=GetString();
    int keyCount=0;
    
    for(int i=0; i<strlen(text);i++){

        //check if character is in range of letters
        if(CheckIfLetter(text[i])){
            //if below 91, uppercase letter
            if(text[i]<91){
                //uppercase letter
                printf("%c",rot(text[i],offsetCalc(k[keyCount]),"upper"));
                keyCount+=1;
                keyCount%=strlen(k);
                //printf("%d\n",keyCount);
            }
            //if below 123, lowercase letter
            else if(text[i]<123){
                //lowercase letter
                printf("%c",rot(text[i],offsetCalc(k[keyCount]),"lower"));
                keyCount+=1;
                keyCount%=strlen(k);
                //printf("%d\n",keyCount);
            }
        }
        //non-letter
        else printf("%c",text[i]);
    }
    printf("\n");
    return 0;
    
}

int CheckIfLetter(char c){
    if(c>64){
            //if below 91, uppercase letter
            if(c<91){
                //uppercase letter
                return 1;

            }
            //if below 97, not a letter
            else if(c<97){
                //non-letter
                return 0;
            }
            //if below 123, lowercase letter
            else if(c<123){
                //lowercase letter
                return 1;
            }
            //non-letter
            return 0;
        }
        //non-letter
        return 0;
}

char offsetCalc(char c){
    if(CheckIfLetter(c)){
            //if below 91, uppercase letter
            if(c<91){
                //uppercase letter
                return c-65;

            }

            //if below 123, lowercase letter
            else{
                //lowercase letter
                return c-97;
            }

        }
        return 0;
}


int rot(int c, int k, string charCase){
        int zeroChar=0;
        if (strcmp(charCase,"upper")==0)
            zeroChar=64;
        if (strcmp(charCase,"lower")==0)
            zeroChar=96;
        
        c = (((c-zeroChar)+k)%26)+zeroChar;
        return c;
        
            
    }
    
    
