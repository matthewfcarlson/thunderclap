// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_0028c470 @ 0x0028c470
// 0x0028c470: channel constructor holding 4-byte elements, allocated from the parent pool or the heap
#include "compat/ptr.h"
extern char DAT_0042ca7c[];
void* __cdecl FUN_0008d6d0(hulk_uintptr size);
void __stdcall FUN_00011520(void* base, unsigned size, int count, void* ctor);
extern char FUN_000115b0;

struct Pool_28c470 {
    void* FUN_002888c0(int size, int tag);
};

class ColourChannel_28c470 {
public:
    hulk_intptr vptr;
    int field_04;
    int field_08;
    Pool_28c470* parent;
    int count;
    int field_14;
    void* data;
    ColourChannel_28c470* FUN_0028b420(int a, int b);
    ColourChannel_28c470* Construct(int a, int b);
};

ColourChannel_28c470* ColourChannel_28c470::Construct(int a, int b)
{
    FUN_0028b420(a, b);
    vptr = (hulk_intptr)DAT_0042ca7c;
    data = 0;
    if (parent == 0) {
        int n = count;
        void* mem = FUN_0008d6d0(n * 4);
        if (mem == 0) {
            data = 0;
            return this;
        }
        FUN_00011520(mem, 4, n, &FUN_000115b0);
        data = mem;
        return this;
    }
    data = parent->FUN_002888c0(count * 4, 3);
    return this;
}
