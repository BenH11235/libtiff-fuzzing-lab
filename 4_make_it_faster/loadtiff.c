#include "/usr/src/libtiff-Release-v4-0-6/libtiff/tiffio.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define BUF_SIZE 1024
#define RAND_BYTES_SIZE 10
#define ERRMSG_SIZE 1024
#define TMPFILE_BASE "/tmp/input.tif.tmp"

int main(int argc, char* argv[])
{
    
    //write input data to file
    char random_data[RAND_BYTES_SIZE];
    char random_suffix[RAND_BYTES_SIZE+1];
    /*
    #1. read RAND_BYTES_SIZE from /dev/urandom into random_data
    FILE * urandom = fopen(###, ###);
    fread(###, ###, ###, ###);
    fclose(urandom);
    */
    int i;
    //#2. complete the variable in brackets
    for (i=0; i< RAND_BYTES_SIZE; i++) {
        uint rng_out = ((random_data[i] % 16) + 16) % 16;
        //random_suffix[i] = "0123456789abcdef"[###];
    }
    random_suffix[RAND_BYTES_SIZE] = '\0';

    char* buf = malloc(BUF_SIZE*sizeof(char));
    char* fname = malloc(280*sizeof(char));
    sprintf(fname, "%s_%s", TMPFILE_BASE, random_suffix);
    FILE* f = fopen(fname,"a");
    bool done_reading = false;
    while(!done_reading) {
        int just_read;
        memset(buf, 0, BUF_SIZE);
        just_read = read(0,buf,BUF_SIZE); 
        fwrite(buf, 1, just_read, f);
        done_reading = (just_read == 0? true : false);
    }
    fclose(f);
        
    TIFF* tif = TIFFOpen(fname, "r");
    remove(fname);
    free(fname);
    
    if (!tif) {
        free(buf);
        return 1;
    }
    
        
    int width, length;
    char* emsg = malloc(ERRMSG_SIZE*sizeof(char));
    TIFFRGBAImage img;
    
    if (TIFFRGBAImageBegin(&img, tif, 0, emsg)) {
        TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &width);
        TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &length);

        int raster_size = width*length;
        tdata_t raster = _TIFFmalloc(raster_size*sizeof(uint32));
        TIFFRGBAImageGet(&img, (uint32*)raster, width, length);
        _TIFFfree(raster);
        TIFFRGBAImageEnd(&img);
    }
    free(emsg);
    TIFFClose(tif);
    free(buf);
    return 0;
}
