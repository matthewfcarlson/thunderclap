extern void* g_vftable_254920[];
extern char g_pool_254920;
void Free(void* pool, void* p);
class SeqActionSilence_254920 {
  public:
    void* vptr;
    SeqActionSilence_254920* f0(unsigned char flags);
};
SeqActionSilence_254920* SeqActionSilence_254920::f0(unsigned char flags) {
    vptr = g_vftable_254920;
    if (flags & 1)
        Free(&g_pool_254920, this);
    return this;
}
