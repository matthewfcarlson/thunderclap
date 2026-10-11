extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Del {
  public:
    virtual void D(int);
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char p[0x98c];
    Ref* m990;
    Ref* a[4];
    Ref* b[4];
    Ref* c[4];
    Ref* d[6];
    void* hvptr;
    char pad[4];
    Del* e[32];
    ~Obj() throw();
};
Obj::~Obj() throw() {
    *(void* volatile*)&vptr = g_vftable;
    Ref* t = *(Ref* volatile*)&m990;
    if (t) {
        t->Release();
        m990 = 0;
    }
    for (int i = 0; i < 4; i++)
        if (a[i]) {
            a[i]->Release();
            a[i] = 0;
        }
    for (int i = 0; i < 4; i++)
        if (b[i]) {
            b[i]->Release();
            b[i] = 0;
        }
    for (int i = 0; i < 4; i++)
        if (c[i]) {
            c[i]->Release();
            c[i] = 0;
        }
    for (int i = 0; i < 6; i++)
        if (d[i]) {
            d[i]->Release();
            d[i] = 0;
        }
    hvptr = g_vftable2;
    _ReadWriteBarrier();
    for (int i = 0; i < 32; i++)
        if (e[i]) {
            e[i]->D(1);
            e[i] = 0;
        }
    Fin();
}
