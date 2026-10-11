extern "C" void _ReadWriteBarrier();
extern void* vStop[];
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
    char pad2[8];
    Ref* p28;
    void Dtor2() throw();
};
void Target::Dtor2() throw() {
    vf = vStop;
    _ReadWriteBarrier();
    if (p28) {
        p28->Release();
        p28 = 0;
    }
    p1c->Release();
    Base::Dtor();
}
