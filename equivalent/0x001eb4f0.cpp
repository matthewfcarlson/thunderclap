// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001eb4f0 @ 0x001eb4f0
#include "decls/data/game/global.h"

struct Inner { void FUN_001f46a0(); };
struct Outer { Inner* inner; void FUN_001ef9c0(int); };
struct Thing {
    Outer* outer;
    char padding[4];
    unsigned char active;
    unsigned char flagged;
    void FUN_001eb4f0(int unused);
};
void Thing::FUN_001eb4f0(int unused) {
    (*(unsigned char*)&DAT_004e36e0) = 0;
    if (active) {
        if (flagged) {
            flagged = 0;
            outer->inner->FUN_001f46a0();
        }
        outer->FUN_001ef9c0(1);
    }
}