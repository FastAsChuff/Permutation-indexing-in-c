#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include </home/simon/permutationsindexes.c>


// gcc permutations.c -o permutations.bin -O3 -march=native -Wall

int main(int argc, char** argv) {
    int n = 5;
    if (argc >= 2) {
      n = atoi(argv[1]);
    }
    if (n > 0) print_all_ptindexes(n);
    return 0;
}
