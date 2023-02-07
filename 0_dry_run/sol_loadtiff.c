#include "/usr/src/libtiff-Release-v4-0-6/libtiff/tiffio.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    TIFF* tif = TIFFOpen(argv[1], "r");
    if(tif!=0) {
        printf("TIFF load successful!\n");
        TIFFClose(tif);
    } else {
        printf("TIFF load failed.\n");
    return 0;
    }
}
