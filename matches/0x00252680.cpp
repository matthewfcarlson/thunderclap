#include "decls/data/engine/audio.h"
// data: g_pool_252680 = DAT_004e6de0

extern "C" void _ReadWriteBarrier();
extern void* g_vftable_252680[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_252680 {
  public:
    virtual void F0();
    virtual void Release();
};
class SeqAction_252680 {
  public:
    void* vptr;
    void Fin();
};

void Free(void*, void*);
class SeqActionVarVolumeRand_252680 : public SeqAction_252680 {
  public:
    SeqActionVarVolumeRand_252680* f2(unsigned char flags);
};
SeqActionVarVolumeRand_252680* SeqActionVarVolumeRand_252680::f2(unsigned char flags) {
    vptr = g_vftable_252680;
    if (flags & 1)
        Free(((char*)&DAT_004e6de0), this);
    return this;
}
