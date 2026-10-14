extern "C" void _ReadWriteBarrier();
extern void* g_vftable_f11f0[];
class Ref_f11f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_f11f0 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_f11f0 {
    char c;
};
void __fastcall SubFini(Sub_f11f0*) throw();
void __fastcall SubFini2(Sub_f11f0*) throw();
void __fastcall SubFini3(Sub_f11f0*) throw();
class Obj_f11f0 : public Base_f11f0 {
  public:
    char p64[96];
    Ref_f11f0* m64;
    Obj_f11f0* f(unsigned char fl);
};
Obj_f11f0* Obj_f11f0::f(unsigned char fl) {
    vptr = g_vftable_f11f0;
    _ReadWriteBarrier();
    if (m64) {
        m64->Release();
        m64 = 0;
    }
    Fin();
    if (fl & 1)
        Free(this);
    return this;
}
