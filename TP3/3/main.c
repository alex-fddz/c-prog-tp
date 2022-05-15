#include <stdio.h>
#include <string.h>
#include "packing.h"

#define PACK_PARAM "-p"
#define UNPACK_PARAM "-u"

int main(int argc, char **argv) {
    char *pack_name = "p.bin";
    int n = 2;
    char *fnames[2] =  {"f1", "f2"};
    
    if (argc < 2) { // should be 3 normally
        show_help();
        return 0;
    }
    
    if (0 == strcmp(argv[1], PACK_PARAM)) {
        printf("Packing ...\n");
        //file_packing(pack_name, n, fnames);
        printf("Done!\n");
    }
    else if (0 == strcmp(argv[1], UNPACK_PARAM)) {
        printf("Unpacking ...\n");
        //file_unpacking(pack_name);
        printf("Done!\n");
    }
    else {
        show_help();
    }
    
    return 1;
}
