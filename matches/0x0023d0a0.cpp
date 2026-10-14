extern "C" char DAT_00428a7c[];
class ConditionFactoryCaster {
  public:
    virtual void V0();
    virtual void V1();
};
class BaseAllocated {
  public:
    void Init();
};
class Elem_23d0a0 {
  public:
    void Build(int);
};
extern "C" void* __cdecl alloc(unsigned int);
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual void V0();
    virtual ConditionFactoryCasterTemplate* V1(int);
};
void ConditionFactoryCasterTemplate::V0() {}
ConditionFactoryCasterTemplate* ConditionFactoryCasterTemplate::V1(int x) {
    BaseAllocated* p = (BaseAllocated*)alloc(0x10);
    if (p) {
        p->Init();
        *(unsigned int*)p = ((int)DAT_00428a7c);
        ((Elem_23d0a0*)((char*)p + 8))->Build(x);
        return (ConditionFactoryCasterTemplate*)p;
    }
    return 0;
}