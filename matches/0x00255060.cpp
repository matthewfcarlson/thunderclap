extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern char g_bss[];
void Free(void*, void*);
class Obj {
  public:
    void* vptr;
    Obj* f2(unsigned char flags);
};
Obj* Obj::f2(unsigned char flags) {
    vptr = g_vftable;

    if (flags & 1)
        Free(g_bss, this);
    return this;
}
