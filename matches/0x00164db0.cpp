extern "C" char DAT_00415950[];
class Entity {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
};
class Factory_164db0 : public Entity {
    char pad[12];
};
extern void* __cdecl FUN_0008d690(unsigned int);
class Init_164db0 {
  public:
    void InitIt(int);
};
class ConditionFactoryTemplate : public Factory_164db0 {
  public:
    void* vfunc_5();
};
void* ConditionFactoryTemplate::vfunc_5() {
    Init_164db0* p = (Init_164db0*)FUN_0008d690(0x10);
    if (p) {
        p->InitIt(0);
        *(void**)p = (void*)((int)DAT_00415950);
        *((char*)p + 0xc) = 1;
        return p;
    }
    return 0;
}