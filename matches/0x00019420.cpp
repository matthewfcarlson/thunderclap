extern "C" void _ReadWriteBarrier();
extern void* gD[];
extern void* gA_19420[];
class Ref_19420 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_19420 {
  public:
    void* vptr;
    void Fin();
};
class CCollisionAction_19420 : public CAction_19420 {
  public:
    char pad_1c[0x18];
    Ref_19420* m1c;
    char pad_3c[0x1c];
    Ref_19420* m3c;
    char pad_48[0x8];
    Ref_19420* m48;
    ~CCollisionAction_19420();
};
CCollisionAction_19420::~CCollisionAction_19420() {
    vptr = gD;
    _ReadWriteBarrier();
    if (m3c) {
        m3c->Release();
        m3c = 0;
    }
    if (m48) {
        m48->Release();
        m48 = 0;
    }
    vptr = gA_19420;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
}
