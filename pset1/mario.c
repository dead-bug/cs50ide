#include<stdio.h>
#include<cs50.h>

int CharDraw(char character, int count);

int main(void){
    int height;
    //Get height as a non negative integer less than 23.
    //Loop until valid integer is given.
    do{
        printf("Height: ");
        height = GetInt();
    } while (height<0||height>23);
    
    for(int i=1;i<height+1;i++){
        //draw spaces
        CharDraw(' ',height-i);
        
        //draw hashes
        CharDraw('#',i+1);
        
        //draw new line
        printf("\n");
    }
    return 0;
}


// function to print characters (character) a certain number of times (count)
int CharDraw(char character, int count){
    for(int i=0;i<count;i++){
        printf("%c", character);
    }
    return 0;
}