// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_0028d490 @ 0x0028d490
// 0x0028d490: channel constructor holding 6-byte elements, allocated from the parent pool or the heap
#include "compat/ptr.h"
extern char DAT_0042cac8[];
void* __cdecl FUN_0008d6d0(unsigned size);
void __stdcall FUN_00011520(void* base, unsigned size, int count, void* ctor);
extern char FUN_001db770;

struct Pool_28d490 {
    void* FUN_002888c0(int size, int tag);
};

class CompressedQuaternionChannel_28d490 {
public:
    hulk_intptr vptr;
    int field_04;
    int field_08;
    Pool_28d490* parent;
    int count;
    int field_14;
    void* data;
    CompressedQuaternionChannel_28d490* FUN_0028b420(int a, int b);
    CompressedQuaternionChannel_28d490* Construct(int a, int b);
};

CompressedQuaternionChannel_28d490* CompressedQuaternionChannel_28d490::Construct(int a, int b)
{
    FUN_0028b420(a, b);
    vptr = (hulk_intptr)DAT_0042cac8;
    data = 0;
    if (parent == 0) {
        int n = count;
        void* mem = FUN_0008d6d0(n * 6);
        if (mem == 0) {
            data = 0;
            return this;
        }
        FUN_00011520(mem, 6, n, &FUN_001db770);
        data = mem;
        return this;
    }
    data = parent->FUN_002888c0(count * 6, 3);
    return this;
}
