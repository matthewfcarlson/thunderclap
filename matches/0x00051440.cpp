struct CSmartPropWeaponTypeCondition;
extern "C" int __cdecl Check(CSmartPropWeaponTypeCondition*, int, void*, void*, int);
extern void *a, *b;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
bool ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return Check((CSmartPropWeaponTypeCondition*)p, 0, &a, &b, 0) != 0;
}
} // namespace fight