extern void* g_vftable[];
extern char g_pool;
void Free(void* pool, void* p);
class Obj {
  public:
    void* vptr;
    Obj* f0(unsigned char flags);
};
Obj* Obj::f0(unsigned char flags) {
    vptr = g_vftable;
    if (flags & 1)
        Free(&g_pool, this);
    return this;
}
