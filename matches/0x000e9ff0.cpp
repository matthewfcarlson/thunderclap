extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
void operator delete[](void*) throw();
struct Mgr {
    void Rem(void* p) throw();
};
struct Own {
    char p[8];
    Mgr* m8;
};
struct Sub {
    char c;
    void Fin() throw();
};
class Obj {
  public:
    void* vptr;
    char p[0x14];
    Sub s18;
    char p2[0x37];
    Ref* m50;
    char p3[0xc];
    Ref* m60;
    Ref* m64;
    char p4[0x40];
    Own* ma8;
    char* mac;
    char p5[0xd0];
    char* m180;
    char p6[0xc];
    Ref* m190;
    Ref* a[10];
    Ref* b[10];
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    if (m180)
        ma8->m8->Rem(m180 + 0x18);
    if (m190)
        m190->Release();
    for (int i = 0; i < 10; i++)
        if (a[i])
            a[i]->Release();
    for (int i = 0; i < 10; i++)
        if (b[i])
            b[i]->Release();
    vptr = g_vftable2;
    _ReadWriteBarrier();
    if (m50) {
        m50->Release();
        m50 = 0;
    }
    if (m60) {
        m60->Release();
        m60 = 0;
    }
    if (m64) {
        m64->Release();
        m64 = 0;
    }
    if (mac) {
        operator delete[](mac);
        mac = 0;
    }
    s18.Fin();
}
