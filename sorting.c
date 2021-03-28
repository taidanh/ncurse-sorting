#include "curse_lib.h"
#include "bubble.h"
#include "heap.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stack.h"
#include "tools.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define OPTIONS "absqhr:"

enum Sorts { bubble = 1, shell = 2, quick = 3, heap = 4 };

void print_array(uint32_t *A, int max, int len) {
    int i;
    if (max == 0) {
        return;
    }
    for (i = 0; i < max; i += 1) {
        if (i >= (len)) {
            return;
        }
        printf("%13" PRIu32, A[i]);
        if (i % 5 == 4) {
            putc('\n', stdout);
        }
    }
    if ((i - 1) % 5 == 4) {
        return;
    } else {
        // prevent double new line
        printf("i %% 5 == %d\n", i % 5);
        putc('\n', stdout);
        return;
    }
}

void print_invalid(char *fn) {
    fprintf(stderr, "SYNOPSYS\n");
    fprintf(stderr, "   A collection of comparison-based sorting algorithms.\n");
    fputc('\n', stderr);
    fprintf(stderr, "USAGE\n");
    fprintf(stderr, "   %s [-absqh] [-n length] [-r seed]\n", fn);
    fputc('\n', stderr);
    fprintf(stderr, "OPTIONS\n");
    fprintf(stderr, "   -a              Enable all sorts.\n");
    fprintf(stderr, "   -b              Enable Bubble Sort.\n");
    fprintf(stderr, "   -s              Enable Shell Sort.\n");
    fprintf(stderr, "   -q              Enable Quick Sort.\n");
    fprintf(stderr, "   -h              Enable Heap Sort.\n");
    fprintf(stderr, "   -r seed         Specify random seed.\n");
    return;
}

int main(int argc, char **argv) {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    Set sorts = set_empty();
    uint32_t n = w.ws_col; // length of list
    uint32_t height = w.ws_row;
    uint r = 7092016; // seed
    int opt = 0;
    init_count(); // set counters to 0

    if (argc == 1) {
        fprintf(stderr, "Select at least one sort to perform.\n");
        print_invalid(argv[0]);
        exit(1);
    }

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            sorts = set_insert(sorts, bubble);
            sorts = set_insert(sorts, shell);
            sorts = set_insert(sorts, quick);
            sorts = set_insert(sorts, heap);
            break;
        case 'b': sorts = set_insert(sorts, bubble); break;
        case 's': sorts = set_insert(sorts, shell); break;
        case 'q': sorts = set_insert(sorts, quick); break;
        case 'h': sorts = set_insert(sorts, heap); break;
        case 'r': r = atoi(optarg); break;
        default: print_invalid(argv[0]); exit(1);
        }
    }

    srandom(r);

    uint32_t A[n];

    for (uint32_t i = 0; i < n; i += 1) {
        // 30 bit long number
        A[i] = random() % height;
	A[i] += 1;
        // 3 == 0011 shifted to 31st and 30th place then
        // NOTd to make it a mask that clears those bits
    }

    if (set_member(sorts, bubble)) {
        reset_count();
        uint32_t B[n]; // copies contents of A to B as local
        for (uint32_t i = 0; i < n; i += 1) {
            B[i] = A[i];
        }
        bubble_sort(B, n, height);
        printf("Bubble Sort\n");
	printf("%d elements, %lu moves, %lu compares\n", n, moves, compares);
    }

    if (set_member(sorts, shell)) {
        reset_count();
        uint32_t B[n];
        for (uint32_t i = 0; i < n; i += 1) {
            B[i] = A[i];
        }
        shell_sort(B, n, height);
        printf("Shell Sort\n");
	printf("%d elements, %lu moves, %lu compares\n", n, moves, compares);
    }

    if (set_member(sorts, quick)) {
        reset_count();
        uint32_t B[n];
        for (uint32_t i = 0; i < n; i += 1) {
            B[i] = A[i];
        }
        quick_sort(B, n, height);
        printf("Quick Sort\n");
	printf("%d elements, %lu moves, %lu compares\n", n, moves, compares);
    }

    if (set_member(sorts, heap)) {
        reset_count();
        uint32_t B[n];
        for (uint32_t i = 0; i < n; i += 1) {
            B[i] = A[i];
        }
        heap_sort(B, n, height);
        printf("Heap Sort\n");
	printf("%d elements, %lu moves, %lu compares\n", n, moves, compares);
    }

    return 0;
}
