#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include <ctype.h>

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
    
    int k = atoi(argv[1]);
    
    if (k<0){
        printf("BAD INPUT");
        return 1;
    }

        
    string text=GetString();
    for(int i=0; i<strlen(text);i++){
        //check if character is in range of letters
        if(text[i]>64){
            //if below 91, uppercase letter
            if(text[i]<91){
                //uppercase letter
                printf("%c",rot(text[i],k,"upper"));
            }
            //if below 97, not a letter
            else if(text[i]<97){
                //non-letter
                printf("%c",text[i]);
            }
            //if below 123, lowercase letter
            else if(text[i]<123){
                //lowercase letter
                printf("%c",rot(text[i],k,"lower"));
            }
            //non-letter
            else printf("%c",text[i]);
        }
        //non-letter
        else printf("%c",text[i]);
    }
    printf("\n");
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
