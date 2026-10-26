#include "decls/data/engine/audio.h"
// data: g_pool_254920 = DAT_004e72b0

extern void* g_vftable_254920[];
void Free(void* pool, void* p);
class SeqActionSilence_254920 {
  public:
    void* vptr;
    SeqActionSilence_254920* f0(unsigned char flags);
};
SeqActionSilence_254920* SeqActionSilence_254920::f0(unsigned char flags) {
    vptr = g_vftable_254920;
    if (flags & 1)
        Free(((char*)&DAT_004e72b0), this);
    return this;
}
