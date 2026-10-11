extern "C" char DAT_00416938[];
extern "C" void* __cdecl operator_new(unsigned int);
class Obj {
  public:
    Obj(int);
    unsigned int vf;
    int a;
    int b;
    int c;
    unsigned int d;
};
class ConditionFactoryTemplate {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* F();
};
void* ConditionFactoryTemplate::F() {
    Obj* p = (Obj*)operator_new(0x14);
    if (p) {
        p->Obj::Obj(0);
        p->vf = ((int)DAT_00416938);
        p->c = 0;
        p->d = 0x3fc90fdb;
        return p;
    }
    return 0;
}