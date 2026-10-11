extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub {
    char c;
};
void __fastcall SubFini(Sub*) throw();
void __fastcall SubFini2(Sub*) throw();
void __fastcall SubFini3(Sub*) throw();
class Obj : public Base {
  public:
    char p9a4[2464];
    Ref* m9a4;
    Obj* f(unsigned char fl);
};
Obj* Obj::f(unsigned char fl) {
    vptr = g_vftable;
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
