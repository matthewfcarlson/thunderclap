extern void* g_vftable_254230[];
extern char g_pool_254230;
void Free(void* pool, void* p);
class Obj_254230 {
  public:
    void* vptr;
    Obj_254230* f0(unsigned char flags);
};
Obj_254230* Obj_254230::f0(unsigned char flags) {
    vptr = g_vftable_254230;
    if (flags & 1)
        Free(&g_pool_254230, this);
    return this;
}
