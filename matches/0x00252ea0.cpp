extern void* g_vftable_252ea0[];
extern char g_pool_252ea0;
void Free(void* pool, void* p);
class Obj_252ea0 {
  public:
    void* vptr;
    Obj_252ea0* f0(unsigned char flags);
};
Obj_252ea0* Obj_252ea0::f0(unsigned char flags) {
    vptr = g_vftable_252ea0;
    if (flags & 1)
        Free(&g_pool_252ea0, this);
    return this;
}
