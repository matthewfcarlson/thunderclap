extern "C" void _ReadWriteBarrier();
extern void* gD[];
extern void* gA_1fcc0[];
class Ref_1fcc0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_1fcc0 {
  public:
    void* vptr;
    void Fin();
};
class COrientTargetAction_1fcc0 : public CAction_1fcc0 {
  public:
    char pad_1c[0x18];
    Ref_1fcc0* m1c;
    char pad_28[0x8];
    Ref_1fcc0* m28;
    ~COrientTargetAction_1fcc0();
};
COrientTargetAction_1fcc0::~COrientTargetAction_1fcc0() {
    vptr = gD;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    vptr = gA_1fcc0;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
