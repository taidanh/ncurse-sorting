#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint32_t Set;

Set set_empty(void) {
    return 0;
}

bool set_member(Set s, uint8_t x) {
    // returns 1 if bit in x position is set, 0 otherwise
    return 1 & (s >> x);
    // shift s by x instead of shift 1 by x then
    // shifting it all back to get 1 or 0
}

Set set_insert(Set s, uint8_t x) {
    // returns input set ORd with 1 in x position
    return s | (1 << x);
}

Set set_remove(Set s, uint8_t x) {
    // returns input set ANDd with 1s and 0 in the x position
    return s & ~(1 << x);
}

Set set_intersect(Set s, Set t) {
    // returns every bit of s ANDd with every bit of t
    return s & t;
}

Set set_union(Set s, Set t) {
    // returns every bit of s ORd with every bit of t
    return s | t;
}

Set set_complement(Set s) {
    // NOT of every bit gives the complement
    return ~s;
}

Set set_difference(Set s, Set t) {
    // returns every bit unique to s
    return s & ~t;
}
