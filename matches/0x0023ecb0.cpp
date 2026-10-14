extern "C" void _ReadWriteBarrier();
extern void* vSpawn[];
class Ref_23ecb0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Part_23ecb0 {
  public:
    void Fini() throw();
};
struct Base_23ecb0 {
    void* vf;
    void Dtor() throw();
};
struct Target_23ecb0 : Base_23ecb0 {
    char pad[0x1c];
    Ref_23ecb0* p20;
    Ref_23ecb0* p24;
    Part_23ecb0 part;
    void Dtor2() throw();
};
void Target_23ecb0::Dtor2() throw() {
    vf = vSpawn;
    _ReadWriteBarrier();
    if (p24) {
        p24->Release();
        p24 = 0;
    }
    p20->Release();
    part.Fini();
    Base_23ecb0::Dtor();
}
