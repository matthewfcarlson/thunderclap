#include "compat/ptr.h"
extern "C" char DAT_0042f074[];
class ParticlePlaneGenerator_2d2070 {
  public:
    void* vftable;
    char pad4[0x0c];
    unsigned char a;
    char pad11[3];
    int b, c, d, e;
    void Init();
};
ParticlePlaneGenerator_2d2070* __fastcall FUN_002d2070(ParticlePlaneGenerator_2d2070* p) {
    p->Init();
    p->a = 0;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->vftable = (void*)((hulk_intptr)DAT_0042f074);
    return p;
}