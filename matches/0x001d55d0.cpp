extern "C" void _ReadWriteBarrier();
extern void* vProp[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
extern void FUN_00267090(void*);
class Part {
  public:
    void Fini() throw();
};
struct Base {
    void* vf;
    void Dtor() throw();
};
struct Target : Base {
    char pad[0x8c];
    Ref* p90;
    char pad2[0x24];
    void* pb8;
    int pbc;
    Part pc0;
    void Dtor2() throw();
};
void Target::Dtor2() throw() {
    vf = vProp;
    _ReadWriteBarrier();
    if (p90) {
        p90->Release();
        p90 = 0;
    }
    if (pb8) {
        FUN_00267090(pb8);
        pb8 = 0;
    }
    pc0.Fini();
    Base::Dtor();
}
