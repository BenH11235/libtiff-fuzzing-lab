#include "/usr/src/libtiff-Release-v4-0-6/libtiff/tiffio.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define BUF_SIZE 1024
#define TMPFILE "/tmp/input.tif.tmp"

int main(int argc, char* argv[])
{
    char* buf = malloc(BUF_SIZE*sizeof(char));
    FILE* f = fopen(TMPFILE ,"a");
    bool done_reading = false;
    while(!done_reading) {
        int just_read;
        memset(buf, 0, BUF_SIZE);
        //#1. read BUF_SIZE bytes from the standard input and write them to
        //the temp file.
        done_reading = (just_read == 0? true : false);
    }
    fclose(f);
    //#2. open the resulting temp file as a TIFF object.
    int length, width;
    //#3. use the function TIFFGetField to obtain the image width and length.
    printf("Image width: %d\n", width);
    printf("Image length: %d\n", length);
    if(tif!=0) {
        TIFFClose(tif);
    }
    free(buf);
    return 0;
}
