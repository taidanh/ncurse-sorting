#include "tools.h"

#include <stdbool.h>
#include <stdint.h>

uint64_t compares;
uint64_t moves;

bool my_compare(uint32_t i, uint32_t j) {
    // compares += 1;
    // i == A[i]
    // j == A[i - 1]
    return i < j;
}

bool comp_incr(uint32_t i, uint32_t j) {
    comp_add(1);
    // like my_compare, but increments compares
    return i < j;
}

void comp_add(int x) {
    // for sorts that don't directly swap
    compares += x;
    return;
}

void move_add(int x) {
    // for sorts that don't directly swap
    moves += x;
    return;
}

void init_count(void) {
    compares = 0;
    moves = 0;
    return;
}

void reset_count(void) {
    compares = 0;
    moves = 0;
    return;
}

void my_swap(uint32_t *A, uint32_t *B) {
    // moves += 3;
    uint32_t temp = *A;
    *A = *B;
    *B = temp;
    return;
}
