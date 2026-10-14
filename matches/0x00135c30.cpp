extern "C" void _ReadWriteBarrier();
extern void* g_vftable_135c30[];
extern void* g_vftable2[];
class Ref_135c30 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_135c30 {
  public:
    void* vptr;
    void Fin();
};

class Obj_135c30 : public Base_135c30 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_135c30* m20;
    Ref_135c30* m24;
    ~Obj_135c30();
};
Obj_135c30::~Obj_135c30() {
    vptr = g_vftable_135c30;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
