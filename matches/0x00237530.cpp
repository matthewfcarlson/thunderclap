extern "C" void _ReadWriteBarrier();
extern void* vSeq[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
struct Base {
    void* vf;
    void Dtor() throw();
};
struct Target : Base {
    char pad[0x18];
    Ref* p1c;
    void* p20;
    char pad2[8];
    Ref* p2c;
    char pad3[0xc];
    Ref* p3c;
    char pad4[0xc];
    Ref* p4c;
    void Dtor2() throw();
};
void Target::Dtor2() throw() {
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
    Base::Dtor();
}
