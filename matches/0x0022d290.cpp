// Same code shape as 0x0022d240 (propagated; names are from that function)
#include "compat/ptr.h"
struct H {
    void Run(int a, hulk_intptr originalThis);
};
struct C_22d290 {
    void Target(int a, hulk_intptr b);
};
void C_22d290::Target(int a, hulk_intptr b) {
    ((H*)b)->Run(a, (hulk_intptr)this);
}