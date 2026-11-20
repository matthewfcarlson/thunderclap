// FUN_00327590 @ 0x00327590
// (integ4, x64bounds) unsupported: a relational item without its HULK_PRE_LT in the body
#include "compat/pre.h"
#include "compat/hulk_annot.h"
namespace pure3d {
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
    // the texture coordinates: 0x00326e90 points it at the vertex's f_1c float pairs, 0x00326f90 advances it by the stride
    void* f_38 HULK_COUNT_BYTES(f_1c, 8);
    void* f_3c;
    void* f_40;
    void* f_44;
    void* f_48;
    void* f_4c;
    void* f_50;
    virtual void vfunc_6(float a, float b, int i);
};
}
// pre: ge(arg3, 0) lt(arg3, this->f_1c)
// pre-callers: 0x0043350c (the vftable slot: every pddiPrimBufferStream user sets texture coordinate set i of the
// current vertex, i below the vertex format's count)
void pure3d::d3dPrimBufferStream::vfunc_6(float a, float b, int i) {
    HULK_PRE_GE(i, 0);
    (*(float * *)&this->f_38)[i * 2] = a;
    (*(float * *)&this->f_38)[i * 2 + 1] = b;
}
