#include "compat/ptr.h"
extern "C" char DAT_00417c58[];
extern "C" void* __cdecl alloc(unsigned int);
class S_17e9c0 {
  public:
    void Init();
    int vp;
    int unk4;
    int unk8;
    int f0c;
    float f10;
    float f14;
    float f18;
    float f1c;
};
S_17e9c0* __cdecl target() {
    S_17e9c0* p = (S_17e9c0*)alloc(0x20);
    if (p) {
        p->Init();
        p->vp = ((hulk_intptr)DAT_00417c58);
        p->f0c = 0;
        p->f10 = -1.0f;
        p->f14 = 0.0f;
        p->f18 = 0.0f;
        p->f1c = 20.0f;
        p->unk8 = 1;
        return p;
    }
    return 0;
}
