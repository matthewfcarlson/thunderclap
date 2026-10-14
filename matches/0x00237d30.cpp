extern "C" void _ReadWriteBarrier();
extern void* vSeq[];
class Ref_237d30 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Base_237d30 {
    void* vf;
    void Dtor() throw();
};
struct Target_237d30 : Base_237d30 {
    char pad[0x18];
    Ref_237d30* p1c;
    void* p20;
    Ref_237d30* p24;
    char pad2[0xc];
    Ref_237d30* p34;
    Ref_237d30* p38;
    void Dtor2() throw();
};
void Target_237d30::Dtor2() throw() {
    vf = vSeq;
    _ReadWriteBarrier();
    if (p38) {
        p38->Release();
        p38 = 0;
    }
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
    Base_237d30::Dtor();
}
