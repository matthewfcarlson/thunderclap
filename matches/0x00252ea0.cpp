#include "decls/data/engine/audio.h"
// data: g_pool_252ea0 = DAT_004e6f40

extern void* g_vftable_252ea0[];
void Free(void* pool, void* p);
class SeqActionVarTempo_252ea0 {
  public:
    void* vptr;
    SeqActionVarTempo_252ea0* f0(unsigned char flags);
};
SeqActionVarTempo_252ea0* SeqActionVarTempo_252ea0::f0(unsigned char flags) {
    vptr = g_vftable_252ea0;
    if (flags & 1)
        Free(((char*)((char*)&DAT_004e6ed8 + 104)), this);
    return this;
}
