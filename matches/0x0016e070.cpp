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
        p->vf = 0x416938;
        p->c = 0;
        p->d = 0x3fc90fdb;
        return p;
    }
    return 0;
}