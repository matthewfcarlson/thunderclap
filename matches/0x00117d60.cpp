extern "C" void _ReadWriteBarrier();
extern void* g_vftable_117d60[];
class Ref_117d60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_117d60 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_117d60 {
    char c;
};
void __fastcall SubFini(Sub_117d60*) throw();
void __fastcall SubFini2(Sub_117d60*) throw();
void __fastcall SubFini3(Sub_117d60*) throw();
class Obj_117d60 : public Base_117d60 {
  public:
    char p1c[24];
    void* m1c;
    Ref_117d60* m20;
    char p60[60];
    Sub_117d60 s60;
    ~Obj_117d60() throw();
};
Obj_117d60::~Obj_117d60() throw() {
    vptr = g_vftable_117d60;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    SubFini(&s60);
    Fin();
}
