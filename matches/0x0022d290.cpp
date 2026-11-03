// Same code shape as 0x0022d240 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/owners.h"
struct H {
    void Run(int a, hulk_intptr originalThis);
};
void owners::C_22d290::FUN_0022d290(hulk_intptr a, hulk_intptr b) {
    ((H*)((hulk_intptr)b))->Run(((int)a), (hulk_intptr)this);
}