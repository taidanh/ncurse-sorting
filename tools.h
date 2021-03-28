#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <stdbool.h>
#include <stdint.h>

extern uint64_t compares;
extern uint64_t moves;

bool my_compare(uint32_t i, uint32_t j);

bool comp_incr(uint32_t i, uint32_t j);

void comp_add(int x);

void move_add(int x);

void init_count(void);

void reset_count(void);

void my_swap(uint32_t *A, uint32_t *B);

#endif
