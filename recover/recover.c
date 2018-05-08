#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)  // ensure an image file is passed in
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    char *infile = argv[1];  // set file

    FILE *inptr = fopen(infile, "r");  // check if the file can be opened - error checking
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);  // error message
        return 2;  // return 2
    }

    unsigned char buffer[512];
    char tempname[8];
    tempname[7] = '\0';
    FILE *img = NULL;
    int jpegName = 0;
    // char *outptr = "jpegName.jpg";


    while (fread(buffer, 1, 512, inptr) == 512) // will return 512(number) if true
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // check for start of JPEG
        {
            if (jpegName == 0) //checks to see if it is the first img
            {
                sprintf(tempname, "%03i.jpg",  jpegName);  // creates a formated string of data
                img = fopen(tempname, "w");  // opens the img file and makes it writeable
                fwrite(buffer, 1, 512, img);  // writes the buffer data to the img file
                jpegName++;  // increments the jpeg number

            }
            else  // if not the first img
            {
                fclose(img);  // close the previous file
                sprintf(tempname, "%03i.jpg",  jpegName);  // creates a formated string of data
                img = fopen(tempname, "w");  // opens the img file and makes it writeable
                fwrite(buffer, 1, 512, img);  // writes the buffer data to the img file
                jpegName++;  // increments the jpeg number

            }
        }
        else
        {
            if (img != NULL)
            {
            fwrite(buffer, 1, 512, img);
            }
        }

    };
    fclose(img);  // closes the last img file
}

// Open card file
// Repeat until end of card
//     read 512 bytes into a buffer
//     start of new JPEG?
//         yes...
//         no...
//     already found?
//         no... start first jpeg
//         yes... close previous jpeg, open new
// close any remaining files


