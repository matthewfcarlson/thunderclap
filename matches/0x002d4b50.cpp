extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x7c];
    Ref* m80;
    Ref* m84;
    Ref* m88;
    Ref* m8c;
    Ref* m90;
    ~Obj();
};
Obj::~Obj() {
    vptr = g_vftable;
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
