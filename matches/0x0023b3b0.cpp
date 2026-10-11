extern "C" void _ReadWriteBarrier();
extern void* vSR[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
struct Elem {
    char b[0x18];
    void Fini() throw();
};
struct Elem8 {
    char b[8];
    void Fini() throw();
};
struct Base {
    void* vf;
    void Dtor() throw();
};
struct Target : Base {
    void Pre() throw();
    int p4;
    Ref* p8;
    char pad[0x10c];
    Elem8 e118;
    Elem8 e120;
    char pad2[8];
    Elem arr[0x200];
    void Dtor2() throw();
};
void Target::Dtor2() throw() {
    vf = vSR;
    _ReadWriteBarrier();
    Pre();
    p8->Release();
    Elem* p = arr + 0x200;
    for (int i = 0x200; i; --i) {
        --p;
        p->Fini();
    }
    e120.Fini();
    e118.Fini();
    Base::Dtor();
}
