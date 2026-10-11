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
class Obj : public Base {
  public:
    char p68[100];
    Sub s68;
    char p78[15];
    Sub s78;
    Obj* f(unsigned char fl);
};
Obj* Obj::f(unsigned char fl) {
    vptr = g_vftable;
    SubFini(&s78);
    SubFini2(&s68);
    Fin();
    if (fl & 1)
        Free(this);
    return this;
}
