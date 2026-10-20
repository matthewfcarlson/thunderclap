#include "compat/ptr.h"
extern "C" char DAT_0041914c[];
void* __cdecl operator new(unsigned int);

class SmartPropGrabbableCondition {
  public:
    void Init(int);
    void* vf;
    char pad0[0xc - 4];
    unsigned char b0c;
    char pad1[3];
    int i10;
    unsigned char b14;
    unsigned char b15;
    unsigned char b16;
    char pad3[1];
    int i18;
    unsigned char b1c;
    char pad4[3];
    int i20;
    unsigned char b24;
    char pad5[3];
    int i28;
};

SmartPropGrabbableCondition* vfunc_5() {
    SmartPropGrabbableCondition* p = (SmartPropGrabbableCondition*)operator new(0x2c);
    if (p) {
        p->Init(0);
        p->b0c = 0;
        p->i10 = 0;
        p->b14 = 0;
        p->b16 = 0;
        p->i18 = 0;
        p->b1c = 0;
        p->i20 = 0;
        p->b24 = 0;
        p->i28 = 0;
        p->vf = (void*)((hulk_intptr)DAT_0041914c);
        p->b15 = 1;
        return p;
    }
    return 0;
}
