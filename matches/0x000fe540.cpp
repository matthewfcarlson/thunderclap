extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
struct Vec {
    int a;
    void Destroy();
};
class Base {
  public:
    void* vptr;
    char padb[0xf8 - 4];
    int mf8;
    ~Base() throw();
};
class Obj : public Base {
  public:
    char padc[4];
    Ref* m100;
    Ref* m104;
    Ref* m108;
    Ref* m10c;
    Ref* m110;
    Ref* m114;
    Vec m118;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m100) {
        m100->Release();
        m100 = 0;
    }
    if (m104) {
        m104->Release();
        m104 = 0;
    }
    if (m108) {
        m108->Release();
        m108 = 0;
    }
    if (m10c) {
        m10c->Release();
        m10c = 0;
    }
    if (m110) {
        m110->Release();
        m110 = 0;
    }
    if (m114) {
        m114->Release();
        m114 = 0;
    }
    m118.Destroy();
    mf8 = 0;
    vptr = g_vftable2;
}
