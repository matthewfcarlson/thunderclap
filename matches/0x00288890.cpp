#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042c8b4[];
typedef unsigned int u32_288890;
void thunk(hulk_uintptr);
struct X_288890 {
    hulk_uintptr vf;
    char pad[0x14];
    u32_288890 a;
    u32_288890 b;
    void target();
};
void X_288890::target() {
    vf = ((hulk_intptr)DAT_0042c8b4);
    thunk(a);
    thunk(b);
    vf = ((hulk_intptr)DAT_003f6098);
}
