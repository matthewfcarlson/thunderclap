extern "C" int FUN_00344e74(void*, int, void*, void*, int);
extern int gA;
extern int gB;
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class CIsInvincibleCondition {};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
int ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &gA, &gB, 0) != 0;
}