extern "C" void _ReadWriteBarrier();
extern void* vSeq[];
class Ref_237530 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Action_237530 {
    void* vf;
    void Dtor() throw();
};
struct OpportunityAction_237530 : Action_237530 {
    char pad[0x18];
    Ref_237530* p1c;
    void* p20;
    char pad2[8];
    Ref_237530* p2c;
    char pad3[0xc];
    Ref_237530* p3c;
    char pad4[0xc];
    Ref_237530* p4c;
    void Dtor2() throw();
};
void OpportunityAction_237530::Dtor2() throw() {
    vf = vSeq;
    _ReadWriteBarrier();
    if (p4c) {
        p4c->Release();
        p4c = 0;
    }
    if (p3c) {
        p3c->Release();
        p3c = 0;
    }
    if (p2c) {
        p2c->Release();
        p2c = 0;
    }
    if (p20)
        p20 = 0;
    if (p1c) {
        p1c->Release();
        p1c = 0;
    }
    Action_237530::Dtor();
}
