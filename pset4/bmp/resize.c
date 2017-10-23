/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy scale infile outfile\n");
        return 1;
    }


    // remember filenames
    int scale = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
    
    if ((scale<1)||(scale>100))
    {
        printf("Choose a scale greater than 0 and less than or equal to 100\n");
        return 4;
    }

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //Copy BITMAPINFOHEADER for output
    BITMAPINFOHEADER newbi = bi;
    
    //Set height and width of resized image
    newbi.biHeight=bi.biHeight*scale;
    newbi.biWidth=bi.biWidth*scale;
    
    // determine new padding for scanlines
    int newpadding =  (4 - (newbi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //Set biSizeImage and bfSize
    newbi.biSizeImage=((newbi.biWidth*sizeof(RGBTRIPLE))+newpadding)*abs(newbi.biHeight);
    bf.bfSize=newbi.biSizeImage+54;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&newbi, sizeof(BITMAPINFOHEADER), 1, outptr);



    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        //Write each scanline 'scale' times
        for (int m = 0; m < scale; m++)
        {
            
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
    
                //Write each pixel 'scale' times
                for (int n = 0; n < scale; n++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
    
            // skip over padding, in input file
            fseek(inptr, padding, SEEK_CUR);
    
            // write new padding in output file
            for (int k = 0; k < newpadding; k++)
            {
                fputc(0x00, outptr);
            }
            // move back to start of read scanline
            fseek(inptr, -(bi.biWidth*sizeof(RGBTRIPLE)+padding), SEEK_CUR);
        
        }
        //skip to end of read scanline
        fseek(inptr, (bi.biWidth*sizeof(RGBTRIPLE)+padding), SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
