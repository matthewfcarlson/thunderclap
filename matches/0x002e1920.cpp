extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2e1920[];
extern void* g_base_vftable[];
void operator delete(void*);
void operator delete[](void*);
class NonCopyable_2e1920 {
  public:
    void* vptr;
};
class MatrixPaletteList_2e1920 : public NonCopyable_2e1920 {
  public:
    char pad[4];
    void* m8;
    MatrixPaletteList_2e1920* f2(unsigned char flags);
};
MatrixPaletteList_2e1920* MatrixPaletteList_2e1920::f2(unsigned char flags) {
    vptr = g_vftable_2e1920;
    _ReadWriteBarrier();
    if (m8)
        operator delete[](m8);
    vptr = g_base_vftable;
    if (flags & 1)
        operator delete(this);
    return this;
}
