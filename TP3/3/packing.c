/* Packing library definition */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include "packing.h"

struct filestructure {
    char filename[MAX_FNAME_LENGTH];
    unsigned int num_of_bytes;
};

void show_help() {
    printf("Help\n");
}

char *create_unpack_folder(char *fname) {
    // Create a copy of folder name
    char *dirname;
    strcpy(dirname, fname);
    // Create a directory that does not exist
    int j = 1;
    errno = 0;
    while (mkdir(dirname, S_IRWXU) == -1 && errno == EEXIST) {
        sprintf(dirname, "%s(%d)", fname, j);
        j++;
    }
    return dirname;
}

int check_file_exists(char *fname) {
    // Return 1 if file exists, 0 otherwise
    return access(fname, F_OK) == 0 ? 1 : 0;
}

void file_packing(char *packed_file_name, int num_of_files, char **array_of_names) {
    FILE *packet_file;  // The final packed file containing all data
    FILE *f_in;         // Each file to be packed
    char *f_content;       // File content buffer
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
            f_content = (char*)malloc(sizeof(char) * File.num_of_bytes);
            // Read and Store file content in file buffer
            fseek(f_in, 0, SEEK_SET);
            fread(f_content, sizeof(char), File.num_of_bytes, f_in);

            // Write out to packet file: Name | Size | Content
            fwrite(File.filename, sizeof(char), MAX_FNAME_LENGTH, packet_file);
            fwrite(&File.num_of_bytes, sizeof(int), sizeof(int), packet_file);
            fwrite(f_content, sizeof(char), File.num_of_bytes, packet_file);

            // Free buffer and Close file
            free(f_content);
            fclose(f_in);
        }
    }
    fclose(packet_file);
}

void file_unpacking(char *packed_file_name) {
    FILE *packet_file;
    FILE *f_out;
    char *f_content;
    unsigned bytes_to_unpack;
    filestruct File;

    // Open packet file for reading (as bytes)
    packet_file = fopen(packed_file_name, "rb");
    if (packet_file == NULL) return;

    // Unpack in a new folder
    chdir(create_unpack_folder(DEF_UNPACK_FNAME));

    // Get the total size of the packed file (byte to unpack)
    fseek(packet_file, 0, SEEK_END);
    bytes_to_unpack = ftell(packet_file);
    fseek(packet_file, 0, SEEK_SET); // reset to start of file

    // While there are bytes to read, get: Name | Size | Content
    while(ftell(packet_file) < bytes_to_unpack) {

        // Get file's -metadata-
        fread(File.filename, sizeof(char), MAX_FNAME_LENGTH, packet_file);
        fread(&File.num_of_bytes, sizeof(int), sizeof(int), packet_file);

        // Prep file content buffer to store file's bytes
        f_content = (char*)malloc(sizeof(char) * File.num_of_bytes);
        fread(f_content, sizeof(char), File.num_of_bytes, packet_file);

        // Create and write out file
        f_out = fopen(File.filename, "w");
        if (f_out != NULL) {
            fwrite(f_content, sizeof(char), File.num_of_bytes, f_out);
        }

        // Free buffer and close file
        free(f_content);
        fclose(f_out);
    }
    fclose(packet_file);
}

