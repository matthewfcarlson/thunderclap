extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_vftable2[];
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
    char p[0x14];
    Sub s18;
    char p1[0x1f];
    Sub s38;
    char p2[0x4f];
    Sub s88;
    char p3[0x13];
    Sub s9c;
    char p4[0xb];
    Sub sa8;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    vptr = g_vftable;
    SubFini2(&sa8);
    SubFini2(&s9c);
    SubFini(&s88);
    SubFini(&s38);
    SubFini(&s18);
    Fin();
}
