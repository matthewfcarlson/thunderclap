class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class AcquireTargetCondition {};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
extern int a, b;
extern "C" int __cdecl FUN(void*, int, int*, int*, int);
int ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN(p, 0, &a, &b, 0) != 0;
}