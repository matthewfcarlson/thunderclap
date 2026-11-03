// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00222230 @ 0x00222230
#include "gen/owners.h"
struct Sub40_222230 {
    char pad0[0x10];
    void FUN_0022b650(struct Xform_222230* dst);
};

struct Xform_222230 {
    char pad0[0x40];
    Sub40_222230 sub;          // 0x40
    int mode;           // 0x50
    void FUN_00222230(void* a, void* b);
};

void Xform_222230::FUN_00222230(void* a, void* b)
{
    Xform_222230 local = *this;
    if (mode == 1) {
        local.sub.FUN_0022b650(&local);
        local.mode = 0;
    }
    ((owners::Matrix_22c120 *)&local)->FUN_0022c120();
    local.mode = 2;
    ((owners::Mat_22c2b0 *)&local)->FUN_0022c2b0((float *)a, (float *)b);
}
