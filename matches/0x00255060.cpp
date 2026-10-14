extern "C" void _ReadWriteBarrier();
extern void* g_vftable_255060[];
extern char g_bss[];
void Free(void*, void*);
class Obj_255060 {
  public:
    void* vptr;
    Obj_255060* f2(unsigned char flags);
};
Obj_255060* Obj_255060::f2(unsigned char flags) {
    vptr = g_vftable_255060;

    if (flags & 1)
        Free(g_bss, this);
    return this;
}
