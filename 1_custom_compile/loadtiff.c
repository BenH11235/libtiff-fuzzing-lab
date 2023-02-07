// #1 add the correct include path for the header file tiffio.h
// This file is part of your compiled libtiff, this should give you a hint where to look

//#include "/path/to/tiffio.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    //#2 invoke the function TIFFOpen to create a variable named "tif" of type TIFF*
    //run a web search for the documentation of this function
    
    if(tif!=0) {
        printf("TIFF load successful!\n");
        //#3 close the tif object using TIFFCLOSE
    } else {
        printf("TIFF load failed.\n");
    return 0;
    }
}
