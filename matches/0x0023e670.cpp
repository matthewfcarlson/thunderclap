extern "C" void _ReadWriteBarrier();
extern void* vStop[];
class Ref_23e670 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Base_23e670 {
    void* vf;
    void Dtor() throw();
};
struct Target_23e670 : Base_23e670 {
    char pad[0x18];
    Ref_23e670* p1c;
    char pad2[8];
    Ref_23e670* p28;
    void Dtor2() throw();
};
void Target_23e670::Dtor2() throw() {
    vf = vStop;
    _ReadWriteBarrier();
    if (p28) {
        p28->Release();
        p28 = 0;
    }
    p1c->Release();
    Base_23e670::Dtor();
}
