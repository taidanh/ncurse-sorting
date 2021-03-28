#include "bubble.h"
#include "curse_lib.h"

#include "tools.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define MULT 1
#define NAME "BUBBLE"

void bubble_sort(uint32_t *A, uint32_t n, uint32_t height) {
    bool swapped = true;

    initscr();
    curs_set(false);

    while (swapped) {
        swapped = false;

        for (uint32_t i = 1; i < n; i += 1) {
            comp_add(1);
            if (my_compare(A[i], A[i - 1])) {
                move_add(3);
                my_swap(&A[i], &A[i - 1]);
                swapped = true;
            }
	    draw_array(A, n, height, MULT, NAME);
        }
        n -= 1;
    }
    endwin();
}
