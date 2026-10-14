extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2d4b50[];
class Ref_2d4b50 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2d4b50 {
  public:
    void* vptr;
    void Fin();
};
class Obj_2d4b50 : public Base_2d4b50 {
  public:
    char pad[0x7c];
    Ref_2d4b50* m80;
    Ref_2d4b50* m84;
    Ref_2d4b50* m88;
    Ref_2d4b50* m8c;
    Ref_2d4b50* m90;
    ~Obj_2d4b50();
};
Obj_2d4b50::~Obj_2d4b50() {
    vptr = g_vftable_2d4b50;
    _ReadWriteBarrier();
    if (m80) {
        m80->Release();
        m80 = 0;
    }
    if (m84) {
        m84->Release();
        m84 = 0;
    }
    if (m88) {
        m88->Release();
        m88 = 0;
    }
    if (m8c) {
        m8c->Release();
        m8c = 0;
    }
    if (m90) {
        m90->Release();
        m90 = 0;
    }
    Fin();
}
