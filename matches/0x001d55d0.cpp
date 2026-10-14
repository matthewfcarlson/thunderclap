extern "C" void _ReadWriteBarrier();
extern void* vProp[];
class Ref_1d55d0 {
  public:
    virtual void F0();
    virtual void Release();
};
extern void FUN_00267090(void*);
class Part_1d55d0 {
  public:
    void Fini() throw();
};
struct Base_1d55d0 {
    void* vf;
    void Dtor() throw();
};
struct Target_1d55d0 : Base_1d55d0 {
    char pad[0x8c];
    Ref_1d55d0* p90;
    char pad2[0x24];
    void* pb8;
    int pbc;
    Part_1d55d0 pc0;
    void Dtor2() throw();
};
void Target_1d55d0::Dtor2() throw() {
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
    Base_1d55d0::Dtor();
}
