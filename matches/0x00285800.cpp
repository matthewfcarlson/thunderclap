extern "C" void _ReadWriteBarrier();
extern void* vSFC[];
extern void* vFC[];
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
    char pad[0x38];
    Ref* p3c;
    void Dtor2() throw();
};
void Target::Dtor2() throw() {
    vf = vSFC;
    _ReadWriteBarrier();
    if (p3c) {
        p3c->Release();
        p3c = 0;
    }
    vf = vFC;
    _ReadWriteBarrier();
    Base::Dtor();
}
