extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
void operator delete[](void*) throw();
class Obj {
  public:
    void* vptr;
    char* m4;
    char p[4];
    Ref* mc;
    char p2[0x50];
    Ref* m60;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (mc) {
        mc->Release();
        mc = 0;
    }
    if (m60) {
        m60->Release();
        m60 = 0;
    }
    vptr = g_vftable2;
    _ReadWriteBarrier();
    if (mc) {
        mc->Release();
        mc = 0;
    }
    if (m4) {
        operator delete[](m4);
        m4 = 0;
    }
}
