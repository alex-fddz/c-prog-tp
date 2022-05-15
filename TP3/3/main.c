#include <stdio.h>
#include <string.h>
#include "packing.h"

int main(int argc, char **argv) {
    int n = argc - 2;
    char *fnames[n];
    
    if (argc < 2) { // should be 3 normally
        show_help();
        return 0;
    }
    
    if (0 == strcmp(argv[1], PACK_PARAM)) {
        printf("Packing %d file(s) ...\n", n);
        
        // Get files to pack
        for (int i = 0; i < n; i++) {
            fnames[i] = argv[i+2];
        }
        file_packing(DEF_PACKET_FNAME, n, fnames);
        
        printf("Done!\n");
    }
    else if (0 == strcmp(argv[1], UNPACK_PARAM)) {
        printf("Unpacking ...\n");
        
        file_unpacking(argv[2]);
        
        printf("Done!\n");
    }
    else {
        show_help();
    }
    
    return 1;
}
