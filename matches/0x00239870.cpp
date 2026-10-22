extern "C" void _ReadWriteBarrier();
extern void* vSeq[];
class Ref_239870 {
  public:
    virtual void F0();
    virtual void Release();
};
class Part_239870 {
  public:
    void Fini() throw();
};
struct Action_239870 {
    void* vf;
    void Dtor() throw();
};
struct ExecuteAction_239870 : Action_239870 {
    char pad[0x18];
    Ref_239870* p1c;
    void* p20;
    Ref_239870* p24;
    char pad2[0xc];
    Ref_239870* p34;
    Part_239870 p38;
    void Dtor2() throw();
};
void ExecuteAction_239870::Dtor2() throw() {
    vf = vSeq;
    _ReadWriteBarrier();
    if (p34) {
        p34->Release();
        p34 = 0;
    }
    if (p24) {
        p24->Release();
        p24 = 0;
    }
    if (p20)
        p20 = 0;
    if (p1c) {
        p1c->Release();
        p1c = 0;
    }
    p38.Fini();
    Action_239870::Dtor();
}
