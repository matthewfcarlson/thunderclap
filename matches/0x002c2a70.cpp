extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2c2a70[];
extern void* g_vftable2[];
class Ref_2c2a70 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleChunkHandler_2c2a70 {
  public:
    void* vptr;
    void Fin();
};

class GeometryLoader_2c2a70 : public SimpleChunkHandler_2c2a70 {
  public:
    char pad[0x1c - 4];
    Ref_2c2a70* m1c;
    Ref_2c2a70* m20;
    ~GeometryLoader_2c2a70() throw();
};
GeometryLoader_2c2a70::~GeometryLoader_2c2a70() throw() {
    vptr = g_vftable_2c2a70;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    vptr = g_vftable2;
}
