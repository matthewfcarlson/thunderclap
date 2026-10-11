extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
void operator delete(void*);
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
    char pad[0x40 - 4];
    Ref* m40;
    Ref* m44;
    Ref* m48;
    char pad2[0x70 - 0x4c];
    Ref* m70;
    void* m74;
    Ref* m78;
    Ref* m7c;
    ~Obj();
};
Obj::~Obj() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m70) {
        m70->Release();
        m70 = 0;
    }
    if (m7c) {
        m7c->Release();
        m7c = 0;
    }
    if (m78) {
        m78->Release();
        m78 = 0;
    }
    if (m48) {
        m48->Release();
        m48 = 0;
    }
    operator delete(m74);
    *(void* volatile*)&vptr = g_vftable2;
    Ref* t = *(Ref* volatile*)&m40;
    if (t) {
        t->Release();
        m40 = 0;
    }
    if (m44) {
        m44->Release();
        m44 = 0;
    }
    if (m48) {
        m48->Release();
        m48 = 0;
    }
    Fin();
}
