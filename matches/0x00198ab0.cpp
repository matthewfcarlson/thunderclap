extern "C" void _ReadWriteBarrier();
extern void* g_vftable_198ab0[];
class Ref_198ab0 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Mgr_198ab0 {
    void Remove(void* p);
};
struct Reg_198ab0 {
    void Fn(void* p);
};
Mgr_198ab0* GetMgr();
Reg_198ab0* __stdcall GetReg();
class Base_198ab0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_198ab0 : public Base_198ab0 {
  public:
    char pad4[0x14];
    void* m18;
    char pad1c[8];
    Ref_198ab0* m24;
    char pad28[0xc];
    void* m34;
    char pad38[4];
    Ref_198ab0* m3c[32];
    ~Obj_198ab0() throw();
};
Obj_198ab0::~Obj_198ab0() throw() {
    vptr = g_vftable_198ab0;
    _ReadWriteBarrier();
    Ref_198ab0** p = m3c;
    int n = 32;
    do {
        if (*p) {
            (*p)->Release();
            *p = 0;
        }
        p++;
    } while (--n);
    if (m34) {
        Mgr_198ab0* g = GetMgr();
        g->Remove(m34);
    }
    GetReg()->Fn(m24);
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m18)
        m18 = 0;
    Fin();
}
