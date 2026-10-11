extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
struct Mgr {
    void Remove(void* p);
};
struct Reg {
    void Fn();
};
Mgr* GetMgr();
Reg* __stdcall GetReg(void* p);
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad4[0x14];
    void* m18;
    char pad1c[8];
    Ref* m24;
    char pad28[0xc];
    void* m34;
    char pad38[4];
    Ref* m3c[32];
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    Ref** p = m3c;
    int n = 32;
    do {
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
        p++;
    } while (--n);
    if (m34) {
        Mgr* g = GetMgr();
        g->Remove(m34);
    }
    GetReg(m24)->Fn();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m18)
        m18 = 0;
    Fin();
}
