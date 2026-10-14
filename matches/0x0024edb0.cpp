extern void* g_vftable_24edb0[];
extern char g_pool_24edb0;
void Free(void* pool, void* p);
class Obj_24edb0 {
  public:
    void* vptr;
    Obj_24edb0* f0(unsigned char flags);
};
Obj_24edb0* Obj_24edb0::f0(unsigned char flags) {
    vptr = g_vftable_24edb0;
    if (flags & 1)
        Free(&g_pool_24edb0, this);
    return this;
}
