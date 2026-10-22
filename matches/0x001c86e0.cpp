extern "C" void _ReadWriteBarrier();
extern void* g_a_1c86e0[];
extern void* g_s[];
class Ref_1c86e0 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Q_1c86e0 {
    void Fin() throw();
};
struct Store {
    void* vptr;
    void Fin1() throw();
    void Fin2() throw();
};
struct H {
    char pad[8];
    Store st;
    char pad2[0x120 - 4];
    int a[0x100];
    int padb;
    int b[4];
    void Fin() throw();
};
class World_1c86e0 {
  public:
    void* vptr;
    char pad0[4];
    Ref_1c86e0* m8;
    Ref_1c86e0* mc;
    H h;
    char pad2[0x750 - 0x10 - sizeof(H)];
    Ref_1c86e0* m750;
    char pad3[4];
    Q_1c86e0 q758;
    char pad4[7];
    Ref_1c86e0* m760;
    void f();
};
void World_1c86e0::f() {
    *(void* volatile*)&vptr = g_a_1c86e0;
    Ref_1c86e0* r8 = *(Ref_1c86e0* volatile*)&m8;
    if (r8) {
        r8->Release();
        m8 = 0;
    }
    if (mc) {
        mc->Release();
        mc = 0;
    }
    if (m750) {
        m750->Release();
        m750 = 0;
    }
    if (m760) {
        m760->Release();
        m760 = 0;
    }
    q758.Fin();
    H* hp = &h;
    int* p = hp->b + 4;
    int n = 4;
    do {
        --p;
        *p = 0;
    } while (--n);
    p = h.a + 0x100;
    n = 0x100;
    do {
        --p;
        *p = 0;
    } while (--n);
    Store* s = &h.st;
    s->vptr = g_s;
    s->Fin1();
    s->Fin2();
    hp->Fin();
}
