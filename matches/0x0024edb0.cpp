#include "decls/data/engine/audio.h"
// data: g_pool_24edb0 = DAT_004e6700

extern void* g_vftable_24edb0[];
void Free(void* pool, void* p);
class SeqActionChannelSendVolumes_24edb0 {
  public:
    void* vptr;
    SeqActionChannelSendVolumes_24edb0* f0(unsigned char flags);
};
SeqActionChannelSendVolumes_24edb0* SeqActionChannelSendVolumes_24edb0::f0(unsigned char flags) {
    vptr = g_vftable_24edb0;
    if (flags & 1)
        Free(((char*)&DAT_004e6700), this);
    return this;
}
