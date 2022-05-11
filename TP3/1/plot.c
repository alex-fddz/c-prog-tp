#include <stdio.h>
#include <stdlib.h>

#ifdef __unix__
#define drawPlot(f) \
    snprintf(cmd, sizeof(cmd), "gnuplot --persist -e 'plot \"%s\"'", f); \
    system(cmd);
#else
#error "OS not supported!"    
#endif

int main() {
    char cmd[100];
    char* filename = "function_data";
    
    drawPlot(filename);

    
    return 1;
}
