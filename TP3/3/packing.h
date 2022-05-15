/* Packing library */

#ifndef PACKING_H_
#define PACKING_H_

#define PACK_PARAM "-p"
#define UNPACK_PARAM "-u"
#define DEF_PACKET_FNAME "packet_file.bin"

#define MAX_FNAME_LENGTH 256

struct filestructure;

typedef struct filestructure filestruct;

void show_help();

void file_packing(char *packed_file_name, int num_of_files, char **array_of_names);

void file_unpacking(char *packed_file_name);

#endif /* PACKING_H_ */
