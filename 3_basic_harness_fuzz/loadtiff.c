#include "/usr/src/libtiff-Release-v4-0-6/libtiff/tiffio.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define BUF_SIZE 1024
#define ERRMSG_SIZE 1024
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
    remove(TMPFILE);
    
    if (!tif) {
        free(buf);
        return 1;
    }
    
    int width, length;
    TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &width);
    TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &length);
    //#1. set the raster_size - size (in pixels) of raster required to hold
    //image
    
    char* emsg = malloc(ERRMSG_SIZE*sizeof(char));
    TIFFRGBAImage img;

    /*
      #2 Convert the TIFF image into a raster using TIFFRGBAImage functions.
      Search web for documentation of functions: TIFFRGBAImageBegin,
      TIFFRGBAImageGet, TIFFRGBAImageEnd.
    
    if (TIFFRGBAImage###(###, ###, ###, ###)) {
        tdata_t raster = _TIFFmalloc(###*sizeof(uint32));
        TIFFRGBAImage###(###, (uint32*)###, ###, ###);
        _TIFFfree(raster);
        TIFFRGBAImage###(###);
    }

    */
    free(emsg);
    TIFFClose(tif);
    free(buf);
    return 0;
}
