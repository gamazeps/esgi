#include <stdlib.h>

int main(int argc, char** argv) {
    int * test = malloc(sizeof(int));
    free(test);
    free(test);
    return 0;
}
