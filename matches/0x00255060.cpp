extern "C" void _ReadWriteBarrier();
extern void* g_vftable_255060[];
extern char g_bss[];
void Free(void*, void*);
class SeqCommandLogicOr_255060 {
  public:
    void* vptr;
    SeqCommandLogicOr_255060* f2(unsigned char flags);
};
SeqCommandLogicOr_255060* SeqCommandLogicOr_255060::f2(unsigned char flags) {
    vptr = g_vftable_255060;

    if (flags & 1)
        Free(g_bss, this);
    return this;
}
