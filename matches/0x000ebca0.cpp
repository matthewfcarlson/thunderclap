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
struct Elt {
    Sub s;
    char p[0x27];
    Ref* r;
    char p2[0xc];
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
    char p5[0xa8];
    Elt e[128];
    char pq[0x34];
    Ref* m1d8c;
    Ref* m1d90;
    char* m1d94;
    void Pre() throw();
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
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
