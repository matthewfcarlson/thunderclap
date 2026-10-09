class Entity {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
};
class Factory : public Entity {
    char pad[12];
};
extern void* __cdecl FUN_0008d690(unsigned int);
class Init {
  public:
    void InitIt(int);
};
class ConditionFactoryTemplate : public Factory {
  public:
    void* vfunc_5();
};
void* ConditionFactoryTemplate::vfunc_5() {
    Init* p = (Init*)FUN_0008d690(0x10);
    if (p) {
        p->InitIt(0);
        *(void**)p = (void*)0x415950;
        *((char*)p + 0xc) = 1;
        return p;
    }
    return 0;
}