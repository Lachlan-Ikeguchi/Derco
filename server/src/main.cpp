#include "main.hpp"

int main (int argc, char *argv[]) {
    printf("argc: %i\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv: %s\n", argv[i]);
    }
    return 0;
}
