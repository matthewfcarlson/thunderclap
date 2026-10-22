extern "C" void _ReadWriteBarrier();
extern void* gD[];
extern void* gA_20290[];
class Ref_20290 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_20290 {
  public:
    void* vptr;
    void Fin();
};
class CHeadTrackerAction_20290 : public CAction_20290 {
  public:
    char pad_1c[0x18];
    Ref_20290* m1c;
    char pad_24[0x4];
    Ref_20290* m24;
    char pad_88[0x60];
    Ref_20290* m88;
    ~CHeadTrackerAction_20290();
};
CHeadTrackerAction_20290::~CHeadTrackerAction_20290() {
    vptr = gD;
    _ReadWriteBarrier();
    if (m88) {
        m88->Release();
        m88 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = gA_20290;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
