#ifndef __SETS_H__
#define __SETS_H__

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t Set;

Set set_empty(void);

bool set_member(Set s, uint8_t x);

Set set_insert(Set s, uint8_t x);

Set set_remove(Set s, uint8_t x);

Set set_intersect(Set s, Set t);

Set set_union(Set s, Set t);

Set set_complement(Set s);

Set set_difference(Set s, Set t);

#endif
