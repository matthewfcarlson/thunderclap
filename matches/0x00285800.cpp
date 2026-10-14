extern "C" void _ReadWriteBarrier();
extern void* vSFC[];
extern void* vFC[];
class Ref_285800 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Base_285800 {
    void* vf;
    void Dtor() throw();
};
struct Target_285800 : Base_285800 {
    char pad[0x38];
    Ref_285800* p3c;
    void Dtor2() throw();
};
void Target_285800::Dtor2() throw() {
    vf = vSFC;
    _ReadWriteBarrier();
    if (p3c) {
        p3c->Release();
        p3c = 0;
    }
    vf = vFC;
    _ReadWriteBarrier();
    Base_285800::Dtor();
}
