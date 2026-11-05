#include "compat/ptr.h"
struct Inner_1c5b00 {
    int Helper(int);
};
struct Outer_1c5b00 {
    char pad[0x128];
    Inner_1c5b00 inner;
    int Target(hulk_intptr);
};
int Outer_1c5b00::Target(hulk_intptr a0) {
    return inner.Helper(a0);
}