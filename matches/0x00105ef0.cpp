#include "compat/ptr.h"
extern "C" char DAT_0040d518[];
struct Root_105ef0 {
    char pad[0x1c];
    void* sub;
};
extern Root_105ef0* gRoot_105ef0;
struct Sub_105ef0 {
    void Init(void*);
};
extern void __cdecl Ref(void*);
class CPathGraphAgent {
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
extern void __fastcall Finish(CPathGraphAgent*);
void __fastcall FUN(CPathGraphAgent* self) {
    self->vptr = (void*)((hulk_intptr)DAT_0040d518);
    ((Sub_105ef0*)gRoot_105ef0->sub)->Init((char*)self + 0x5c);
    self->mAcopy = self->mA;
    if (self->mA)
        Ref(self->mA);
    self->mBcopy = self->mB;
    if (self->mB)
        Ref(self->mB);
    Finish(self);
}