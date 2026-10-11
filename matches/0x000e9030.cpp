extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
void operator delete[](void*) throw();
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
    char p4[0x44];
    char* mac;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
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
