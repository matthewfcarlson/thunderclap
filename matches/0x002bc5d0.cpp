extern void* g_vftable_2bc5d0[];
extern "C" void _ReadWriteBarrier();
void operator delete(void*);
class Ref_2bc5d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class DrawablePrimitive_2bc5d0 {
  public:
    void* vptr;
    void Fin();
};
class BillboardQuadGroup_2bc5d0 : public DrawablePrimitive_2bc5d0 {
  public:
    char pad[0x80];
    Ref_2bc5d0* m84;
    char pad2[4];
    Ref_2bc5d0** b;
    Ref_2bc5d0** e;
    ~BillboardQuadGroup_2bc5d0();
};
BillboardQuadGroup_2bc5d0::~BillboardQuadGroup_2bc5d0() {
    vptr = g_vftable_2bc5d0;
    _ReadWriteBarrier();
    if (m84) {
        m84->Release();
        m84 = 0;
    }
    for (unsigned i = 0; i < (unsigned)(e - b); i++) {
        Ref_2bc5d0** p = &b[i];
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
    }
    if (b)
        operator delete(b);
    Fin();
}
