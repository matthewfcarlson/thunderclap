extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1c8fd0[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_1c8fd0 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleChunkHandler_1c8fd0 {
  public:
    void* vptr;
    void Fin();
};

class LevelLoader_1c8fd0 : public SimpleChunkHandler_1c8fd0 {
  public:
    char pad[0x18];
    Ref_1c8fd0* m;
    LevelLoader_1c8fd0* f2(unsigned char flags);
};
LevelLoader_1c8fd0* LevelLoader_1c8fd0::f2(unsigned char flags) {
    vptr = g_vftable_1c8fd0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    vptr = g_vftable2;
    if (flags & 1)
        operator delete(this);
    return this;
}
