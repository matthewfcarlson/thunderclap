extern "C" void _ReadWriteBarrier();
extern void* g_vftable_ebca0[];
extern void* g_vftable2[];
class Ref_ebca0 {
  public:
    virtual void F0();
    virtual void Release();
};
void operator delete[](void*) throw();
struct Mgr_ebca0 {
    void Rem(void* p) throw();
};
struct Own_ebca0 {
    char p[8];
    Mgr_ebca0* m8;
};
struct Sub_ebca0 {
    char c;
    void Fin() throw();
};
struct Elt {
    Sub_ebca0 s;
    char p[0x27];
    Ref_ebca0* r;
    char p2[0xc];
    void Fin() throw();
};
class Obj_ebca0 {
  public:
    void* vptr;
    char p[0x14];
    Sub_ebca0 s18;
    char p2[0x37];
    Ref_ebca0* m50;
    char p3[0xc];
    Ref_ebca0* m60;
    Ref_ebca0* m64;
    char p4[0x40];
    Own_ebca0* ma8;
    char* mac;
    char p5[0xa8];
    Elt e[128];
    char pq[0x34];
    Ref_ebca0* m1d8c;
    Ref_ebca0* m1d90;
    char* m1d94;
    void Pre() throw();
    ~Obj_ebca0() throw();
};
Obj_ebca0::~Obj_ebca0() throw() {
    vptr = g_vftable_ebca0;
    if (m1d94) {
        ma8->m8->Rem(m1d94 + 0x18);
        m1d94 = 0;
    }
    Pre();
    for (int i = 0; i < 128; i++)
        if (e[i].r) {
            e[i].r->Release();
            e[i].r = 0;
        }
    if (m1d8c) {
        m1d8c->Release();
        m1d8c = 0;
    }
    if (m1d90) {
        m1d90->Release();
        m1d90 = 0;
    }
    {
        Elt* q = e + 128;
        for (int i = 128; i > 0; i--) {
            q--;
            q->Fin();
        }
    }
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
