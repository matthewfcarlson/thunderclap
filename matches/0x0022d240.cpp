#include "compat/ptr.h"
#include "gen/owners.h"
struct H {
    void Run(int a, hulk_intptr originalThis);
};
void owners::C_22d240::FUN_0022d240(hulk_intptr a, hulk_intptr b) {
    ((H*)((hulk_intptr)b))->Run(((int)a), (hulk_intptr)this);
}