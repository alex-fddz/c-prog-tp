/* Packing library */

#ifndef PACKING_H_
#define PACKING_H_

#define MAX_FNAME_LENGTH 256

struct filestructure;

typedef struct filestructure filestruct;

void show_help();

void file_packing(char *packed_file_name, int num_of_files, char **array_of_names);

void file_unpacking(char *packed_file_name);

#endif /* PACKING_H_ */
