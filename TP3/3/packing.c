/* Packing library definition */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "packing.h"

struct filestructure {
    char filename[MAX_FNAME_LENGTH];
    unsigned int num_of_bytes;
};

void file_packing(char *packed_file_name, int num_of_files, char **array_of_names) {
    FILE *packet_file;  // The final packed file containing all data
    FILE *f_in;         // Each file to be packed
    char *f_buff;       // File content buffer
    filestruct File;    // File 'metadata' structure

    // Open output/packed file for writing
    packet_file = fopen(packed_file_name, "w");
    if (packet_file == NULL) return;

    // For every file to pack
    for (int f = 0; f < num_of_files; f++) {

        // Get its name and open for reading (as bytes)
        strcpy(File.filename, array_of_names[f]);
        f_in = fopen(File.filename, "rb");
        if (f_in != NULL) {

            // Get size of the file (number of bytes)
            fseek(f_in, 0, SEEK_END);
            File.num_of_bytes = ftell(f_in);

            // Prep buffer to store the content of the file 
            f_buff = (char*)malloc(sizeof(char) * File.num_of_bytes);
            // Read and Store file content in file buffer
            fseek(f_in, 0, SEEK_SET);
            fread(f_buff, sizeof(char), File.num_of_bytes, f_in);

            // Write out to packet file: Name | Size | Content
            fwrite(File.filename, sizeof(char), MAX_FNAME_LENGTH, packet_file);
            fwrite(&File.num_of_bytes, sizeof(int), sizeof(int), packet_file);
            fwrite(f_buff, sizeof(char), File.num_of_bytes, packet_file);

            // Free buffer and Close file
            free(f_buff);
            fclose(f_in);
        }
    }
}

void file_unpacking(char *packed_file_name);

