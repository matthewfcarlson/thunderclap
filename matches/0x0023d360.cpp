class Sub {
  public:
    void Setup(void*);
};
class Obj {
  public:
    void Init();
    char pad[8];
    Sub sub;
};
extern void* __cdecl alloc(unsigned int);
class FactoryBase {
  public:
    virtual void V0();
    virtual void* V1(void*);
};
class Caster : public FactoryBase {
  public:
    char pad[4];
};
class ConditionFactoryCasterTemplate : public Caster {
  public:
    void* V1(void*);
};
void* ConditionFactoryCasterTemplate::V1(void* a) {
    Obj* p = (Obj*)alloc(16);
    if (p) {
        p->Init();
        *((void**)p) = (void*)0x428afc;
        p->sub.Setup(a);
        return p;
    }
    return 0;
}