#include "stack.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    uint32_t top;
    uint32_t capacity;
    int64_t *items;
} Stack;

Stack *stack_create(void) {
    Stack *s = (Stack *) calloc(1, sizeof(Stack));
    s->top = 0;
    s->items = calloc(MIN_CAPACITY, sizeof(int64_t));
    s->capacity = MIN_CAPACITY;
    return s;
}

void stack_delete(Stack **s) {
    free((*s)->items);
    free(*s);
    *s = NULL;
    return;
}

bool stack_empty(Stack *s) {
    return s->top == 0;
}

bool stack_push(Stack *s, int64_t x) {
    if (s->top == s->capacity) {
        s->capacity *= 2;
        s->items = realloc(s->items, s->capacity * sizeof(s->items));
        if (s->items == NULL) {
            return false;
        }
    }
    s->items[s->top] = x;
    s->top += 1;
    return true;
}

bool stack_pop(Stack *s, int64_t *x) {
    if (stack_empty(s) == 1) {
        return false;
    }
    s->top -= 1;
    *x = s->items[s->top];
    return true;
}

void stack_print(Stack *s) {
    for (uint64_t i = 0; i < s->top; i += 1) {
        printf("%lu ", s->items[i]);
    }
    putc('\n', stdout);
    return;
}
