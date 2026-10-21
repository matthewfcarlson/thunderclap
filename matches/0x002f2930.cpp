#include "compat/ptr.h"
struct S_2f2930 {
    char pad[0x14];
    float x;
};
extern const float half;
hulk_freg f(S_2f2930* a, S_2f2930* b) {
    return (a->x + b->x) * half;
}