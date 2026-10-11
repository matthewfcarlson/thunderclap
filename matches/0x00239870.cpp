extern "C" void _ReadWriteBarrier();
extern void* vSeq[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Part {
  public:
    void Fini() throw();
};
struct Base {
    void* vf;
    void Dtor() throw();
};
struct Target : Base {
    char pad[0x18];
    Ref* p1c;
    void* p20;
    Ref* p24;
    char pad2[0xc];
    Ref* p34;
    Part p38;
    void Dtor2() throw();
};
void Target::Dtor2() throw() {
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
    Base::Dtor();
}
