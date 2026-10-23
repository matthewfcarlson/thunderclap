struct CSmartPropWeaponTypeCondition;
extern "C" int __cdecl FUN_00344e74(CSmartPropWeaponTypeCondition*, int, void*, void*, int);
extern void *DAT_00491ca8, *DAT_00494478;
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
    return FUN_00344e74((CSmartPropWeaponTypeCondition*)p, 0, &DAT_00491ca8, &DAT_00494478, 0) != 0;
}
} // namespace fight