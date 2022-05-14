#include "packing.h"

int main() {
    char pack_name[] = "p.bin";
    int n = 1;
    char *fnames[1] =  {"f1"};

    file_packing(pack_name, n, fnames);

    return 1;
}
