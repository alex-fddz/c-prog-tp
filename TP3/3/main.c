#include "packing.h"

int main() {
    char *pack_name = "p.bin";
    int n = 2;
    char *fnames[2] =  {"f1", "f2"};

    //file_packing(pack_name, n, fnames);
    file_unpacking(pack_name);

    return 1;
}
