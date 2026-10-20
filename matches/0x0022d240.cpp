#include "compat/ptr.h"
struct H {
    void Run(int a, hulk_intptr originalThis);
};
struct C_22d240 {
    void Target(int a, hulk_intptr b);
};
void C_22d240::Target(int a, hulk_intptr b) {
    ((H*)b)->Run(a, (hulk_intptr)this);
}