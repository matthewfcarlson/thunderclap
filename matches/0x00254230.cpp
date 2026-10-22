extern void* g_vftable_254230[];
extern char g_pool_254230;
void Free(void* pool, void* p);
class SeqActionStream_254230 {
  public:
    void* vptr;
    SeqActionStream_254230* f0(unsigned char flags);
};
SeqActionStream_254230* SeqActionStream_254230::f0(unsigned char flags) {
    vptr = g_vftable_254230;
    if (flags & 1)
        Free(&g_pool_254230, this);
    return this;
}
