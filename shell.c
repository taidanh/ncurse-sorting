#include "curse_lib.h"
#include "shell.h"

#include "gaps.h"
#include "tools.h"

#include <ncurses.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MULT 15

void shell_sort(uint32_t *A, uint32_t n, uint32_t height) {
    initscr();
    curs_set(false);

    for (uint32_t k = 0; k < GAPS; k += 1) {
        for (uint32_t i = gaps[k]; i < n; i += 1) {
            uint32_t j = i;
            uint32_t temp = A[i];
            while ((j >= gaps[k]) && comp_incr(temp, A[j - gaps[k]])) {
                my_swap(&A[j], &A[j - gaps[k]]);
                move_add(3);
                j -= gaps[k];
		draw_array(A, n, height, MULT);
            }
            A[j] = temp;
        }
    }
    draw_array(A, n, height, 200);
    endwin();
    return;
}
