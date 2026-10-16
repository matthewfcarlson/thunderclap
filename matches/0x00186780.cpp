class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class GrapplePropStateByNameCondition {};
extern int __cdecl castFn(void*, int, void*, void*, int);
extern void* a;
extern void* b;
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
int ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return castFn(p, 0, &a, &b, 0) != 0;
}