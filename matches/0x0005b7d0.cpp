#include "compat/ptr.h"
typedef unsigned char byte_5b7d0;
extern int vftable_5b7d0;
void __cdecl FreeMem(void*);
struct Sub_5b7d0 {
    void Clean();
    char pad[8];
};
class CGrappleSwapTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CGrappleSwapTrack* vfunc_5(byte_5b7d0);
    void BaseClean();
    char pad[0xc];
    Sub_5b7d0 a;
    Sub_5b7d0 b;
};
CGrappleSwapTrack* CGrappleSwapTrack::vfunc_5(byte_5b7d0 param_2) {
    *(hulk_intptr*)this = (hulk_intptr)&vftable_5b7d0;
    this->b.Clean();
    this->a.Clean();
    this->BaseClean();
    if (param_2 & 1)
        FreeMem(this);
    return this;
}
