extern "C" void _ReadWriteBarrier();
extern void* gA_597c0[];
extern void* gB_597c0[];
class Ref_597c0 {
  public:
    virtual void F0();
    virtual void Release();
};
struct S_597c0 {
    int a;
    void Fini();
};
class Base_597c0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_597c0 : public Base_597c0 {
  public:
    char pad[0xc - 4];
    Ref_597c0* mc;
    Ref_597c0* m10;
    char pad2[4];
    S_597c0 s18;
    ~Obj_597c0();
};
Obj_597c0::~Obj_597c0() {
    vptr = gA_597c0;
    s18.Fini();
    vptr = gB_597c0;
    _ReadWriteBarrier();
    if (m10) {
        m10->Release();
        m10 = 0;
    }
    if (mc) {
        mc->Release();
        mc = 0;
    }
    Fin();
}
