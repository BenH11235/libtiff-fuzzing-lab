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
        just_read = read(0,buf,BUF_SIZE); 
        fwrite(buf, 1, just_read, f);
        done_reading = (just_read == 0? true : false);
    }
    fclose(f);
    TIFF* tif = TIFFOpen(TMPFILE, "r");
    int length, width;
    TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &width);
    TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &length);
    printf("Image width: %d\n", width);
    printf("Image length: %d\n", length);
    if(tif!=0) {
        TIFFClose(tif);
    }
    free(buf);
    return 0;
}
