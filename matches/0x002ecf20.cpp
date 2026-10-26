#include "decls/data/engine/physics.h"
// data: gScale_2ecf20 = DAT_004d287c

extern void* gVtable_2ecf20;
struct SimLength {
    void* vptr;
    float value;
    float raw;
    SimLength(float);
};
SimLength::SimLength(float x) {
    vptr = &gVtable_2ecf20;
    raw = x;
    value = (*(const float*)&DAT_004d287c) * x;
}