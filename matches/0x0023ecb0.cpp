extern "C" void _ReadWriteBarrier();
extern void* vSpawn[];
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
    char pad[0x1c];
    Ref* p20;
    Ref* p24;
    Part part;
    void Dtor2() throw();
};
void Target::Dtor2() throw() {
    vf = vSpawn;
    _ReadWriteBarrier();
    if (p24) {
        p24->Release();
        p24 = 0;
    }
    p20->Release();
    part.Fini();
    Base::Dtor();
}
