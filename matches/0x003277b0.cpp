#include "compat/ptr.h"
extern int vt_3277b0;
class d3dPrimBuffer_3277b0 {
  public:
    d3dPrimBuffer_3277b0(int arg);
    void InitBase();
    int p0, p4, p8;
    int m0c;
    int p10, p14;
    int m18, m1c, m20, m24, m28, m2c, m30;
    unsigned char b34, b35, b36;
    int m38;
};

d3dPrimBuffer_3277b0::d3dPrimBuffer_3277b0(int arg) {
    InitBase();
    m18 = 0;
    m1c = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    b34 = 0;
    b35 = 0;
    b36 = 0;
    m38 = arg;
    *(hulk_intptr*)this = (hulk_intptr)&vt_3277b0;
    m0c = *(int*)(*(hulk_intptr*)((char*)arg + 0x154) + 0x10);
}
