class AllocThing {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class InitThing {
  public:
    void Init(int);
};
class ConditionFactoryTemplate : public AllocThing {
  public:
    void* vfunc_5();
};
void* ConditionFactoryTemplate::vfunc_5() {
    InitThing* p = (InitThing*)FUN_0008d690(0x10);
    if (p) {
        p->Init(0);
        *(void**)p = (void*)0x416698;
        *((char*)p + 0xc) = 1;
        return p;
    }
    return (void*)0;
}