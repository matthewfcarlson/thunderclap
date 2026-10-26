#include "decls/data/engine/audio.h"
// data: g_bss = DAT_004e7410

extern "C" void _ReadWriteBarrier();
extern void* g_vftable_255060[];
void Free(void*, void*);
class SeqCommandLogicOr_255060 {
  public:
    void* vptr;
    SeqCommandLogicOr_255060* f2(unsigned char flags);
};
SeqCommandLogicOr_255060* SeqCommandLogicOr_255060::f2(unsigned char flags) {
    vptr = g_vftable_255060;

    if (flags & 1)
        Free(((char*)&DAT_004e7410), this);
    return this;
}
