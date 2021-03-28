#include "curse_lib.h"
#include "quick.h"

#include "stack.h"
#include "tools.h"

#include <ncurses.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MULT 20
#define NAME "QUICK"

int64_t partition(uint32_t *A, uint32_t lo, uint32_t hi, uint32_t n, uint32_t height) {
    uint32_t pivot = A[lo + ((hi - lo) / 2)];
    // above counts as a comparison
    // comp_add(1);
    uint32_t i = lo - 1;
    uint32_t j = hi + 1;

    do {
        comp_add(1);
        i += 1;
        while (A[i] < pivot) {
            comp_add(1); // inner increment since while loop
            i += 1;
        }
        comp_add(1);
        j -= 1;
        while (A[j] > pivot) {
            comp_add(1); // inner increment since while loop
            j -= 1;
        }
        if (i < j) {
            move_add(3);
            my_swap(&A[i], &A[j]);
        }
	draw_array(A, n, height, MULT, NAME);
    } while (i < j);
    return j;
}

void quick_sort(uint32_t *A, uint32_t n, uint32_t height) {
    int64_t left = 0;
    int64_t right = n - 1;

    Stack *stack = stack_create();
    stack_push(stack, left);
    stack_push(stack, right);

    int64_t hi = 0;
    int64_t lo = 0;
    uint32_t p = 0;

    initscr();
    curs_set(false);

    while (!stack_empty(stack)) {
        stack_pop(stack, &hi);
        stack_pop(stack, &lo);
        p = partition(A, lo, hi, n, height);
        if (my_compare((p + 1), hi)) {
            stack_push(stack, p + 1);
            stack_push(stack, hi);
        }
        if (my_compare(lo, p)) {
            stack_push(stack, lo);
            stack_push(stack, p);
        }
    }
    stack_delete(&stack);
    endwin();
}
