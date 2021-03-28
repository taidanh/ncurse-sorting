#include <stdint.h>
#include <errno.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PILLAR "#"
#define DELAY 1000
#define MAX 16

void draw_pillar(uint32_t col, uint32_t height, uint32_t max) {
    for (uint32_t row = 0; row < max; row += 1) {
	if (row >= (max - height)) {
	    mvprintw(row, col, PILLAR);
	} else {
	    mvprintw(row, col, " ");
	}
    }
    return;
}

void draw_title(char *name) {
    char title[MAX];
    sprintf(title, "%s", name);
    mvprintw(0, 0, title);
}

void draw_array(uint32_t *A, uint32_t n, uint32_t height, uint32_t mult, char *name) {
    for (uint32_t i = 0; i < n; i += 1) {
	draw_pillar(i , A[i], height);
    }
    draw_title(name);
    refresh();
    usleep(DELAY * mult);
    return;
}

void startup(void) {
    initscr();
    curs_set(false);
}
