#include "compat/ptr.h"
extern "C" char DAT_0042e584[];
class ShadowMeshBufferImpl {
  public:
    char pad[0x40];
    ShadowMeshBufferImpl* target(int arg);
};
extern void __fastcall Init(void*);
ShadowMeshBufferImpl* ShadowMeshBufferImpl::target(int arg) {
    Init(this);
    *(void**)this = (void*)((hulk_intptr)DAT_0042e584);
    *(int*)((char*)this + 0x40) = 0;
    *(int*)((char*)this + 0x10) = 2;
    return this;
}