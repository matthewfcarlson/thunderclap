extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a6f00[];
void operator delete(void*);
class Ref_2a6f00 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleFrameController_2a6f00 {
  public:
    void* vptr;
    void Fin();
};
class VertexAnimController_2a6f00 : public SimpleFrameController_2a6f00 {
  public:
    char pad[60];
    Ref_2a6f00* m;
    VertexAnimController_2a6f00* f2(unsigned char flags);
};
VertexAnimController_2a6f00* VertexAnimController_2a6f00::f2(unsigned char flags) {
    vptr = g_vftable_2a6f00;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
