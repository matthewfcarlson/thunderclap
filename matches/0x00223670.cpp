extern "C" char DAT_004272b8[];
class Puppet;
class Aux_223670 {
  public:
    void Init();
};
class Puppet {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual Puppet* f5();
    void InitA();
    void InitC(Puppet*);
    char pad[0x60];
    int x;
    int y;
};
extern void* __cdecl allocThunk(unsigned int);
Puppet* Puppet::f5() {
    Puppet* p = (Puppet*)allocThunk(0x2f0);
    if (p) {
        p->InitA();
        *((int*)p) = ((int)DAT_004272b8);
        ((Aux_223670*)((char*)p + 0x10))->Init();
        p->x = 0;
        p->y = 0;
        p->InitC(this);
        return p;
    } else {
        return 0;
    }
}
