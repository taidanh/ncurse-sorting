#include <ncurses.h>
#include <stdint.h>

void draw_pillar(uint32_t row, uint32_t height, uint32_t max);

void draw_array(uint32_t *A, uint32_t n, uint32_t height, uint32_t multiplier, char *name);

void startup(void);
