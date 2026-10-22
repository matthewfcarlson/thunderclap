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
struct Action_23ecb0 {
    void* vf;
    void Dtor() throw();
};
struct SpawnAction_23ecb0 : Action_23ecb0 {
    char pad[0x1c];
    Ref_23ecb0* p20;
    Ref_23ecb0* p24;
    Part_23ecb0 part;
    void Dtor2() throw();
};
void SpawnAction_23ecb0::Dtor2() throw() {
    vf = vSpawn;
    _ReadWriteBarrier();
    if (p24) {
        p24->Release();
        p24 = 0;
    }
    p20->Release();
    part.Fini();
    Action_23ecb0::Dtor();
}
