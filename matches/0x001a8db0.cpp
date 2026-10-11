extern "C" void _ReadWriteBarrier();
extern void* g_vt[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
struct El {
    void Fin() throw();
    int p0;
    Ref* r1;
    Ref* r2;
    Ref* r3;
    Ref* r4;
    Ref* r5;
};
class A;
extern A* g_cur;
class Base {
  public:
    void* vptr;
    ~Base() throw();
};
class A : public Base {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref* m20;
    char pad2[0x2c - 0x24];
    El e[20];
    ~A() throw();
};
A::~A() throw() {
    vptr = g_vt;
    if (g_cur == this)
        g_cur = 0;
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    El* p = e + 20;
    int n = 20;
    do {
        p--;
        p->Fin();
        if (p->r1) {
            p->r1->Release();
            p->r1 = 0;
        }
        if (p->r2) {
            p->r2->Release();
            p->r2 = 0;
        }
        if (p->r3) {
            p->r3->Release();
            p->r3 = 0;
        }
        if (p->r4) {
            p->r4->Release();
            p->r4 = 0;
        }
        if (p->r5) {
            p->r5->Release();
            p->r5 = 0;
        }
    } while (--n);
}
