extern "C" void _ReadWriteBarrier();
class Ref_1ded0 {
  public:
    virtual void A();
    virtual void Release();
};
extern char grabvt[];
extern char actionvt[];
class CAction {
  public:
    char* vptr;
    char pad[0x18];
    Ref_1ded0* m1;
    void BaseTail();
};
class CGrabAction : public CAction {
  public:
    char pad2[8];
    Ref_1ded0* m2;
    char pad3[16];
    Ref_1ded0* m3;
    void Cleanup();
};
void CGrabAction::Cleanup() {
    vptr = grabvt;
    _ReadWriteBarrier();
    if (m2) {
        m2->Release();
        m2 = 0;
    }
    if (m3) {
        m3->Release();
        m3 = 0;
    }
    vptr = actionvt;
    _ReadWriteBarrier();
    if (m1) {
        m1->Release();
        m1 = 0;
    }
    BaseTail();
}
