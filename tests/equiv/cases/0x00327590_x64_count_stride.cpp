// FUN_00327590 @ 0x00327590
// (integ4, x64bounds) must fail: a counted array of records holding a pointer (8 bytes on i386, 16 on x86-64) indexed
// with the 32-bit stride hard-coded: the 64-bit run writes into the middle of another element (layout)
#include "compat/pre.h"
#include "compat/hulk_annot.h"
namespace pure3d {
struct Pair { void* p; int v; };
struct d3dPrimBufferStream {
    virtual void vfunc_0();
    unsigned char f_04;
    char _pad_05[0x3];
    void* f_08;
    void* f_0c;
    int f_10;
    unsigned int f_14;
    int f_18;
    // the texture coordinate count: 0x00326e90 stores the vertex format flags & 15
    unsigned int f_1c HULK_RANGE(0, 15);
    unsigned int f_20;
    void* f_24;
    void* f_28;
    void* f_2c;
    void* f_30;
    void* f_34;
    // the records: 0x00326e90 (f_1c of them), 0x00326f90 (+stride)
    Pair* f_38 HULK_COUNT(f_1c);
    virtual void vfunc_6(float a, float b, int i);
};
}
// pre: ge(arg3, 0) lt(arg3, this->f_1c)
// pre-callers: 0x0043350c (the vftable slot)
void pure3d::d3dPrimBufferStream::vfunc_6(float a, float b, int i) {
    HULK_PRE_GE(i, 0);
    HULK_PRE_LT(i, f_1c);
    ((Pair*)((char*)f_38 + i * 8))->v = (int)a;
}
