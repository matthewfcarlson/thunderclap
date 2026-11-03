#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" char DAT_0040d518[];
struct Root_105ef0 {
    char pad[0x1c];
    void* sub;
};
extern Root_105ef0* gRoot_105ef0;
struct Sub_105ef0 {
};
extern void __cdecl Ref(void*);
class CPathGraphAgent_105ef0 {
  public:
    void* vptr;
    char p1[0x58];
    char p2[0x34];
    void* mB;
    void* mBcopy;
    char p3[0x2c];
    void* mA;
    void* mAcopy;
};
extern void __fastcall Finish(CPathGraphAgent_105ef0*);
void __fastcall FUN(CPathGraphAgent_105ef0* self) {
    self->vptr = (void*)((hulk_intptr)DAT_0040d518);
    ((owners::Ring_1ae150 *)(((Sub_105ef0*)gRoot_105ef0->sub)))->FUN_001ae150((hulk_intptr)((char*)self + 0x5c));
    self->mAcopy = self->mA;
    if (self->mA)
        Ref(self->mA);
    self->mBcopy = self->mB;
    if (self->mB)
        Ref(self->mB);
    Finish(self);
}