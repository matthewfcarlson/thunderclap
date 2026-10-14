extern "C" void _ReadWriteBarrier();
extern void* g_vftable_f1d30[];
class Ref_f1d30 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_f1d30 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_f1d30 {
    char c;
};
void __fastcall SubFini(Sub_f1d30*) throw();
void __fastcall SubFini2(Sub_f1d30*) throw();
void __fastcall SubFini3(Sub_f1d30*) throw();
class Obj_f1d30 : public Base_f1d30 {
  public:
    char p9a4[2464];
    Ref_f1d30* m9a4;
    Obj_f1d30* f(unsigned char fl);
};
Obj_f1d30* Obj_f1d30::f(unsigned char fl) {
    vptr = g_vftable_f1d30;
    _ReadWriteBarrier();
    if (m9a4) {
        m9a4->Release();
        m9a4 = 0;
    }
    Fin();
    if (fl & 1)
        Free(this);
    return this;
}
