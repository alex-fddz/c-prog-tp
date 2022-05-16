#include <stdio.h>
#include <string.h>
#include "packing.h"

int main(int argc, char **argv) {
    int n = argc - 2;
    char *fnames[n];

    // Check for a valid input / call
    if (argc < 3) { 
        show_help();
        return 0;
    }

    /* File packing */
    if (0 == strcmp(argv[1], PACK_PARAM)) {
        printf("Packing %d file(s) ...\n", n);

        // Get files to pack
        for (int i = 0; i < n; i++) {
            fnames[i] = argv[i+2];
            // and validate files exist
            if (!check_file_exists(fnames[i])) {
                printf("ERR: One or more specified files do not exist.\n");
                return 0; // End program if a file does not exist
            }
        }

        // Pack files
        file_packing(DEF_PACKET_FNAME, n, fnames);

        printf("Done!\n");
    }

    /* File Unpacking */
    else if (0 == strcmp(argv[1], UNPACK_PARAM)) {
        printf("Unpacking ...\n");

        // Validate file
        if (!check_file_exists(argv[2])) {
            printf("ERR: One or more specified files do not exist.\n");
            return 0; // End program if file does not exist
        }

        // Unpack files
        file_unpacking(argv[2]);

        printf("Done!\n");
    }

    else { // Invalid param
        show_help();
    }

    return 1;
}
