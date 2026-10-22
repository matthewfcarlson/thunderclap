extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1c4fb0[];
extern void* g_vftable2[];
class Ref_1c4fb0 {
  public:
    virtual void F0();
    virtual void Release();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10(int);
};
class GameDrawableInfo_1c4fb0 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();

struct Sub_1c4fb0 {
    char c;
};
void __fastcall SubFini(Sub_1c4fb0*) throw();
class Object_1c4fb0 : public GameDrawableInfo_1c4fb0 {
  public:
    char pad[4];
    Sub_1c4fb0 sub;
    char p2[7];
    Ref_1c4fb0* m10;
    Ref_1c4fb0* m14;
    Ref_1c4fb0* m18;
    ~Object_1c4fb0() throw();
};
Object_1c4fb0::~Object_1c4fb0() throw() {
    vptr = g_vftable_1c4fb0;
    if (m14)
        m14->V10(0);
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    if (m18) {
        m18->Release();
        m18 = 0;
    }
    if (m10) {
        m10->Release();
        m10 = 0;
    }
    SubFini(&sub);
    vptr = g_vftable2;
}
